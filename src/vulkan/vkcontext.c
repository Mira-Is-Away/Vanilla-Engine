#include "vulkan/vkcontext.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <GLFW/glfw3.h>

#include "misc/vnl_macros.h"
#include "misc/vnl_status.h"
#include "misc/vnl_types.h"
#include "vnl_ds/vnl_list.h"

typedef struct VkQueueFamilyIndices {
    bool has_graphics_family;
    u32 graphics_family;
} VkQueueFamilyIndices;

typedef struct VkContext {
    VkInstance instance;
    VkApplicationInfo app_info;
    VkInstanceCreateInfo create_info;
    VkPhysicalDevice physical_device;
    VkDevice device;
    VkQueue graphics_queue;
} VkContext;

static VkContext vkctx;

static void vk_context_init_app_info(const VnlConfig* config) {
    VkApplicationInfo app_info = {
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pNext = NULL,
        .pApplicationName = config->title,
        .applicationVersion = VK_MAKE_VERSION(
            config->version.major,
            config->version.minor,
            config->version.patch
        ),
        .pEngineName = "Vanilla",
        .engineVersion = VK_MAKE_VERSION(
            VNL_ENGINE_VERSION_MAJOR,
            VNL_ENGINE_VERSION_MINOR,
            VNL_ENGINE_VERSION_PATCH
        ),
        .apiVersion = VK_API_VERSION_1_0
    };

    printf("Built with Vanilla v%d.%d.%d\n",
        VNL_ENGINE_VERSION_MAJOR,
        VNL_ENGINE_VERSION_MINOR,
        VNL_ENGINE_VERSION_PATCH
    );

    printf("%s build version %d.%d.%d\n",
        config->title,
        config->version.major,
        config->version.minor,
        config->version.patch
    );

    vkctx.app_info = app_info;
}

static void vk_context_init_instance_create_info() {
    VkInstanceCreateInfo create_info = {
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pNext = NULL,
        .flags = 0,
        .pApplicationInfo = &vkctx.app_info,
        .enabledLayerCount = 0,
        .ppEnabledLayerNames = 0
    };

    u32 glfw_extension_count = 0;
    const char** glfw_extensions;
    glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

    create_info.enabledExtensionCount = glfw_extension_count;
    create_info.ppEnabledExtensionNames = glfw_extensions;

    vkctx.create_info = create_info;
}

static VnlStatus vk_context_init(const VnlConfig* config, VnlContext* vnl_ctx) {
    u32 extension_count = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extension_count, NULL);
    printf("%d vulkan extensions supported.\n", extension_count);

    VkInstance instance;

    vk_context_init_app_info(config);
    vk_context_init_instance_create_info();

    VkResult result = vkCreateInstance(&vkctx.create_info, NULL, &instance);
    if (result != VK_SUCCESS) {
        printf("Failed to create vulkan context.\n");
        return FAILURE;
    }

    vkctx.instance = instance;
    vnl_ctx->vkctx = &vkctx;
    return SUCCESS;
}


static VkQueueFamilyIndices vk_find_queue_families(VkPhysicalDevice device) {
    VkQueueFamilyIndices indices = {
        .has_graphics_family = false,
        .graphics_family = 0
    };

    u32 queue_family_count = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queue_family_count, NULL);

    VkQueueFamilyProperties queue_families[queue_family_count];
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queue_family_count, queue_families);

    for (u32 i = 0; i < queue_family_count; i++) {
        if(queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.graphics_family = i;
            indices.has_graphics_family = true;
        }

        if (indices.has_graphics_family) break;
    }

    return indices;
}

static bool vk_is_device_suitable(VkPhysicalDevice device) {
    VkQueueFamilyIndices indices = vk_find_queue_families(device);
    return indices.has_graphics_family;
}

static VnlStatus vk_pick_physical_device() {
    VkPhysicalDevice physical_device = VK_NULL_HANDLE;
    u32 device_count = 0;
    vkEnumeratePhysicalDevices(vkctx.instance, &device_count, NULL);

    if (device_count == 0) {
        printf("Failed to find a GPU with Vulkan support.\n");
        return FAILURE;
    }

    VkPhysicalDevice devices[device_count];
    vkEnumeratePhysicalDevices(vkctx.instance, &device_count, devices);

    for (u32 i = 0; i < device_count; i++) {
        if (vk_is_device_suitable(devices[i])) {
            physical_device = devices[i];
            break;
        }
    }

    if (physical_device == VK_NULL_HANDLE) {
        printf("Failed to find a GPU with Vulkan support.\n");
        return FAILURE;
    }

    vkctx.physical_device = physical_device;

    return SUCCESS;
}

static VnlStatus vk_create_logical_device() {
    VkPhysicalDeviceFeatures device_features = { 0 };
    VkQueueFamilyIndices indices = vk_find_queue_families(vkctx.physical_device);

    f32 queue_priority = 1.0f;
    VkDeviceQueueCreateInfo queue_create_info = {
        .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
        .pNext = NULL,
        .flags = 0,
        .queueFamilyIndex = indices.graphics_family,
        .queueCount = 1,
        .pQueuePriorities = &queue_priority
    };

    VkDeviceCreateInfo create_info = {
        .sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
        .pNext = NULL,
        .flags = 0,
        .queueCreateInfoCount = 1,
        .pQueueCreateInfos = &queue_create_info,
        .enabledLayerCount = 0,
        .ppEnabledLayerNames = NULL,
        .enabledExtensionCount = 0,
        .ppEnabledExtensionNames = NULL,
        .pEnabledFeatures = &device_features
    };

    if (vkCreateDevice(vkctx.physical_device,
                       &create_info,
                       NULL, &vkctx.device) != VK_SUCCESS) {
        printf("Failed to create logical device.\n");
        return FAILURE;
    }

    vkGetDeviceQueue(vkctx.device, indices.graphics_family, 0, &vkctx.graphics_queue);

    return SUCCESS;
}

VnlStatus vulkan_init(const VnlConfig* config, VnlContext* vnl_ctx) {
    if (!vk_context_init(config, vnl_ctx)) return FAILURE;
    if (!vk_pick_physical_device()) return FAILURE;
    if (!vk_create_logical_device()) return FAILURE;

    return SUCCESS;
}

void vulkan_shutdown() {
    vkDestroyDevice(vkctx.device, NULL);
    vkDestroyInstance(vkctx.instance, NULL);
}
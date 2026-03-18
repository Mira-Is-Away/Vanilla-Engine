#include "vulkan/vkcontext.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <GLFW/glfw3.h>

#include "misc/vnl_macros.h"
#include "misc/vnl_types.h"

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

VkContext* vk_context_init(VnlConfig* config) {
    VkInstance instance;

    vk_context_init_app_info(config);
    vk_context_init_instance_create_info();

    VkResult result = vkCreateInstance(&vkctx.create_info, NULL, &instance);
    if (result != VK_SUCCESS) {
        printf("Failed to create vulkan context.\n");
        return NULL;
    }

    vkctx.instance = instance;
    return &vkctx;
}

void vk_context_destroy() {
    vkDestroyInstance(vkctx.instance, NULL);
}

void vk_pick_physical_devce() {
    u32 deviceCount = 0;
    vkEnumeratePhysicalDevices(vkctx.instance, &deviceCount, NULL);
}
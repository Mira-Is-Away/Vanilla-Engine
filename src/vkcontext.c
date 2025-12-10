#include "vkcontext.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <GLFW/glfw3.h>

static void vk_context_init_app_info(VkContext* ctx, const char* app_name) {
    VkApplicationInfo* app_info = malloc(sizeof(VkApplicationInfo));

    app_info->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info->pNext = NULL;
    app_info->pApplicationName = app_name;
    app_info->applicationVersion = VK_MAKE_VERSION(0, 1, 0);
    app_info->pEngineName = "Vanilla";
    app_info->engineVersion = VK_MAKE_VERSION(0, 1, 0);
    app_info->apiVersion = VK_API_VERSION_1_0;

    ctx->app_info = app_info;
}

static void vk_context_init_instance_create_info(VkContext* ctx) {
    VkInstanceCreateInfo* create_info = malloc(sizeof(VkInstanceCreateInfo));

    create_info->sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info->pNext = NULL;
    create_info->flags = 0;
    create_info->pApplicationInfo = ctx->app_info;
    create_info->enabledLayerCount = 0;
    create_info->ppEnabledLayerNames = 0;

    uint32_t glfw_extension_count = 0;
    const char** glfw_extensions;
    glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

    create_info->enabledExtensionCount = glfw_extension_count;
    create_info->ppEnabledExtensionNames = glfw_extensions;

    ctx->create_info = create_info;
}

VkContext* vk_context_init(const char* app_name) {

    VkContext* ctx = malloc(sizeof(VkContext));
    VkInstance* instance = malloc(sizeof(VkInstance));

    vk_context_init_app_info(ctx, app_name);
    vk_context_init_instance_create_info(ctx);

    VkResult result = vkCreateInstance(ctx->create_info, NULL, instance);
    if (result != VK_SUCCESS) {
        printf("Failed to create Vulkan instance.\n");
        exit(1);
    }

    ctx->instance = instance;
    return ctx;
}

void vk_context_destroy(VkContext* ctx) {
    vkDestroyInstance(*ctx->instance, NULL);
}
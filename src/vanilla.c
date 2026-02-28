#include "vanilla.h"

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vulkan/vulkan.h>

#include "vulkan/vkcontext.h"
#include "misc/vnl_ints.h"

static VnlContext vnl_ctx;

VnlStatus vnl_init(VnlConfig* config) {
    if (!glfwInit()) {
        printf("failed to init glfw.\n");
        return FAILURE;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    GLFWwindow* window = glfwCreateWindow(config->window.width,
                                          config->window.height,
                                          config->title, NULL, NULL);
    if (!window) {
        printf("Failed to create window.\n");
        return FAILURE;
    }
    config->window.pointer = window;

    u32 extension_count = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extension_count, NULL);
    printf("%d vulkan extensions supported.\n", extension_count);

    VkContext* vkctx = vk_context_init(config);
    if (vkctx == NULL) {
        printf("Failed to create Vulkan instance.\n");
        return FAILURE;
    }

    vnl_ctx.vkctx = vkctx;
    vnl_ctx.config = config;

    printf("Vanilla has initialised successfully.\n");
    return SUCCESS;
}

void vnl_run() {
    /*
    while(!glfwWindowShouldClose(vnl_ctx.window)) {
        glfwPollEvents();
    }*/

    printf("vnl_run() has been called. This function is currently a dummy; Shutting down...\n");
}

void vnl_shutdown() {
    vk_context_destroy(vnl_ctx.vkctx);
    glfwDestroyWindow(vnl_ctx.config->window.pointer);
    printf("Vanilla has shut down successfully.\n");
}
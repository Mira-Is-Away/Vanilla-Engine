#include "vanilla.h"

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vulkan/vulkan.h>

#include "vulkan/vkcontext.h"
#include "defs/vnl_ints.h"

typedef struct VanillaContext {
    GLFWwindow* window;
    VkContext* vkctx;
} VanillaContext;

static VanillaContext vnl_ctx;

int vnl_init(int width, int height) {
    if (!glfwInit()) {
        printf("failed to init glfw.\n");
        return 0;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    GLFWwindow* window = glfwCreateWindow(width, height, VNL_GAME_NAME, NULL, NULL);
    if (!window) {
        printf("Failed to create window.\n");
        return 0;
    }

    u32 extension_count = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extension_count, NULL);
    printf("%d vulkan extensions supported.\n", extension_count);

    vnl_ctx.window = window;

    VkContext* vkctx = vk_context_init();
    if (vkctx == NULL) {
        printf("Failed to create Vulkan instance.\n");
        return 0;
    }

    vnl_ctx.vkctx = vkctx;

    printf("Vanilla has initialised successfully.\n");
    return 1;
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
    glfwDestroyWindow(vnl_ctx.window);
    printf("Vanilla has shut down successfully.\n");
}
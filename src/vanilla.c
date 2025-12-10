#include "vanilla.h"

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <vulkan/vulkan.h>

#include "vkcontext.h"

typedef struct VanillaContext {
    GLFWwindow* window;
    VkContext* renderer;
} VanillaContext;

static VanillaContext vnl_ctx;

int vanilla_init(const char* window_name) {
    if (!glfwInit()) {
        printf("failed to init glfw.\n");
        return 0;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    GLFWwindow* window = glfwCreateWindow(800, 600, window_name, NULL, NULL);
    if (!window) {
        printf("Failed to create window.\n");
        return 0;
    }

    uint32_t extension_count = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extension_count, NULL);
    printf("%d vulkan extensions supported.\n", extension_count);

    vnl_ctx.window = window;

    vnl_ctx.renderer = vk_context_init(window_name);

    printf("Vanilla has initialised successfully.\n");
    return 1;
}

void vanilla_run() {
    while(!glfwWindowShouldClose(vnl_ctx.window)) {
        glfwPollEvents();
    }
}

void vanilla_shutdown() {
    vk_context_destroy(vnl_ctx.renderer);
    glfwDestroyWindow(vnl_ctx.window);
    printf("Vanilla has shutdown successfully.\n");
}
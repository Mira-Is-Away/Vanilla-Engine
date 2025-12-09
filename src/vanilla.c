#include "vanilla.h"

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <vulkan/vulkan.h>

typedef struct VanillaContext {
    GLFWwindow* window;
} VanillaContext;

static VanillaContext vnl_ctx;

int vanilla_init(const char* window_name) {
    if (!glfwInit()) {
        printf("failed to init glfw.\n");
        return 0;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, window_name, NULL, NULL);
    if (!window) {
        printf("Failed to create window.\n");
        return 0;
    }

    uint32_t extension_count = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extension_count, NULL);
    printf("%d vulkan extensions supported.\n", extension_count);

    vnl_ctx.window = window;

    printf("Vanilla has initialised successfully.\n");
    return 1;
}

void vanilla_run() {
    while(!glfwWindowShouldClose(vnl_ctx.window)) {
        glfwPollEvents();
    }
}

void vanilla_shutdown() {
    glfwDestroyWindow(vnl_ctx.window);
    printf("Vanilla has shutdown successfully.\n");
}
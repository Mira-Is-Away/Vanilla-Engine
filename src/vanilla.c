#include "vanilla.h"

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vulkan/vulkan.h>

#include "vkcontext.h"

typedef struct VanillaContext {
    GLFWwindow* window;
    VkContext* vkctx;
} VanillaContext;

static VanillaContext vnl_ctx;

int vanilla_init(const char* app_name) {
    if (!glfwInit()) {
        printf("failed to init glfw.\n");
        return 0;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    const char* app_name_final = strcmp(app_name, "") ? app_name : "Untitled Vanilla Project";
    GLFWwindow* window = glfwCreateWindow(800, 600, app_name_final, NULL, NULL);
    if (!window) {
        printf("Failed to create window.\n");
        return 0;
    }

    uint32_t extension_count = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extension_count, NULL);
    printf("%d vulkan extensions supported.\n", extension_count);

    vnl_ctx.window = window;

    VkContext* vkctx = vk_context_init(app_name_final);
    if (vkctx == NULL) {
        printf("Failed to create Vulkan instance.\n");
        return 0;
    }

    vnl_ctx.vkctx = vkctx;

    printf("Vanilla has initialised successfully.\n");
    return 1;
}

void vanilla_run() {
    while(!glfwWindowShouldClose(vnl_ctx.window)) {
        glfwPollEvents();
    }
}

void vanilla_shutdown() {
    vk_context_destroy(vnl_ctx.vkctx);
    glfwDestroyWindow(vnl_ctx.window);
    printf("Vanilla has shutdown successfully.\n");
}
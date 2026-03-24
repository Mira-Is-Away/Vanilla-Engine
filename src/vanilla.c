#include "vanilla.h"

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vulkan/vulkan.h>

#include "glfw/window.h"
#include "misc/vnl_types.h"
#include "vulkan/vkcontext.h"

struct VnlEngine {
    const VnlConfig* config;
    GLFWwindow* window;
    VkContext* vkctx;
};

static VnlStatus vnl_init_glfw() {
    if (!glfwInit()) {
        printf("failed to init glfw.\n");
        return VNL_ERROR_GLFW_INIT_FAILED;
    }

    return VNL_SUCCESS;
}

VnlStatus vnl_init(const VnlConfig* config, VnlEngine** out_engine) {
    VnlStatus status;

    if ((status = vnl_init_glfw()) != VNL_SUCCESS) return status;

    VnlEngine* engine = malloc(sizeof(VnlEngine));
    if (!engine) return VNL_ERROR_OUT_OF_MEMORY;
    memset(engine, 0, sizeof(VnlEngine));

    engine->config = config;

    if ((status = vnl_window_create(config, &engine->window)) != VNL_SUCCESS) {
        free(engine);
        return status;
    }

    if ((status = vulkan_init(config, &engine->vkctx)) != VNL_SUCCESS) {
        vnl_window_destroy(engine->window);
        free(engine);
        return status;
    }

    *out_engine = engine;
    printf("Vanilla has initialised successfully.\n");
    return VNL_SUCCESS;
}

void vnl_run(VnlEngine* engine) {
    if (!engine || !engine->window) return;

    /*
    while(!glfwWindowShouldClose(engine->window)) {
        glfwPollEvents();
    }*/

    printf("vnl_run() has been called. This function is currently a dummy; Shutting down...\n");
}

void vnl_shutdown(VnlEngine* engine) {
    if (!engine) return;

    vulkan_shutdown(engine->vkctx);
    vnl_window_destroy(engine->window);
    glfwTerminate();
    free(engine);
    
    printf("Vanilla has shut down successfully.\n");
}
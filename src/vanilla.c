#include "vanilla.h"

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vulkan/vulkan.h>

#include "glfw/window.h"
#include "misc/vnl_types.h"
#include "vulkan/vkcontext.h"

static VnlContext vnl_ctx;

static VnlStatus vnl_init_glfw() {
    if (!glfwInit()) {
        printf("failed to init glfw.\n");
        return FAILURE;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    return SUCCESS;
}

static VnlStatus vnl_init_vulkan(VnlConfig* config) {
    u32 extension_count = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extension_count, NULL);
    printf("%d vulkan extensions supported.\n", extension_count);

    VkContext* vkctx = vk_context_init(config);
    if (vkctx == NULL) {
        printf("Failed to create Vulkan instance.\n");
        return FAILURE;
    }

    vnl_ctx.vkctx = vkctx;

    return SUCCESS;
}

VnlStatus vnl_init(VnlConfig* config) {
    if (!vnl_init_glfw()) return FAILURE;
    if (!vnl_window_create(config)) return FAILURE;
    if (!vnl_init_vulkan(config)) return FAILURE;

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

void vnl_config_set_title(VnlConfig* cfg, const char* title) {
    cfg->title = title;
}

void vnl_config_set_version(VnlConfig* cfg, VnlGameVersion version) {
    cfg->version = version;
}

void vnl_config_set_target_fps(VnlConfig* cfg, f32 target) {
    cfg->target_fps = target;
}

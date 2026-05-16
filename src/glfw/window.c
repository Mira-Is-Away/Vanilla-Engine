#include "glfw/window.h"

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "misc/vnl_types.h"

VnlStatus vnl_window_create(const VnlConfig* config, GLFWwindow** out_window) {
    
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow(config->window.width,
                                          config->window.height,
                                          config->title,
                                          NULL, NULL);
    if (!window) {
        printf("Failed to create window.\n");
        return VNL_ERROR_WINDOW_CREATION_FAILED;
    }

    *out_window = window;

    return VNL_SUCCESS;
}

void vnl_window_destroy(GLFWwindow* window) {
    if (window) {
        glfwDestroyWindow(window);
    }
}
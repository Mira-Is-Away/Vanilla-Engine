#include "glfw/window.h"

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "misc/vnl_types.h"

VnlStatus vnl_window_create(VnlConfig* config) {
    
    GLFWwindow* window = glfwCreateWindow(config->window.width,
                                          config->window.height,
                                          config->title,
                                          NULL, NULL);
    if (!window) {
        printf("Failed to create window.\n");
        return FAILURE;
    }

    config->window.pointer = window;

    return SUCCESS;
}

void vnl_window_destroy(VnlWindow* window) {
    glfwDestroyWindow(window->pointer);
    free(window);
}
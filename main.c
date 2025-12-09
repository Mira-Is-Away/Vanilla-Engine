#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

#define RETRY_MAX 5

int main(){

    if (!glfwInit()) {
        printf("failed to init glfw.\n");
        exit(1);
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Vanilla v0.1", NULL, NULL);
    if (!window) {
        printf("failed to create window.\n");
        exit(1);
    }

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    printf("hello world!\n");
    return 0;
}

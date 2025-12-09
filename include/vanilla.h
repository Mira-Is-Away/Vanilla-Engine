#ifndef VANILLA_VANILLA_H_
#define VANILLA_VANILLA_H_

#define GLFW_INCLUDE_VULKAN

typedef struct VanillaContext VanillaContext;

int vanilla_init(const char* window_name);
void vanilla_run();
void vanilla_shutdown();

#endif
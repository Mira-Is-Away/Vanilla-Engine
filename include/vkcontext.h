#ifndef VANILLA_VKCONTEXT_H_
#define VANILLA_VKCONTEXT_H_

#include <vulkan/vulkan.h>

typedef struct VkContext {
    VkInstance* instance;
    VkApplicationInfo* app_info;
    VkInstanceCreateInfo* create_info;
} VkContext;

VkContext* vk_context_init(const char* app_name);
void vk_context_destroy(VkContext* ctx);

#endif
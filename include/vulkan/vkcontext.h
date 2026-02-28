/**
 * @file vkcontext.h
 * 
 * The structure and functions dedicated to storing
 * Vulkan context information.
 * 
 * @author Henry R
 * @date 2025-12-09
 */

#ifndef VANILLA_VULKAN_VKCONTEXT_H_
#define VANILLA_VULKAN_VKCONTEXT_H_

#include <vulkan/vulkan.h>

typedef struct VnlConfig VnlConfig;

/**
 * @struct VkContext
 * @brief Holds pointers to Vulkan context information.
 */
typedef struct VkContext {
    VkInstance* instance;
    VkApplicationInfo* app_info;
    VkInstanceCreateInfo* create_info;
} VkContext;

/**
 * @brief Initialises a Vulkan context instance.
 * @return Returns a pointer to valid VkContext.
 * @retval NULL If context initialisation fails.
 */
VkContext* vk_context_init(VnlConfig* config);

/**
 * @brief Destroys a given Vulkan context instance.
 * @param ctx A Vulkan context to be destroyed.
 */ 
void vk_context_destroy(VkContext* ctx);

#endif
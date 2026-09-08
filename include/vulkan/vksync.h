#ifndef VNL_VULKAN_VKSYNC
#define VNL_VULKAN_VKSYNC

#include <core/vnl_status.h>
#include <vulkan/vulkan.h>

typedef struct {
    VkSemaphore image_available;
    VkSemaphore render_finished;
    VkFence     in_flight;
} VkSync;

typedef struct {
    VkDevice device;
} VkSyncDesc;

VnlStatus vk_sync_create(const VkSyncDesc *desc, VkSync *out_sync);

#endif
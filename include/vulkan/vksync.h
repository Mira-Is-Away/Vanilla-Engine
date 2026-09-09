#ifndef VNL_VULKAN_VKSYNC
#define VNL_VULKAN_VKSYNC

#include <core/vnl_status.h>
#include <vulkan/vulkan.h>

#define VNL_MAX_FRAMES_IN_FLIGHT 2

typedef struct {
    VkDevice    device;
    VkSemaphore image_available;
    VkSemaphore render_finished;
    VkFence     in_flight;
} VkSync;

typedef struct {
    VkDevice device;
} VkSyncDesc;

VnlStatus vk_sync_create(const VkSyncDesc *desc, VkSync *out_sync);

void vk_sync_destroy(VkSync sync);

void vk_wait_in_flight(const VkSync *sync);

void vk_reset_in_flight(VkSync *sync);

#endif
#include <vulkan/vksync.h>

#include <core/vnl_status.h>
#include <mira/clarity.h>
#include <vulkan/vulkan.h>

VnlStatus vk_sync_create(const VkSyncDesc *desc, VkSync *out_sync) {
    VkSemaphoreCreateInfo semaphore_info = (VkSemaphoreCreateInfo){
        .sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO,
    };

    VkFenceCreateInfo fence_info = (VkFenceCreateInfo){
        .sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
    };

    VkResult status = VK_SUCCESS;

    status = vkCreateSemaphore(desc->device, &semaphore_info, NULL,
                               &out_sync->image_available);
    status = vkCreateSemaphore(desc->device, &semaphore_info, NULL,
                               &out_sync->render_finished);
    status =
        vkCreateFence(desc->device, &fence_info, NULL, &out_sync->in_flight);

    if (status != VK_SUCCESS) {
        CLARITY_LOG_ERROR("Failed to create Vulkan synchronisation objects.");
        return VNL_ERROR_SYNC_OBJECTS_CREATION_FAILED;
    }

    return VNL_SUCCESS;
}
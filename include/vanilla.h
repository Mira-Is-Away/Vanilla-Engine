/**
 * @file vanilla.h
 * 
 * The entry point to interact with the Vanilla engine.
 * 
 * @author Henry R
 * @date 2025-12-09
 */

#ifndef VANILLA_VANILLA_H_
#define VANILLA_VANILLA_H_

typedef struct GLFWwindow GLFWwindow;

#include "misc/vnl_macros.h"
#include "misc/vnl_status.h"
#include "misc/vnl_structs.h"
#include "vulkan/vkcontext.h"

#define GLFW_INCLUDE_VULKAN

typedef struct VnlContext{
    VnlConfig* config;
    VkContext* vkctx;
} VnlContext;

/**
 * @brief Initialises the engine and its components.
 * @param[in] width The width of the window to be created.
 * @param[in] height The height of the window to be created.
 * @retval 1 If initialisation was successfull.
 * @retval 0 If initialisation failed.
 */
VnlStatus vnl_init(VnlConfig* config);

/**
 * @brief Runs the engine's main loop.
 */
void vnl_run();

/**
 * @brief Shuts down the engine, deallocating all used memory.
 */
void vnl_shutdown();

#endif
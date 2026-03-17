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
#include "misc/vnl_types.h"
#include "vulkan/vkcontext.h"

#define GLFW_INCLUDE_VULKAN

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
void vnl_run(void);

/**
 * @brief Shuts down the engine, deallocating all used memory.
 */
void vnl_shutdown(void);

VnlContext* vnl_get_context(void);

VnlContext* vnl_get_config(void);

void vnl_config_set_title(VnlConfig* cfg, const char* title);
void vnl_config_set_version(VnlConfig* cfg, VnlGameVersion version);
void vnl_config_set_target_fps(VnlConfig* cfg, f32 target);

#endif
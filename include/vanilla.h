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

#define GLFW_INCLUDE_VULKAN
#define VNL_DEFAULT_APP_NAME "Untitled Vanilla Project"

typedef struct VanillaContext VanillaContext;

/**
 * @brief Initialises the engine and its components.
 * @param[in] app_name Name of the application to be created. If NULL, assigns default name.
 * @param[in] width The width of the window to be created.
 * @param[in] height The height of the window to be created.
 * @retval 1 If initialisation was successfull.
 * @retval 0 If initialisation failed.
 */
int vanilla_init(const char* app_name, int width, int height);

/**
 * @brief Runs the engine's main loop.
 */
void vanilla_run();

/**
 * @brief Shuts down the engine, deallocating all used memory.
 */
void vanilla_shutdown();

#endif
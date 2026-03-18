/**
 * @file window.h
 * 
 * Defines utility functions to handle windows within the engine.
 * 
 * @date 17-03-26
 * @author Henry R
 */

#ifndef VANILLA_GLFW_WINDOW_H_
#define VANILLA_GLFW_WINDOW_H_

#include <GLFW/glfw3.h>

#include "misc/vnl_status.h"

typedef struct VnlConfig VnlConfig;
typedef struct VnlWindow VnlWindow;

/**
 * @brief Creates a GLFW window, returns a VnlWindow wrapper.
 * @param width The window width.
 * @param height The window height.
 * @param title The title of the window.
 * @return A pointer to the created window.
 * @retval NULL If window creation fails.
 */
VnlStatus vnl_window_create(VnlConfig* config);

/**
 * @brief Destroys a VnlWindow entity.
 * @param window A pointer to the window to be destroyed.
 */
void vnl_window_destroy(VnlWindow* window);

#endif
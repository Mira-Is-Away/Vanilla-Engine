/**
 * @file vnl_macros.h
 * 
 * Useful general-purpose macros defined and used by the engine.
 * 
 * @author Henry R
 * @date 2026-02-21
 */

#ifndef VANILLA_MISC_VANILLA_MACROS_H_
#define VANILLA_MISC_VANILLA_MACROS_H_

#define VNL_ENGINE_VERSION_MAJOR 0
#define VNL_ENGINE_VERSION_MINOR 1
#define VNL_ENGINE_VERSION_PATCH 0

/** @brief Macro with the engine's default configuration data.
 * 
 * Usage:
 * VnlConfig config = VNL_DEFAULT_CONFIG;
 */
#define VNL_DEFAULT_CONFIG { \
    .window = {1280, 720, NULL}, \
    .title = "Untiled Vanilla Project", \
    .version = {0, 0, 0}, \
    .target_fps = 60.0f \
}

#endif
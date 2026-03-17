#ifndef VANILLA_MISC_VNL_TYPES_H_
#define VANILLA_MISC_VNL_TYPES_H_

#include "misc/vnl_ints.h"

typedef struct VkContext VkContext;

typedef struct VnlVec2 {
    int x, y;
} VnlVec2;

typedef struct VnlVec3 {
    int x, y, z;
} VnlVec3;

typedef struct VnlVec4 {
    int x, y, z, w;
} VnlVec4;

typedef struct VnlRGBA {
    int r, g, b, a;
} VnlRGBA;

typedef struct VnlWindow {
    u16 width;
    u16 height;
    GLFWwindow* pointer;
} VnlWindow;

typedef struct VnlGameVersion {
    u16 major;
    u16 minor;
    u16 patch;
} VnlGameVersion;

typedef struct VnlConfig {
    VnlWindow window;
    VnlGameVersion version;
    const char* title;
    f32 target_fps;
} VnlConfig;

typedef struct VnlContext {
    VnlConfig* config;
    VkContext* vkctx;
} VnlContext;

#endif
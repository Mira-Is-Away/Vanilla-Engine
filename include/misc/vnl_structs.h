#ifndef VANILLA_MISC_VNL_STRUCTS_H_
#define VANILLA_MISC_VNL_STRUCTS_H_

#include "misc/vnl_ints.h"

typedef struct {
    int x, y;
} VnlVec2;

typedef struct {
    int x, y, z;
} VnlVec3;

typedef struct {
    int x, y, z, w;
} VnlVec4;

typedef struct {
    int r, g, b, a;
} VnlRGBA;

typedef struct {
    u16 width;
    u16 height;
    GLFWwindow* pointer;
} VnlWindow;

typedef struct {
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

#endif
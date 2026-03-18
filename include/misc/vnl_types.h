#ifndef VANILLA_MISC_VNL_TYPES_H_
#define VANILLA_MISC_VNL_TYPES_H_

#include <stdint.h>

#include <GLFW/glfw3.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

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
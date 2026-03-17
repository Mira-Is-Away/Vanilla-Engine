#include <stdlib.h>
#include <stdio.h>

#include "vanilla.h"

// TODO: Add Vulkan validation layers
// TODO: Add proper logging with filters

int main() {

    VnlConfig config = VNL_DEFAULT_CONFIG;
    config.title = "Test Sandbox";
    config.version.minor = 1;

    if(vnl_init(&config) == FAILURE) {
        printf("Failed to initialise Vanilla. Terminating program...\n");
        exit(EXIT_FAILURE);
    }

    vnl_run();

    vnl_shutdown();

    return 0;
    
}
#include <stdlib.h>
#include <stdio.h>

#include "vanilla.h"

// TODO: Add Vulkan validation layers
// TODO: Add proper logging with filters

int main() {
    /*
    User creates and owns the config.
    There is a VNL_DEFAULT_CONFIG macro that populates a 
    basic but valid config struct. 
    */
    VnlConfig config = VNL_DEFAULT_CONFIG;
    config.title = "Test Sandbox";
    config.version.minor = 1;

    VnlEngine* engine = NULL;

    if(vnl_init(&config, &engine) != VNL_SUCCESS) {
        printf("Failed to initialise Vanilla. Terminating program...\n");
        exit(EXIT_FAILURE);
    }

    vnl_run(engine);

    vnl_shutdown(engine);

    return 0;
    
}
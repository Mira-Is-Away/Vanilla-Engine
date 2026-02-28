#include <stdlib.h>
#include <stdio.h>

#include "vanilla.h"

int main(){

    /*
    Henry - 26-02-22
    Consider creating a Vnl_Window object that holds
    information such as the dimentions and positions,
    and wraps GLFW_Window. Alternatively, keep the
    GLFW implementation completely hidden so that the
    developer never even gets to se it. Should work
    fine too, since Vanilla will only render to a
    single window.
    */

    VnlConfig config = VNL_DEFAULT_CONFIG;
    config.title = "Test Sandbox";
    config.version.minor = 1;

    if(vnl_init(&config) == FAILURE) {
        exit(EXIT_FAILURE);
    }

    vnl_run();

    vnl_shutdown();

    return 0;
}
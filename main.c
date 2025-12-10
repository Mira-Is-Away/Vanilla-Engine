#include <stdlib.h>

#include "vanilla.h"

int main(){

    if(!vanilla_init("My sandbox - Vanilla")) {
        exit(EXIT_FAILURE);
    }

    vanilla_run();

    vanilla_shutdown();

    return 0;
}

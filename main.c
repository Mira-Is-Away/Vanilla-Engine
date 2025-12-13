#include <stdlib.h>

#include "vanilla.h"

int main(){

    if(!vanilla_init(NULL, 800, 600)) {
        exit(EXIT_FAILURE);
    }

    vanilla_run();

    vanilla_shutdown();

    return 0;
}

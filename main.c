#include <stdlib.h>

#include "vanilla.h"

int main(){

    if(!vanilla_init("Vanilla 0.1")) {
        exit(1);
    }

    vanilla_run();

    vanilla_shutdown();

    return 0;
}

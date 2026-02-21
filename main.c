#include <stdlib.h>
#include <stdio.h>

#include "vanilla.h"

int main(){

    if(!vnl_init(NULL, 800, 600)) {
        exit(EXIT_FAILURE);
    }

    vnl_run();

    vnl_shutdown();

    return 0;
}
#include <stdlib.h>
#include <stdio.h>

#include "vanilla.h"
#include "vnl_ds/vnl_list.h"

typedef struct {
    int payload;
    VNL_List_Link link;
} Data;

int main(){

    /*if(!vanilla_init(NULL, 800, 600)) {
        exit(EXIT_FAILURE);
    }*/

    //vanilla_run();

    VNL_List list;
    vnl_list_init(&list);

    Data* d1 = malloc(sizeof(Data)); d1->payload = 43;
    Data* d2 = malloc(sizeof(Data)); d2->payload = 7;
    Data* d3 = malloc(sizeof(Data)); d3->payload = 12;
    Data* d4 = malloc(sizeof(Data)); d4->payload = 40;

    vnl_list_push_back(&list, &d1->link);
    vnl_list_push_back(&list, &d2->link);
    vnl_list_push_back(&list, &d3->link);
    vnl_list_push_back(&list, &d4->link);

    printf("Iterating with vnl_list_for_each_entry:\n");
    Data* entry;
    vnl_list_for_each_entry(entry, &list, link) {
        printf("data: %d\n", entry->payload);
    }

    // Cleanup (Safe iteration)
    Data* next;
    vnl_list_for_each_entry_safe(entry, next, &list, link) {
        vnl_list_remove(&list, &entry->link);
        free(entry);
    }

    //vanilla_shutdown();

    return 0;
}
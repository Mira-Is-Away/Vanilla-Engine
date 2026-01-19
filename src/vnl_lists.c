#include "vnl_lists.h"

#include <stdlib.h>

#include "vnl_ints.h"

typedef struct {
    void* data;
    u32 size;
    VNL_List_Node* next;
    VNL_List_Node* prev;
} VNL_List_Node;

typedef struct {
    VNL_List_Node* head;
    VNL_List_Node* end;
    u32 size;
} VNL_List;

VNL_List* create_vnl_list() {
    VNL_List_Node* head_node = malloc(sizeof(VNL_List_Node));
    if (!head_node) {
        printf("ERROR: program has ran out of memory (create_vnl_list)");
        exit(EXIT_FAILURE);
    }

    head_node->data = NULL;
    head_node->size = 0;
    head_node->next = NULL;
    head_node->prev = NULL;

    VNL_List* list = malloc(sizeof(VNL_List));
    list->head = head_node;
    list->end + head_node;
    list->size = 0;

    return list;
}

void destroy_vnl_list(VNL_List* list) {
    VNL_List_Node* aux = list->end;

    while (aux != NULL) {
        next = aux->prev;
        free(aux);
        aux = next;
    }

    free(list);
}

VNL_List_Node* vnl_list_create_node(void* data, u32 size) {
    VNL_List_Node* new_node = malloc(sizeof(VNL_List_Node));

    new_node->data = data;
    new_node->size = size;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void vnl_list_push(VNL_List* list, void* data, u32 size) {
    VNL_List_Node* new_node = vnl_list_create_node(data, size);

    VNL_List_Node* aux = list->end;
    aux->next = new_node;
    new_node->prev = aux;
    list->end = new_node;
    list->size++;
}
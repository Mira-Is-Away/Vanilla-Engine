#include "vnl_ds/vnl_list.h"

#include <stdlib.h>
#include <stddef.h>

#include "misc/vnl_types.h"

static VnlListNode* vnl_list_create_node(void* data, u32 size) {
    VnlListNode* node = (VnlListNode*) calloc(1, sizeof(VnlListNode));

    if (!node) return NULL; 

    node->data = data;
    node->size = size;

    node->prev = NULL;
    node->next = NULL;

    return node;
}

VnlList* vnl_list_create() {
    VnlList* list = calloc(1, sizeof(VnlList));

    if (!list) return NULL; 

    VnlListNode* head = vnl_list_create_node(NULL, 0);
    if (!head) {
        free(list);
        return NULL;
    }

    list->head = head;
    list->tail = list->head;
    list->size = 0;

    return list;
}

VnlList* vnl_list_pushfront(VnlList* list, void* data, u32 size) {
    if (!list) return NULL;
    VnlListNode* node = vnl_list_create_node(data, size);
    if (!node) return NULL;

    VnlListNode* head = list->head;
    VnlListNode* first_node = head->next;

    node->next = first_node;
    node->prev = head;
    head->next = node;

    if (first_node) {
        first_node->prev = node;
    } else {
        list->tail = node;
    }

    list->size++;

    return list;
}

VnlList* vnl_list_pushback(VnlList* list, void* data, u32 size) {
    if (!list) return NULL;
    VnlListNode* node = vnl_list_create_node(data, size);
    if (!node) return NULL;

    VnlListNode* tail = list->tail;

    node->next = NULL;
    node->prev = tail;
    tail->next = node;

    list->tail = node;
    list->size++;

    return list;
}

void* vnl_list_get_element_from_index(VnlList* list, u32 index) {
    VnlListNode* cursor = list->head->next;
    for (u32 i = 0; i <= index; i++) {
        if (cursor == NULL) return NULL;

        if (i == index) return cursor->data;

        cursor = cursor->next;
    }

    return NULL;
}
#include "vnl_ds/vnl_list.h"

void vnl_list_init(VNL_List* list) {
    if (!list) return;
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

void vnl_list_push_back(VNL_List* list, VNL_List_Link* link) {
    link->next = NULL;
    link->prev = list->tail;

    if (list->tail) {
        list->tail->next = link;
    } else {
        list->head = link;
    }

    list->tail = link;
    list->count++;
}

void vnl_list_push_front(VNL_List* list, VNL_List_Link* link) {
    link->prev = NULL;
    link->next = list->head;

    if (list->head) {
        list->head->prev = link;
    } else {
        list->tail = link;
    }

    list->head = link;
    list->count++;
}

VNL_List_Link* vnl_list_remove(VNL_List* list, VNL_List_Link* link) {
    if (link->prev) {
        link->prev->next = link->next;
    } else {
        list->head = link->next;
    }

    if (link->next) {
        link->next->prev = link->prev;
    } else {
        list->tail = link->prev;
    }

    link->next = NULL;
    link->prev = NULL;
    list->count--;

    return link;
}

VNL_List_Link* vnl_list_pop_back(VNL_List* list) {
    if (!list->tail) return NULL;
    return vnl_list_remove(list, list->tail);
}

VNL_List_Link* vnl_list_pop_front(VNL_List* list) {
    if (!list->head) return NULL;
    return vnl_list_remove(list, list->head);
}

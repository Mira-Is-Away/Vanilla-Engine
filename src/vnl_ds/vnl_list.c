#include "vnl_ds/vnl_list.h"

void vnl_list_init(VnlList* list) {
    if (!list) return;
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

void vnl_list_push_back(VnlList* list, VnlListLink* link) {
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

void vnl_list_push_front(VnlList* list, VnlListLink* link) {
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

VnlListLink* vnl_list_remove(VnlList* list, VnlListLink* link) {
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

VnlListLink* vnl_list_pop_back(VnlList* list) {
    if (!list->tail) return NULL;
    return vnl_list_remove(list, list->tail);
}

VnlListLink* vnl_list_pop_front(VnlList* list) {
    if (!list->head) return NULL;
    return vnl_list_remove(list, list->head);
}

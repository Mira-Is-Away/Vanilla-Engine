#ifndef VANILLA_INCLUDE_VNL_DS_LIST_H_
#define VANILLA_INCLUDE_VNL_DS_LIST_H_

#include <stddef.h>
#include "vnl_ints.h"

/**
 * @struct VNL_List_Link
 * @brief Intrusive link to be embedded in data structures.
 */
typedef struct VNL_List_Link {
    struct VNL_List_Link* next;
    struct VNL_List_Link* prev;
} VNL_List_Link;

/**
 * @struct VNL_List
 * @brief Head of an intrusive doubly linked list.
 */
typedef struct VNL_List {
    VNL_List_Link* head;
    VNL_List_Link* tail;
    u32 count;
} VNL_List;

/**
 * @brief Retrieves the parent structure from a list link pointer.
 * @param ptr Pointer to the VNL_List_Link.
 * @param type The type of the parent structure.
 * @param member The name of the VNL_List_Link member within the parent structure.
 */
#define vnl_container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

/**
 * @brief Simple iteration over the list links.
 */
#define vnl_list_for_each(pos, list) \
    for (pos = (list)->head; pos != NULL; pos = pos->next)

/**
 * @brief Iteration safe against removal of the current link.
 */
#define vnl_list_for_each_safe(pos, next, list) \
    for (pos = (list)->head, next = (pos ? pos->next : NULL); \
         pos != NULL; \
         pos = next, next = (pos ? pos->next : NULL))

/**
 * @brief Iterates over the list and provides the parent structure pointer directly.
 */
#define vnl_list_for_each_entry(pos, list, member) \
    for (pos = ((list)->head ? vnl_container_of((list)->head, __typeof__(*pos), member) : NULL); \
         pos != NULL; \
         pos = (pos->member.next ? vnl_container_of(pos->member.next, __typeof__(*pos), member) : NULL))

/**
 * @brief Iterates over the list entries safely (allows removal).
 */
#define vnl_list_for_each_entry_safe(pos, next, list, member) \
    for (pos = ((list)->head ? vnl_container_of((list)->head, __typeof__(*pos), member) : NULL), \
         next = ((pos && pos->member.next) ? vnl_container_of(pos->member.next, __typeof__(*pos), member) : NULL); \
         pos != NULL; \
         pos = next, \
         next = ((pos && pos->member.next) ? vnl_container_of(pos->member.next, __typeof__(*pos), member) : NULL))


/**
 * @brief Initializes a list head.
 * @param list Pointer to the list to initialize.
 */
void vnl_list_init(VNL_List* list);

/**
 * @brief Pushes a link to the end of the list.
 * @param list Pointer to the list.
 * @param link Pointer to the link to insert.
 */
void vnl_list_push_back(VNL_List* list, VNL_List_Link* link);

/**
 * @brief Pushes a link to the front of the list.
 * @param list Pointer to the list.
 * @param link Pointer to the link to insert.
 */
void vnl_list_push_front(VNL_List* list, VNL_List_Link* link);

/**
 * @brief Removes a specific link from the list.
 * @param list Pointer to the list.
 * @param link Pointer to the link to remove.
 * @return The removed link pointer.
 */
VNL_List_Link* vnl_list_remove(VNL_List* list, VNL_List_Link* link);

/**
 * @brief Pops a link from the end of the list.
 * @param list Pointer to the list.
 * @return The removed link pointer, or NULL if empty.
 */
VNL_List_Link* vnl_list_pop_back(VNL_List* list);

/**
 * @brief Pops a link from the front of the list.
 * @param list Pointer to the list.
 * @return The removed link pointer, or NULL if empty.
 */
VNL_List_Link* vnl_list_pop_front(VNL_List* list);

#endif

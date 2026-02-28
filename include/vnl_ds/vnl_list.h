/**
 * @file vnl_list.h
 * 
 * Intrusive doubly-linked list and associated functions and macros
 * 
 * @author Henry R
 * @date 2026-02-16
 */

#ifndef VANILLA_VNL_DS_LIST_H_
#define VANILLA_VNL_DS_LIST_H_

#include <stddef.h>
#include "misc/vnl_ints.h"

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
 * @param ptr A valid pointer to the desired object's type.
 * @param list Pointer to the list link.
 */
#define vnl_list_for_each(ptr, list) \
    for (ptr = (list)->head; ptr != NULL; ptr = ptr->next)

/**
 * @brief Iteration safe against removal of the current link.
 * @param ptr A valid pointer to the desired object's type.
 * @param next Must be another valid pointer of the desired object type. Used for internal safety safeguards.
 * param list Pointer to the list link.
 */
#define vnl_list_for_each_safe(ptr, next, list) \
    for (ptr = (list)->head, next = (ptr ? ptr->next : NULL); \
         ptr != NULL; \
         ptr = next, next = (ptr ? ptr->next : NULL))

/**
 * @brief Iterates over the list and provides the parent structure pointer directly.
 * @param ptr A valid pointer to the desired object's type.
 * @param list Pointer to the list link.
 * @param member The desired member of the struct you wish to retrieve.
 */
#define vnl_list_for_each_entry(ptr, list, member) \
    for (ptr = ((list)->head ? vnl_container_of((list)->head, __typeof__(*ptr), member) : NULL); \
         ptr != NULL; \
         ptr = (ptr->member.next ? vnl_container_of(ptr->member.next, __typeof__(*ptr), member) : NULL))

/**
 * @brief Iterates over the list entries safely (allows removal).
 * @param ptr A valid pointer to the desired object's type.
 * @param next A pointer of the same type as entry. The macro will use it to iterate over the list. It doesn't need to be initialised.
 * @param list A pointer to the list link.
 * @param member The desirerd member of the struct you wish to retrieve.
 */

// 26-02-21 - a couple days ago only i and god knew what i meant with this macro definition. now only god knows
#define vnl_list_for_each_entry_safe(ptr, next, list, member) \
    for (ptr = ((list)->head ? vnl_container_of((list)->head, __typeof__(*ptr), member) : NULL), \
         next = ((ptr && ptr->member.next) ? vnl_container_of(ptr->member.next, __typeof__(*ptr), member) : NULL); \
         ptr != NULL; \
         ptr = next, \
         next = ((ptr && ptr->member.next) ? vnl_container_of(ptr->member.next, __typeof__(*ptr), member) : NULL))


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

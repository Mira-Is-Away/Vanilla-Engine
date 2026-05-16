/**
 * @file vnl_list.h
 * 
 * Standard generic doubly-linked list and associated functions
 * 
 * @author Henry R
 * @date 2026-05-15
 */

#ifndef VANILLA_VNL_DS_LIST_H_
#define VANILLA_VNL_DS_LIST_H_

#include "misc/vnl_types.h"

typedef struct VnlListNode {
    /*
    Pointer to the actual data in memory.
    Not great for fast iteration through
    each node, since cache misses will be
    nearly guaranteed.
    */
    void* data;
    u32 size;

    struct VnlListNode* prev;
    struct VnlListNode* next;
} VnlListNode;

typedef struct VnlList {
    VnlListNode* head;
    VnlListNode* tail;
    u32 size;
} VnlList;

/**
 * @brief Create a VnlList object and allocates a head node.
 * @return A pointer to the list object that has been created.
 */
VnlList* vnl_list_create();

/**
 * @brief Insert a node at the start of the list.
 * @param list A pointer to the list object.
 * @param data A pointer to the data to be stored.
 * @param size The size of the data in bytes.
 * @return A pointer to the list object. Mostly useful for chaining.
 */
VnlList* vnl_list_pushfront(VnlList* list, void* data, u32 size);

/**
 * @brief Insert a node at the end of the list.
 * @param list A pointer to the list object.
 * @param data A pointer to the data to be stored.
 * @param size The size of the data in bytes.
 * @return A pointer to the list object. Mostly useful for chaining.
 */
VnlList* vnl_list_pushback(VnlList* list, void* data, u32 size);

/**
 * @brief Retrieves the element of the list in the corresponding index.
 * @param list A pointer to the list object.
 * @param index The index of the element to be retrieved.
 * @return A pointer to the data at that index.
 * @retval NULL If the element is not found.
 */
void* vnl_list_get_element_from_index(VnlList* list, u32 index);

#endif
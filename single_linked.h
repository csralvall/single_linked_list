/**
  * @file single_linked.h
  * @brief Functions prototypes and data structure of single linked list.
  *
  * This file contains the structure used to define a
  * single linked list and all the function prototypes
  * of the operations allowed over the lists.
  *
  * @author csralvall
  *
  * @bug No known bugs.
  */

#include <stdlib.h>

/**
 * @brief Structure of each node that begins to the list.
 *
 * Struct that holds an integer and a pointer to the next
 * node of the list.
 */
typedef struct node{
    int data;
    struct node* link;
}node_t;

/**
 * @brief Pointer to a node in the list.
 *
 * Defines a pointer to a node. It's used to point to the head
 * of the list.
 */
typedef node_t* list_t;

/**
 * @brief Creates a node with value item and returns.
 *
 * Allocs space for a new node. If alloc succeeds a new node
 * is created, the value of item is stored inside the node,
 * and the pointer to the next node is set NULL.
 *
 * @param item the integer to be stored
 * @return on succeed, a pointer to the new node, if fails, a NULL pointer
 */
list_t lCreate(int item);

/**
 * @brief Prints the content of a list.
 *
 * Runs over the list from beginning to end and
 * prints its content to stdout.
 *
 * @param head pointer to the beginning of the list
 * @return 0 on succeed, 1 on failure
 * @warning if head is NULL, prints error and returns
 */
int lDisplay(list_t head);

/**
 * @brief Insert an element to the tail of the list.
 *
 * Creates a new node with value equal to item, runs
 * over all the list and inserts the new element at
 * the end of the list.
 *
 * @param head pointer to the beginning of the list
 * @param item value of the new node to insert
 * @return 0 on succeed, 1 on failure
 * @warning if head is NULL, prints error and returns
 */
int lInsertT(list_t head, int item);

/**
 * @brief Inserts an element at the head of the list.
 *
 * Creates a new node with value equal to item and
 * makes it the new head of the list.

 * @param head pointer to the beginning of the list
 * @param item value of the new node to insert
 * @return pointer to the new head of list
 */
list_t lInsertH(list_t head, int item);

/**
 * @brief Inserts an element after a position given.
 * 
 * Runs over a list until reach the postion given
 * and inserts the element.
 * 
 * @param head pointer to the beginning of the list
 * @param item value of the new node to insert
 * @param pos position after which inserts the item
 * @return 0 on succeed, 1 on failure
 * @warning if head is NULL, pos is negative or list is too short, prints error and returns
 */
int lInsertPos(list_t head, int item, int pos);

/**
 * @brief Inserts element befor a position given.
 *
 * Runs over a list until reach the element before
 * the position given, and inserts the item after it.
 *
 * @param head pointer to the beginning of the list
 * @param item value of the new node to insert
 * @param pre position before which inserts the item
 * @return 0 on succeed, 1 on failure
 * @warning if head is NULL, pre less than one or list is too short, prints error and returns
 */
int lInsertPre(list_t head, int item, int pre);

/**
 * @brief Deletes the head of the list.
 *
 * Removes the head of the list.
 *
 * @param head pointer to the beginning of the list
 * @return pointer to the new list
 * @note if head is NULL, prints a warning message
 */
list_t lDeleteH(list_t head);

/**
 *
 * @param head pointer to the beginning of the list
 */
list_t lDeleteT(list_t head);

/**
 *
 * @param head pointer to the beginning of the list
 */
int lDeletePos(list_t head, int pos);

/**
 *
 * @param head pointer to the beginning of the list
 */
int lSize(list_t head);

/**
 *
 * @param head pointer to the beginning of the list
 */
int lSearch(list_t head, int key);

/**
 *
 * @param head pointer to the beginning of the list
 */
list_t lReverse(list_t head);

/**
 *
 */
list_t lMerge(list_t a, list_t b);

/**
 *
 * @param head pointer to the beginning of the list
 */
list_t lCopy(list_t head);

/**
 *
 */
list_t lArrToList(int* arr, int size);

/**
 *
 * @param head pointer to the beginning of the list
 */
void lDestroy(list_t head);


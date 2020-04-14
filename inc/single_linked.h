/**
  * @file single_linked.h
  * @brief Functions prototypes and data structure of single linked list.
  *
  * This file contains the structure used to define a
  * single linked list and all the function prototypes
  * of the operations allowed over the lists.
  *
  * @author csralvall
  * @date April 2020
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
 * @return on succeed, a pointer to the new node, if fails,
 * a NULL pointer
 * @warning if alloc fails, an error message is displayed,
 and the function returns
 */
list_t create(int item);

/**
 * @brief Prints the content of a list.
 *
 * Runs over the list from beginning to end and
 * prints its content to stdout.
 *
 * @param head pointer to the beginning of the list
 * @return 0 on succeed, 1 on failure
 * @note if head is NULL, prints warning and returns
 */
int display(list_t head);

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
 * @note if head is NULL, prints warning and returns
 */
int insertT(list_t head, int item);

/**
 * @brief Inserts an element at the head of the list.
 *
 * Creates a new node with value equal to item and
 * makes it the new head of the list.

 * @param head pointer to the beginning of the list
 * @param item value of the new node to insert
 * @return pointer to the new head of list
 */
list_t insertH(list_t head, int item);

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
 * @warning if head is NULL, pos is negative or list is too short,
 * prints error and returns
 */
int insertPos(list_t head, int item, int pos);

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
 * @warning if head is NULL, pre is less than one or list is too short,
 * prints error and returns
 */
int insertPre(list_t head, int item, int pre);

/**
 * @brief Deletes the head of the list.
 *
 * Removes the head of the list.
 *
 * @param head pointer to the beginning of the list
 * @return pointer to the new list
 * @note if head is NULL, prints a warning message and returns
 */
list_t deleteH(list_t head);

/**
 * @brief Deletes the tail of the list.
 *
 * Runs over all the list until reachs the last element
 * and removes it.
 *
 * @param head pointer to the beginning of the list
 * @return pointer to the list without the last item
 * @note if head is NULL, prints warning message and returns
 */
list_t deleteT(list_t head);

/**
 * @brief Deletes the element after a given position.
 *
 * Runs over the list until reachs the position given
 * and deletes the following element, wrapping up the
 * rest of the list.
 *
 * @param head pointer to the beginning of the list
 * @param pos position after which removes the element
 * @return 0 on succeed, 1 on failure
 * @warning if head is null, pos is negative, equal to zero
 * or greater than list size the function prints error and returns
 */
int deletePos(list_t head, int pos);

/**
 * @brief Computes the size of the list.
 *
 * Runs over all the list counting the elements.
 *
 * @param head pointer to the beginning of the list
 * @return the number of elements in the list
 * @note a null pointer means an empty list
 */
int size(list_t head);

/**
 * @brief Searchs an item in the list.
 *
 * Runs over the list making comparisons until it finds the
 * element that matchs the key and returns its position.
 *
 * @param head pointer to the beginning of the list
 * @param key element to search for
 * @return if found, the position of the element, -1 on the other case
 * @note if head is NULL, prints warning message and returns
 */
int search(list_t head, int key);

/**
 * @brief Reverse the order of the list.
 *
 * Runs over all the list, turning up the order of the nodes.
 *
 * @param head pointer to the beginning of the list
 * @returns a pointer to the tail of the old list
 */
list_t reverse(list_t head);

/**
 * @brief Takes two list, join them and turns into only one.
 *
 * Goes to the end of the first list and joins it with the
 * head of the second list.
 *
 * @params a head of the first list
 * @params b head of the second list
 * @return a pointer to the beginning of the new list on succeed
 * or NULL on failure
 * @warning you can't merge the same list, in case of that
 prints error and returns
 */
list_t merge(list_t a, list_t b);

/**
 * @brief Copies all the list on another new list
 *
 * Runs over all the list copying on each iteration
 * the nodes of the original list onto another list.
 *
 * @param head pointer to the beginning of the list
 * @return a pointer to the new list
 */
list_t copy(list_t head);

/**
 * @brief Transforms an array into a single linked list
 * 
 * Copies all the content of the cells of an array into
 * nodes and joins all of them on a single linked list.
 *
 * @param arr pointer to the beginning of the array
 * @param size size of the array
 * @return a pointer to the new list on succeed or NULL on failure
 */
list_t arr2list(int* arr, int size);

/**
 * @brief Destroys all the list.
 *
 * Frees all the nodes in the list.

 * @param head pointer to the beginning of the list
 * @return Void
 */
void destroy(list_t head);


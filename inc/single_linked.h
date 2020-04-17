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

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>

/**
 * @brief Defines the list type.
 *
 * Redefines the name used to refer to lists. 
 */
typedef struct list_t List;

/**
 * @brief Creates a list.
 *
 * Allocs space for the new list.
 * If alloc succeeds a new list is created.
 *
 * @param Void
 * @return on success, a pointer to the new list, if fails,
 * a NULL pointer.
 * @warning if alloc fails, an error message is displayed,
 and the function returns.
 */
List * init(void);

/**
 * @brief Prints the content of a list.
 *
 * Runs over the list from beginning to end and
 * prints its content to stdout.
 *
 * @param list pointer to the list.
 * @return 0 on success, 1 on failure.
 * @note if list is empty, prints error and returns.
 */
int display(List *list);

/**
 * @brief Insert an element to the tail of the list.
 *
 * Creates a new node with value equal to item, runs
 * over all the list and inserts the new element at
 * the end of the list.
 *
 * @param list pointer to the list.
 * @param item value of the new node to insert.
 * @return 0 on success, 1 on failure.
 * @note if list is empty, prints error and returns.
 */
int insertT(List *list, int item);

/**
 * @brief Inserts an element at the head of the list.
 *
 * Creates a new node with value equal to item and
 * makes it the new head of the list.

 * @param list pointer to the list.
 * @param item value of the new node to insert.
 * @return 0 on success, 1 on failure.
 * @note if list is empty, prints error and returns.
 */
int insertH(List *list, int item);

/**
 * @brief Inserts an element after a position given.
 * 
 * Runs over a list until reach the postion given
 * and inserts the element.
 * 
 * @param list pointer to the list.
 * @param item value of the new node to insert.
 * @param pos position after which inserts the item.
 * @return 0 on success, 1 on failure.
 * @warning if list is empty, pos is negative or list size is less
 * than pos, prints error and returns.
 */
int insertPos(List *list, int item, int pos);

/**
 * @brief Inserts element before a position given.
 *
 * Runs over a list until reach the element before
 * the position given, and inserts the item after it.
 *
 * @param list pointer to the list.
 * @param item value of the new node to insert.
 * @param pre position before which inserts the item.
 * @return 0 on success, 1 on failure.
 * @warning if list is empty, pre is negative or list size is less
 * or equal to pre, prints error and returns.
 */
int insertPre(List *list, int item, int pre);

/**
 * @brief Deletes the head of the list.
 *
 * Removes the head of the list.
 *
 * @param list pointer to the list.
 * @return the list without his first element.
 * @note if list is empty, prints a warning message and returns.
 */
int deleteH(List *list);

/**
 * @brief Deletes the tail of the list.
 *
 * Runs over all the list until reachs the last element
 * and removes it.
 *
 * @param list pointer to the list.
 * @return the list without the last item.
 * @note if list is empty, prints warning message and returns.
 */
int deleteT(List *list);

/**
 * @brief Deletes the element after a given position.
 *
 * Runs over the list until reachs the position given
 * and deletes the following element, wrapping up the
 * rest of the list.
 *
 * @param list pointer to the list.
 * @param pos position after which remove the element.
 * @return 0 on success, 1 on failure.
 * @warning if list is empty, pos is negative, equal to zero
 * or greater than list size the function prints error and returns.
 */
int deletePos(List *list, int pos);

/**
 * @brief Retrieves the size of the list.
 *
 * Returns the number of items inside the list.
 *
 * @param list pointer to the list.
 * @return the number of elements inside the list.
 */
int size(List *list);

/**
 * @brief Checks if the list is empty.
 *
 * Allows the user to check if the list is empty.
 *
 * @param list pointer to the list.
 * @return 1 if the list is empty, 0 if not.
 */
int empty(List *list);

/**
 * @brief Searchs an item in the list.
 *
 * Runs over the list making comparisons until it finds the
 * element that matchs the key and returns its position.
 *
 * @param list pointer to the list.
 * @param key element to search for.
 * @return if found, the position of the element, -1 on the other case.
 * @note if list is empty, prints error message and returns.
 */
int search(List *list, int key);

/**
 * @brief Reverse the order of the list.
 *
 * Runs over all the list, turning up the order of the nodes.
 *
 * @param list pointer to the list.
 * @return Void
 */
void reverse(List *list);

/**
 * @brief Takes two list, join them and turns into only one.
 *
 * Goes to the end of the first list and joins it with the
 * head of the second list.
 *
 * @params a pointer to the first list.
 * @params b pointer to the second list.
 * @return 0 on success, 1 on failure.
 * @warning in case of null pointer or the same list on both parameters,
 * prints error and returns.
 */
int merge(List *a, List *b);

/**
 * @brief Copies all the list on another new list
 *
 * Runs over all the list copying on each iteration
 * the nodes of the original list onto another list.
 *
 * @param list pointer to the list.
 * @return a pointer to the new list on success or NULL on failure.
 */
List * copy(List *list);

/**
 * @brief Transforms an array into a single linked list
 * 
 * Copies all the content of the cells of an array into
 * nodes and joins all of them on a single linked list.
 *
 * @param arr pointer to the beginning of the array.
 * @param size size of the array.
 * @return a pointer to the new list on success or NULL on failure.
 */
List * arr2list(int* arr, int size);

/**
 * @brief Destroys all the list.
 *
 * Frees all the nodes in the list and 
 * frees the structure.
 *
 * @param list pointer to the list.
 * @return Void
 */
void destroy(List *head);

#endif // LIST_H_


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

#ifdef TYPE

#ifndef TYPED
#define TYPED(THING) THING
#endif

/**
 * @brief Defines the list type.
 *
 * Redefines the name used to refer to lists. 
 */
typedef struct TYPED(List)  TYPED(List);

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
TYPED(List) * TYPED(init) (void);

/**
 * @brief Prints the content of a list.
 *
 * Runs over the list from beginning to end and prints its content
 * to stdout.
 *
 * @param list pointer to the list.
 * @param f pointer to user defined function to display TYPE struct.
 * @return 0 on success, 1 on failure.
 * @warning if f fails, prints error and returns.
 * @warning if list unitialized or empty, prints error and returns.
 * @note f should return 0 on success and 1 on failure. This function
 * should preferably display the structure in a "box with arrow" format
 * like this: []->.
 */
int TYPED(display) (TYPED(List) *list, int (*f) (TYPE));

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
 * @warning if list is unitialized, prints error and returns.
 */
int TYPED(append) (TYPED(List) *list, TYPE item);

/**
 * @brief Inserts an element at the head of the list.
 *
 * Creates a new node with value equal to item and
 * makes it the new head of the list.

 * @param list pointer to the list.
 * @param item value of the new node to insert.
 * @return 0 on success, 1 on failure.
 * @warning if list is unitialized, prints error and returns.
 */
int TYPED(prepend) (TYPED(List) *list, TYPE item);

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
 * @warning if list is unitialized, pos is negative or list size is less
 * than pos, prints error and returns.
 */
int TYPED(insert_pos) (TYPED(List) *list, TYPE item, int pos);

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
 * @warning if list is unitialized or empty, pre is negative
 * or list size is less or equal to pre, prints error and returns.
 */
int TYPED(insert_pre) (TYPED(List) *list, TYPE item, int pre);

/**
 * @brief Deletes the head of the list.
 *
 * Removes the head of the list.
 *
 * @param list pointer to the list.
 * @param f pointer to user defined function to destroy TYPE struct.
 * If TYPE refers to primitive C-types, just use NULL instead of f.
 * @return the list without his first element.
 * @warning if list is unitialized prints error and returns.
 * @warning if f fails, prints error and returns.
 * @note if list is empty, prints a warning message and returns.
 * @note f should return 0 on success and 1 on failure.
 */
int TYPED(remove_head) (TYPED(List) *list, int (*f) (TYPE));

/**
 * @brief Deletes the tail of the list.
 *
 * Runs over all the list until reachs the last element
 * and removes it.
 *
 * @param list pointer to the list.
 * @param f pointer to user defined function to destroy TYPE struct.
 * If TYPE refers to primitive C-types, just use NULL instead of f.
 * @return the list without the last item.
 * @warning if f fails, prints error and returns.
 * @warning if the list is unitialized prints error and returns.
 * @note if list is empty, prints warning message and returns.
 * @note f should return 0 on success and 1 on failure.
 */
int TYPED(remove_tail) (TYPED(List) *list, int (*f) (TYPE));

/**
 * @brief Deletes the element after a given position.
 *
 * Runs over the list until reachs the position given
 * and deletes the following element, wrapping up the
 * rest of the list.
 *
 * @param list pointer to the list.
 * @param pos position after which remove the element.
 * @param f pointer to user defined function to destroy TYPE struct.
 * If TYPE refers to primitive C-types, just use NULL instead of f.
 * @return 0 on success, 1 on failure.
 * @warning if f fails, prints error and returns.
 * @warning if list is unitialized or empty, pos is negative,
 * equal to zero or greater than list size the function
 * prints error and returns.
 * @note f should return 0 on success and 1 on failure.
 */
int TYPED(remove_from) (TYPED(List) *list, int pos, int (*f) (TYPE));

/**
 * @brief Retrieves the size of the list.
 *
 * Returns the number of items inside the list.
 *
 * @param list pointer to the list.
 * @return the number of elements inside the list on succes
 * or -1 on failure.
 * @warning if the list is unitialized prints error and returns.
 */
int TYPED(size) (TYPED(List) *list);

/**
 * @brief Checks if the list is empty.
 *
 * Allows the user to check if the list is empty.
 *
 * @param list pointer to the list.
 * @return 1 if the list is empty or unitialized, 0 if not.
 * @warning if the list is unitialized prints error and returns.
 */
int TYPED(empty) (TYPED(List) *list);

/**
 * @brief Searchs an item in the list.
 *
 * Runs over the list making comparisons until it finds the
 * element that matchs the key and returns its position.
 *
 * @param list pointer to the list.
 * @param key element to search for.
 * @return if found, the position of the element, -1 on the other case.
 * @warning if list is unitialized or empty, prints error message
 * and returns.
 */
int TYPED(search) (TYPED(List) *list, TYPE key);

/**
 * @brief Retrieves the element in the position given.
 *
 * Returns the current element in the given position at
 * that moment in the list.
 *
 * @param list pointer to the list.
 * @param pos position of the element queried.
 * @param ret address of the return value.
 * @return 0 on succees, 1 on failure.
 * @warning if the list is unitialized, pos is less than 0 or greater
 * than the size of the list, prints error and returns.
 */
int TYPED(query) (TYPED(List) *list, int pos, TYPE *ret);

/**
 * @brief Reverse the order of the list.
 *
 * Runs over all the list, turning up the order of the nodes.
 *
 * @param list pointer to the list.
 * @return Void
 * @warning if the list is unitialized prints error and returns.
 */
void TYPED(reverse) (TYPED(List) *list);

/**
 * @brief Takes two list, join them and turns into only one.
 *
 * Goes to the end of the first list and joins it with the
 * head of the second list.
 *
 * @params a pointer to the first list.
 * @params b pointer to the second list.
 * @return 0 on success, 1 on failure.
 * @warning in case of unitialized list or the same list
 * on both parameters, prints error and returns.
 */
int TYPED(merge) (TYPED(List) *a, TYPED(List) *b);

/**
 * @brief Copies all the list on another new list
 *
 * Runs over all the list copying on each iteration
 * the nodes of the original list onto another list.
 *
 * @param list pointer to the list.
 * @return a pointer to the new list on success or NULL on failure.
 * @warning if the list is unitialized prints error and returns.
 * @note the user must check if the list is empty.
 */
TYPED(List) * TYPED(copy) (TYPED(List) *list);

/**
 * @brief Transforms an array into a single linked list
 * 
 * Copies all the content of the cells of an array into
 * nodes and joins all of them on a single linked list.
 *
 * @param arr pointer to the beginning of the array.
 * @param size size of the array.
 * @param f pointer to user defined function to copy TYPE struct.
 * If TYPE refers to primitive C-types, just use NULL instead of f.
 * @return a pointer to the new list on success or NULL on failure.
 * @note f should return a pointer to the copied struct on success
 * and NULL on failure.
 * @note if the size provided is less than 0, prints warning and returns.
 */
TYPED(List) * TYPED(arr2list) (TYPE *arr, int size, TYPE (*f) (TYPE));

/**
 * @brief Destroys all the list.
 *
 * Frees all the nodes in the list and 
 * frees the structure.
 *
 * @param list pointer to the list.
 * @param f pointer to user defined function to destroy TYPE struct.
 * If TYPE refers to primitive C-types, just use NULL instead of f.
 * @return Void
 * @warning if list is unitialized prints error and returns.
 * @warning if f fails, prints error and returns.
 * @note f should return 0 on success and 1 on failure.
 */
void TYPED(destroy) (TYPED(List) *list, int (*f) (TYPE));

#endif // TYPE


#include <stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node_t;

typedef node_t* list_t;

list_t lCreate(int item);

int lDisplay(list_t head);

int lInsertT(list_t head, int item);

void lDelete(list_t head, int item);

int lSearch(list_t head, int key);

void lReverse(list_t head);

list_t lMerge(list_t a, list_t b);

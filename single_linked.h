#include <stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node;

typedef node* list_t;

list_t lCreate(void);

int lVisit(list_t head);

int lInsert(list_t head, int item, int pos);

void lDelete(list_t head, int item);

int lSearch(list_t head, int key);

void lReverse(list_t head);

list_t lMerge(list_t a, list_t b);

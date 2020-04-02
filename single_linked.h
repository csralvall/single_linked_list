#include <stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node;

typedef node* list;

list lCreate(void);

void lVisit(list l);

void lInsert(list l, int e);

void lDelete(list l, int e);

int lSearch(list l, int k);

void lReverse(list l);

list lMerge(list a, list b);

#include <stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node_t;

typedef node_t* list_t;

list_t lCreate(int item);

int lDisplay(list_t head);

int lInsertT(list_t head, int item);

list_t lInsertH(list_t head, int item);

int lInsertPos(list_t head, int item, int pos);

int lInsertPre(list_t head, int item, int pre);

list_t lDeleteH(list_t head);

list_t lDeleteT(list_t head);

int lDeletePos(list_t head, int pos);

int lSearch(list_t head, int key);

list_t lReverse(list_t head);

list_t lMerge(list_t a, list_t b);

list_t lCopy(list_t head);

void lDestroy(list_t head);


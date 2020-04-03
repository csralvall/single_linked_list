#include <stdlib.h>
#include <stdio.h>
#include "single_linked.h"

list_t lCreate(list_t head, int elem) {
    list_t new = calloc(1, sizeof(node));
    if(new == NULL) {
        fprintf(stderr,"lCreate::ERROR - allocation fail.\n");
        exit(1);
    }
    new->data = elem;
    new->link = NULL;
    if(head == NULL) {
        head = new;
    } else {
        list_t temp = head;
        while(temp->link != NULL) {
            temp = head->link;
        }
        temp->link = new;
    }

    return head;
}

void lVisit(list_t head);

void lInsert(list_t head, int elem);

void lDelete(list_t head, int elem);

int lSearch(list_t head, int key);

void lReverse(list_t head);

list_t lMerge(list_t a, list_t b);

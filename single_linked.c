#include <stdlib.h>
#include <stdio.h>
#include "single_linked.h"

list_t lCreate(int item) {
    list_t new = calloc(1, sizeof(node_t));
    if(new == NULL) {
        fprintf(stderr,"lCreate::ERROR - allocation fail.\n");
        exit(1);
    }
    new->data = item;
    new->link = NULL;

    return new;
}

int lDisplay(list_t head) {
    if(head == NULL) {
        fprintf(stderr,"lVisit::WARNING - null pointer as argument.\n");
        return 1;
    } else {
        list_t temp = head;
        while(temp->link != NULL) {
            printf("[%i]->", temp->data);
            temp = temp->link;
        }
        printf("[%i]", temp->data);
    }

    return 0;
}

int lInsertT(list_t head, int item) {
    if(head == NULL) {
        fprintf(stderr,"lInsertT::WARNING - null pointer as argument.\n");
        return 1;
    } else {
        list_t temp = head;
        while(temp->link != NULL) {
            temp = temp->link;
        }
        list_t new = lCreate(item);
        temp->link = new;
    }

    return 0;
}

list_t lInsertH(list_t head, int item) {
    list_t temp = head;
    list_t new = lCreate(item);
    new->link = temp;
    head = new;

    return head;
}

void lDelete(list_t head, int item);

int lSearch(list_t head, int key);

void lReverse(list_t head);

list_t lMerge(list_t a, list_t b);

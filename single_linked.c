#include <stdlib.h>
#include <stdio.h>
#include "single_linked.h"

list_t lCreate(void) {
    list_t new = calloc(1, sizeof(node));
    if(new == NULL) {
        fprintf(stderr,"lCreate::ERROR - allocation fail.\n");
        exit(1);
    }
    new->data = 0;
    new->link = NULL;

    return new;
}

int lVisit(list_t head) {
    if(head == NULL) {
        fprintf(stderr,"lVisit::WARNING - null pointer as argument.\n");
        return 1;
    } else {
        list_t temp = head;
        while(temp->link != NULL) {
            printf("[%i]->", temp->data);
        }
        printf("[%i]", temp->data);
    }

    return 0;
}

int lInsert(list_t head, int item, int pos) {
    if(head == NULL) {
        fprintf(stderr,"lInsert::WARNING - null pointer as argument.\n");
        return 1;
    } else {
        list_t temp = head;
        while(temp->link != NULL && pos--) {
            temp = temp->link;
        }
        if(pos == 0) {
            list_t ptemp = temp;
            list_t new = lCreate();
            new->data = item;
            new->link = temp->link;
            ptemp->link = new;
        } else if(temp->link == NULL) {
            fprintf(stderr,"lInsert::WARNING - position out of bound.\n");
            return 1;
        }
    }

    return 0;
}

void lDelete(list_t head, int item);

int lSearch(list_t head, int key);

void lReverse(list_t head);

list_t lMerge(list_t a, list_t b);

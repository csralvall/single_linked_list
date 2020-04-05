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

int lInsertPos(list_t head, int item, int pos) {
    if(head == NULL) {
        fprintf(stderr,"lInsertPos::ERROR - null pointer, list must be initialized.\n");
        return 1;
    } else if(pos < 0) {
        fprintf(stderr,"lInsertPos::ERROR - pos must be greater or equal to zero.\n");
    } else {
        list_t temp = head;
        list_t ptemp = head;
        while(ptemp != NULL && pos) {
            temp = ptemp;
            ptemp = ptemp->link;
            pos--;
        }
        if(pos == 0) {
            list_t new = lCreate(item);
            new->link = temp->link;
            temp->link = new;
        } else {
            fprintf(stderr,"lInsertPos::ERROR - list is to short, unreachable position.\n");
            return 1;
        }
    }

    return 0;
}

int lInsertPre(list_t head, int item, int pre) {
    if(head == NULL) {
        fprintf(stderr,"lInsertPre::ERROR - null pointer, unreachable position.\n");
        return 1;
    } else if(pre < 1) {
        fprintf(stderr,"lInsertPre::ERROR - pre must be greater than zero.\n");
        return 1;
    } else {
        list_t temp = head;
        while(temp->link != NULL && pre != 1) {
            temp = temp->link;
            pre--;
        }
        if(pre == 1) {
            list_t new = lCreate(item);
            new->link = temp->link;
            temp->link = new;
        } else {
            fprintf(stderr,"lInsertPre::ERROR - list is to short, unreachable position.\n");
            return 1;
        }
    }

    return 0;
}

list_t lDeleteH(list_t head) {
    if(head != NULL) {
        list_t temp = head;
        head = head->link;
        free(temp);
    } else {
        fprintf(stderr,"lDeleteH::WARNING - the list is empty.\n");
    }

    return head;
}

list_t lDeleteT(list_t head) {
    if(head == NULL) {
        fprintf(stderr,"lDeleteT::WARNING - the list is empty.\n");
    } else {
        list_t temp = head;
        list_t ptemp = head;
        while(ptemp->link != NULL) {
            temp = ptemp;
            ptemp = ptemp->link;
        }
        if(ptemp != head) {
            free(ptemp);
            temp->link = NULL;
        } else {
            free(ptemp);
            head = NULL;
        }
    }

    return head;
}

int lDeletePos(list_t head, int pos) {
    if(head == NULL) {
        fprintf(stderr,"lDeleteIn::ERROR - null pointer, list must be initialized.\n");
        return 1;
    } else if(pos < 0) {
        fprintf(stderr,"lDeleteIn::ERROR - pos must be greater or equal to zero.\n");
    } else {
        list_t temp = head;
        list_t ptemp = head;
        while(ptemp->link != NULL && pos) {
            temp = ptemp;
            ptemp = ptemp->link;
            pos--;
        }
        if(pos == 0) {
            temp->link = ptemp->link;
            free(ptemp);
            ptemp = NULL;
        } else {
            fprintf(stderr,"lDeleteIn::ERROR - list is to short, unreachable position.\n");
            return 1;
        }
    }

    return 0;
}

int lSearch(list_t head, int key);

void lReverse(list_t head);

list_t lMerge(list_t a, list_t b);

/**
 * @file single_linked.c
 * @brief Implementation of functions to use over a single likend list.
 *
 * Functions to manipulate a single linked list with ease.
 *
 * @author csralvall
 * @date April 2020
 *
 * @bug No known bugs
 */
#include <stdlib.h>
#include <stdio.h>
#include "single_linked.h"

list_t lCreate(int item) {
    list_t new = calloc(1, sizeof(node_t));
    if(new == NULL) {
        fprintf(stderr,"lCreate::ERROR - allocation fail.\n");
        return NULL;
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
        return 1;
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
        fprintf(stderr,"lDeletePos::ERROR - null pointer, list must be initialized.\n");
        return 1;
    } else if(pos < 0) {
        fprintf(stderr,"lDeletePos::ERROR - pos must be greater or equal to zero.\n");
        return 1;
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
            fprintf(stderr,"lDeletePos::ERROR - list is to short, unreachable position.\n");
            return 1;
        }
    }

    return 0;
}

int lSize(list_t head) {
    list_t temp = head;
    int size = 0;
    
    while(temp != NULL) {
        size++;
        temp = temp->link;
    }

    return size;
}

int lSearch(list_t head, int key) {
    int pos = 0;
    list_t temp = head;
    if(head == NULL) {
        fprintf(stderr,"lSearch::WARNING - list is empty");
    } else {
        while(temp != NULL && temp->data != key) {
            temp = temp->link;
            pos++;
        }
    }
    if(temp == NULL) {
        pos = -1;
    }
    return pos;
}
        

list_t lReverse(list_t head) {
    list_t pos, cur = head, pre = NULL;
    while(cur != NULL) {
        pos = cur->link;
        cur->link = pre;
        pre = cur;
        cur = pos;
    }
    head = pre;
    return head;
}

list_t lMerge(list_t a, list_t b) {
    list_t ret = a;
    if(a == NULL) {
        ret = b;
    } else if(b == NULL) {
        ret = a;
    } else if(a != b) {
        list_t temp = a;
        while(temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = b;
        ret = a;
    } else {
        fprintf(stderr,"lMerge::ERROR - you can't merge the same list\n");
    }

    return ret;
}

list_t lCopy(list_t head) {
    list_t newList = lCreate(head->data);
    list_t temp = head->link;
    while(temp != NULL) {
        lInsertT(newList, temp->data);
        temp = temp->link;
    }
    
    return newList;
}

list_t lArrToList(int* arr, int size) {
    list_t newList = lCreate(arr[0]);
    
    for(int i = 1; i < size; i++) {
        lInsertT(newList,arr[i]);
    }

    return newList;
}

void lDestroy(list_t head) {
    while(head != NULL) {
        head = lDeleteH(head);
    }
}


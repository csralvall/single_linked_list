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
#include "../inc/single_linked.h"

list_t create(int item) {
    list_t new = calloc(1, sizeof(node_t));
    if(new == NULL) {
        fprintf(stderr,"create::ERROR - allocation fail.\n");
        return NULL;
    }
    new->data = item;
    new->link = NULL;

    return new;
}

int display(list_t head) {
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
    printf("\n");

    return 0;
}

int insertT(list_t head, int item) {
    if(head == NULL) {
        fprintf(stderr,"insertT::WARNING - null pointer as argument.\n");
        return 1;
    } else {
        list_t temp = head;
        while(temp->link != NULL) {
            temp = temp->link;
        }
        list_t new = create(item);
        temp->link = new;
    }

    return 0;
}

list_t insertH(list_t head, int item) {
    list_t temp = head;
    list_t new = create(item);
    new->link = temp;
    head = new;

    return head;
}

int insertPos(list_t head, int item, int pos) {
    if(head == NULL) {
        fprintf(stderr,"insertPos::ERROR - null pointer, list must be initialized.\n");
        return 1;
    } else if(pos < 0) {
        fprintf(stderr,"insertPos::ERROR - pos must be greater or equal to zero.\n");
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
            list_t new = create(item);
            new->link = temp->link;
            temp->link = new;
        } else {
            fprintf(stderr,"insertPos::ERROR - list is to short, unreachable position.\n");
            return 1;
        }
    }

    return 0;
}

int insertPre(list_t head, int item, int pre) {
    if(head == NULL) {
        fprintf(stderr,"insertPre::ERROR - null pointer, unreachable position.\n");
        return 1;
    } else if(pre < 1) {
        fprintf(stderr,"insertPre::ERROR - pre must be greater than zero.\n");
        return 1;
    } else {
        list_t temp = head;
        while(temp->link != NULL && pre != 1) {
            temp = temp->link;
            pre--;
        }
        if(pre == 1) {
            list_t new = create(item);
            new->link = temp->link;
            temp->link = new;
        } else {
            fprintf(stderr,"insertPre::ERROR - list is to short, unreachable position.\n");
            return 1;
        }
    }

    return 0;
}

list_t deleteH(list_t head) {
    if(head != NULL) {
        list_t temp = head;
        head = head->link;
        free(temp);
    } else {
        fprintf(stderr,"deleteH::WARNING - the list is empty.\n");
    }

    return head;
}

list_t deleteT(list_t head) {
    if(head == NULL) {
        fprintf(stderr,"deleteT::WARNING - the list is empty.\n");
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

int deletePos(list_t head, int pos) {
    if(head == NULL) {
        fprintf(stderr,"deletePos::ERROR - null pointer, list must be initialized.\n");
        return 1;
    } else if(pos <= 0) {
        fprintf(stderr,"deletePos::ERROR - pos must be greater or equal to zero.\n");
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
            fprintf(stderr,"deletePos::ERROR - list is to short, unreachable position.\n");
            return 1;
        }
    }

    return 0;
}

int size(list_t head) {
    list_t temp = head;
    int size = 0;
    
    while(temp != NULL) {
        size++;
        temp = temp->link;
    }

    return size;
}

int search(list_t head, int key) {
    int pos = 0;
    list_t temp = head;
    if(head == NULL) {
        fprintf(stderr,"search::WARNING - list is empty");
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
        

list_t reverse(list_t head) {
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

list_t merge(list_t a, list_t b) {
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
        fprintf(stderr,"merge::ERROR - you can't merge the same list\n");
    }

    return ret;
}

list_t copy(list_t head) {
    list_t newList = create(head->data);
    list_t temp = head->link;
    while(temp != NULL) {
        insertT(newList, temp->data);
        temp = temp->link;
    }
    
    return newList;
}

list_t arr2list(int* arr, int size) {
    list_t newList = create(arr[0]);
    
    for(int i = 1; i < size; i++) {
        insertT(newList,arr[i]);
    }

    return newList;
}

void destroy(list_t head) {
    while(head != NULL) {
        head = deleteH(head);
    }
}


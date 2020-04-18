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

struct node_t {
    int data;
    struct node_t* link;
};

typedef struct node_t* node;

struct list_t {
    int size;
    node head;
};

static node create(int item) {
    node new = calloc(1, sizeof(struct node_t));
    if(new == NULL) {
        fprintf(stderr,"create::ERROR - allocation fail.\n");
        return NULL;
    }
    new->data = item;
    new->link = NULL;

    return new;
}

List * init(void) {
    List* new = calloc(1, sizeof(struct list_t));

    if(new == NULL) {
        fprintf(stderr,"init::ERROR - allocation fail.\n");
        return NULL;
    }

    new->size = 0;
    new->head = NULL;

    return new;
}

int display(List *list) {
    if(list == NULL) {
        fprintf(stderr,"display::ERROR - unitialized list.\n");
        return 1;
    } else if(empty(list)) {
        fprintf(stderr,"display::ERROR - empty list as argument.\n");
        return 1;
    } else {
        node temp = list->head;
        while(temp->link != NULL) {
            printf("[%i]->", temp->data);
            temp = temp->link;
        }
        printf("[%i]", temp->data);
    }
    printf("\n");

    return 0;
}

int insertT(List *list, int item) {
    if(list == NULL) {
        fprintf(stderr,"insertT::ERROR - unitialized list.\n");
        return 1;
    } else {
        node new = create(item);
        if(empty(list)) {
            list->head = new;
        } else {
            node temp = list->head;
            while(temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = new;
        }
        list->size++;
    }

    return 0;
}

int insertH(List *list, int item) {
    if(list == NULL) {
        fprintf(stderr,"insertH::ERROR - unitialized list.\n");
        return 1;
    } else {
        node temp = list->head;
        node new = create(item);
        new->link = temp;
        list->head = new;
        list->size++;
    }

    return 0;
}

int insertPos(List *list, int item, int pos) {
    if(list == NULL) {
        fprintf(stderr,"insertPos::ERROR - unitialized list.\n");
        return 1;
    } else if(pos < 0 || pos >= size(list)) {
        fprintf(stderr,"insertPos::ERROR - pos is out of the bounds of the list.\n");
        return 1;
    } else {
        node temp = list->head;
        node ptemp = list->head;
        while(ptemp != NULL && pos) {
            temp = ptemp;
            ptemp = ptemp->link;
            pos--;
        }
        node new = create(item);
        new->link = temp->link;
        temp->link = new;
        list->size++;
    }

    return 0;
}

int insertPre(List *list, int item, int pre) {
    if(list == NULL) {
        fprintf(stderr,"insertPre::ERROR - unitialized list.\n");
        return 1;
    } else if(empty(list)) {
        fprintf(stderr,"insertPre::ERROR - empty list, unreachable position.\n");
        return 1;
    } else if(pre < 1 || pre > size(list)) {
        fprintf(stderr,"insertPre::ERROR - pre is out of the bounds of the list.\n");
        return 1;
    } else {
        node temp = list->head;
        while(temp->link != NULL && pre != 1) {
            temp = temp->link;
            pre--;
        }
        if(pre == 1) {
            node new = create(item);
            new->link = temp->link;
            temp->link = new;
            list->size++;
        }
    }

    return 0;
}

int deleteH(List *list) {
    if(list == NULL) {
        fprintf(stderr,"deleteH::ERROR - unitialized list.\n");
        return 1;
    } else if(empty(list)) {
        fprintf(stderr,"deleteH::WARNING - the list is empty.\n");
        return 1;
    } else {
        node temp = list->head;
        list->head = temp->link;
        free(temp);
        list->size--;
    }

    return 0;
}

int deleteT(List *list) {
    if(list == NULL) {
        fprintf(stderr,"deleteT::ERROR - unitialized list.\n");
        return 1;
    } else if(empty(list)) {
        fprintf(stderr,"deleteT::WARNING - the list is empty.\n");
        return 1;
    } else {
        node temp = list->head;
        node ptemp = list->head;
        while(ptemp->link != NULL) {
            temp = ptemp;
            ptemp = ptemp->link;
        }
        if(ptemp != list->head) {
            free(ptemp);
            temp->link = NULL;
        } else {
            free(ptemp);
            list->head = NULL;
        }
        list->size--;
    }

    return 0;
}

int deletePos(List *list, int pos) {
    if(list == NULL) {
        fprintf(stderr,"deletePos::ERROR - unitialized list.\n");
        return 1;
    } else if(empty(list)) {
        fprintf(stderr,"deletePos::ERROR - list is empty, nothing to delete.\n");
        return 1;
    } else if(pos <= 0 || pos > (size(list)-1)) {
        fprintf(stderr,"deletePos::ERROR - pos is out of the bounds of the list.\n");
        return 1;
    } else {
        node temp = list->head;
        node ptemp = list->head;
        while(ptemp->link != NULL && pos) {
            temp = ptemp;
            ptemp = ptemp->link;
            pos--;
        }
        temp->link = ptemp->link;
        free(ptemp);
        ptemp = NULL;
        list->size--;
    }

    return 0;
}

int size(List *list) {
    if(list == NULL) {
        fprintf(stderr,"size::ERROR - unitialized list.\n");
        return -1;
    }
    return (list->size);
}

int empty(List *list) {
    int ret = 0;
    if(list == NULL) {
        fprintf(stderr,"empty::ERROR - unitialized list.\n");
        ret = 1;
    } else if(list->head == NULL) {
        ret = 1;
    } 

    return ret;
}

int search(List *list, int key) {
    int pos = -1;
    if(list == NULL) {
        fprintf(stderr,"search::ERROR - unitialized list.\n");
    } else if(empty(list)) {
        fprintf(stderr,"search::ERROR - list is empty.\n");
    } else {
        node temp = list->head;
        while(temp != NULL && temp->data != key) {
            temp = temp->link;
            pos++;
        }
        if(temp == NULL) {
            pos = -1;
        }
    }

    return pos;
}

int query(List *list, int pos, int *ret) {
    if(list == NULL) {
        fprintf(stderr,"query::ERROR - unitialized list.\n");
        return 1;
    } else if(pos < 0 || pos >= size(list)) {
        fprintf(stderr,"query::ERROR - pos is out of the bounds of the list.\n");
        return 1;
    } else {
        node temp = list->head;
        while(temp->link != NULL && pos) {
            temp = temp->link;
            pos--;
        }
        *ret = temp->data;
    }

    return 0;
}

void reverse(List *list) {
    if(list == NULL) {
        fprintf(stderr,"reverse::ERROR - unitialized list.\n");
    } else {
        node pos, cur = list->head, pre = NULL;
        while(cur != NULL) {
            pos = cur->link;
            cur->link = pre;
            pre = cur;
            cur = pos;
        }
        list->head = pre;
    }
}

int merge(List *a, List *b) {
    if(a == NULL || b == NULL) {
        fprintf(stderr,"merge::ERROR - unitialized list.\n");
        return 1;
    } else if(empty(a) || empty(b)) {
        fprintf(stderr,"merge::ERROR - can't merge empty list.\n");
        return 1;
    } else if(a != b) {
        node temp = a->head;
        while(temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = b->head;
        b->head = NULL;
        destroy(b);
    } else {
        fprintf(stderr,"merge::ERROR - can't merge list with itself.\n");
        return 1;
    }

    return 0;
}

List * copy(List *list) {
    List *newList = NULL;
    if(list == NULL) {
        fprintf(stderr,"copy::ERROR - unitialized list.\n");
        return NULL;
    } else {
        newList = init();
        node temp = list->head;
        while(temp != NULL) {
            insertT(newList, temp->data);
            temp = temp->link;
        }
    }
    
    return newList;
}

List * arr2list(int* arr, int size) {
    List *newList = NULL;
    if(size > 0) {
        newList = init();
        
        for(int i = 0; i < size; i++) {
            insertT(newList,arr[i]);
        }
    } else {
        fprintf(stderr,"arr2list::WARNING - size must be greater than 0.\n");
    }

    return newList;
}

void destroy(List *list) {
    if(list == NULL) {
        fprintf(stderr,"destroy::ERROR - unitialized list.\n");
    } else {
        while(!empty(list)) {
            deleteH(list);
            list->size--;
        }
        free(list);
        list = NULL;
    }
}


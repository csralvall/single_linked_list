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
#include "../inc/int_list.h"

struct node_t {
    TYPE data;
    struct node_t* link;
};

typedef struct node_t* node;

struct TYPED(List) {
    int size;
    node head;
};

static node create(TYPE item) {
    node new = calloc(1, sizeof(struct node_t));
    if(new == NULL) {
        fprintf(stderr,"create::ERROR - allocation fail.\n");
        return NULL;
    }
    new->data = item;
    new->link = NULL;

    return new;
}

TYPED(List) * TYPED(init) (void) {
    TYPED(List)* new = calloc(1, sizeof(struct TYPED(List)));

    if(new == NULL) {
        fprintf(stderr,"init::ERROR - allocation fail.\n");
        return NULL;
    }

    new->size = 0;
    new->head = NULL;

    return new;
}

int TYPED(display) (TYPED(List) *list) {
    if(list == NULL) {
        fprintf(stderr,"display::ERROR - unitialized list.\n");
        return 1;
    } else if(TYPED(empty) (list)) {
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

int TYPED(insertT) (TYPED(List) *list, TYPE item) {
    if(list == NULL) {
        fprintf(stderr,"insertT::ERROR - unitialized list.\n");
        return 1;
    } else {
        node new = create(item);
        if(TYPED(empty) (list)) {
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

int TYPED(insertH) (TYPED(List) *list, TYPE item) {
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

int TYPED(insertPos) (TYPED(List) *list, TYPE item, int pos) {
    if(list == NULL) {
        fprintf(stderr,"insertPos::ERROR - unitialized list.\n");
        return 1;
    } else if(pos < 0 || pos >= TYPED(size) (list)) {
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

int TYPED(insertPre) (TYPED(List) *list, TYPE item, int pre) {
    if(list == NULL) {
        fprintf(stderr,"insertPre::ERROR - unitialized list.\n");
        return 1;
    } else if(TYPED(empty) (list)) {
        fprintf(stderr,"insertPre::ERROR - empty list, unreachable position.\n");
        return 1;
    } else if(pre < 1 || pre > TYPED(size) (list)) {
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

int TYPED(deleteH) (TYPED(List) *list) {
    if(list == NULL) {
        fprintf(stderr,"deleteH::ERROR - unitialized list.\n");
        return 1;
    } else if(TYPED(empty) (list)) {
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

int TYPED(deleteT) (TYPED(List) *list) {
    if(list == NULL) {
        fprintf(stderr,"deleteT::ERROR - unitialized list.\n");
        return 1;
    } else if(TYPED(empty) (list)) {
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

int TYPED(deletePos) (TYPED(List) *list, int pos) {
    if(list == NULL) {
        fprintf(stderr,"deletePos::ERROR - unitialized list.\n");
        return 1;
    } else if(TYPED(empty) (list)) {
        fprintf(stderr,"deletePos::ERROR - list is empty, nothing to delete.\n");
        return 1;
    } else if(pos <= 0 || pos > (TYPED(size) (list)-1)) {
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

int TYPED(size) (TYPED(List) *list) {
    if(list == NULL) {
        fprintf(stderr,"size::ERROR - unitialized list.\n");
        return -1;
    }
    return (list->size);
}

int TYPED(empty) (TYPED(List) *list) {
    int ret = 0;
    if(list == NULL) {
        fprintf(stderr,"empty::ERROR - unitialized list.\n");
        ret = 1;
    } else if(list->head == NULL) {
        ret = 1;
    } 

    return ret;
}

int TYPED(search) (TYPED(List) *list, TYPE key) {
    int pos = -1;
    if(list == NULL) {
        fprintf(stderr,"search::ERROR - unitialized list.\n");
    } else if(TYPED(empty) (list)) {
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

int TYPED(query) (TYPED(List) *list, int pos, TYPE *ret) {
    if(list == NULL) {
        fprintf(stderr,"query::ERROR - unitialized list.\n");
        return 1;
    } else if(pos < 0 || pos >= TYPED(size) (list)) {
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

void TYPED(reverse) (TYPED(List) *list) {
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

int TYPED(merge) (TYPED(List) *a, TYPED(List) *b) {
    if(a == NULL || b == NULL) {
        fprintf(stderr,"merge::ERROR - unitialized list.\n");
        return 1;
    } else if(TYPED(empty) (a) || TYPED(empty) (b)) {
        fprintf(stderr,"merge::ERROR - can't merge empty list.\n");
        return 1;
    } else if(a != b) {
        node temp = a->head;
        while(temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = b->head;
        b->head = NULL;
        TYPED(destroy) (b);
    } else {
        fprintf(stderr,"merge::ERROR - can't merge list with itself.\n");
        return 1;
    }

    return 0;
}

TYPED(List) * TYPED(copy) (TYPED(List) *list) {
    TYPED(List) *newList = NULL;
    if(list == NULL) {
        fprintf(stderr,"copy::ERROR - unitialized list.\n");
        return NULL;
    } else {
        newList = TYPED(init) ();
        node temp = list->head;
        while(temp != NULL) {
            TYPED(insertT) (newList, temp->data);
            temp = temp->link;
        }
    }
    
    return newList;
}

TYPED(List) * TYPED(arr2list) (TYPE* arr, TYPE size) {
    TYPED(List) *newList = NULL;
    if(size > 0) {
        newList = TYPED(init) ();
        
        for(int i = 0; i < size; i++) {
            TYPED(insertT) (newList,arr[i]);
        }
    } else {
        fprintf(stderr,"arr2list::WARNING - size must be greater than 0.\n");
    }

    return newList;
}

void TYPED(destroy) (TYPED(List) *list) {
    if(list == NULL) {
        fprintf(stderr,"destroy::ERROR - unitialized list.\n");
    } else {
        while(!TYPED(empty) (list)) {
            TYPED(deleteH) (list);
            list->size--;
        }
        free(list);
        list = NULL;
    }
}


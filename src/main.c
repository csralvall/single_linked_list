#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../inc/single_linked.h"

void test_create(void) {
    list_t list = create(0);
    destroy(list);
}

void test_insert(void) {
    list_t list = create(20);

    for(int i = 19; i >= 0; i-=2) {
        list = insertH(list,i);
    }

    for(int i = 1; i < 19; i+=2) {
        insertPre(list,i+1,i);
    }

    for(int i = 21; i < 30; i+=2) {
        insertT(list,i);
    }

    for(int i = 21; i < 30; i+=2) {
        insertPos(list,i+1,i);
    }

    display(list);

    destroy(list);
}

void test_delete(void) {
    list_t list = create(0);

    for(int i = 1; i < 10; i++) {
        list = insertH(list,i);
    }

    display(list);

    for(int i = 1; i < 3; i++) {
        deletePos(list,i);
    }

    display(list);

    for(int i = 0; i < 3; i++) {
        deleteT(list);
    }

    display(list);

    for(int i = 0; i < 2; i++) {
        list = deleteH(list);
    }

    destroy(list);
}

void test_size(void) {
    list_t list = create(0);

    for(int i = 1; i < 1000; i++) {
        list = insertH(list,i);
    }

    assert(1000 == size(list));

    destroy(list);
}

void test_search(void) {
    list_t list = create(0);

    for(int i = 1; i < 10; i++) {
        insertT(list,i);
    }

    assert(-1 == search(list,11));

    assert(9 == search(list,9));

    destroy(list);
}

void test_reverse(void) {
    list_t list = create(0);

    for(int i = 1; i < 10; i++) {
        list = insertH(list,i);
    }

    list = reverse(list);

    display(list);

    destroy(list);
}

void test_merge(void) {
    list_t list = create(0);
    list_t tsil = NULL;

    for(int i = 1; i < 10; i++) {
        list = insertH(list,i);
    }

    tsil = copy(list);
    tsil = reverse(tsil);

    list = merge(list,tsil);

    destroy(list);
}


void test_copy(void) {
    list_t list = create(0);
    list_t tsil = create(10);
    
    for(int i = 1; i < 10; i++) {
        insertT(list,i);
    }

    for(int i = 11; i < 20; i++) {
        insertT(tsil,i);
    }

    display(list);
    display(tsil);

    destroy(list);
    destroy(tsil);
}

void test_conversion(void) {
    int* arr = calloc(10, sizeof(int));
    list_t list = NULL;
    
    if(arr == NULL) {
        fprintf(stderr,"testConversion::ERROR - calloc failed.\n");
    }

    for(int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    list = arr2list(arr, 10);

    display(list);

    destroy(list);

    free(arr);
}

int main(void) {

    test_create();

    test_insert();

    test_delete();

    test_size();

    test_merge();

    test_reverse();

    test_search();

    test_copy();

    test_conversion();

    return 0;
}

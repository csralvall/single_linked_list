#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../inc/int_list.h"

void test_create(void) {
    List *list = init();
    destroy(list);
}

void test_insert(void) {
    List *list = init();

    for(int i = 20; i >= 0; i-=2) {
        insertH(list,i);
    }

    for(int i = 1; i < 19; i+=2) {
        insertPre(list,i,i);
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
    List *list = init();

    for(int i = 1; i < 10; i++) {
        insertT(list,i);
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
        deleteH(list);
    }

    destroy(list);
}

void test_size(void) {
    List *list = init();

    for(int i = 0; i < 1000; i++) {
        insertT(list,i);
    }

    assert(1000 == size(list));

    destroy(list);
}

void test_search(void) {
    List *list = init();

    for(int i = 0; i < 10; i++) {
        insertT(list,i);
    }

    assert(-1 == search(list,11));

    assert(8 == search(list,9));

    destroy(list);
}

void test_reverse(void) {
    List *list = init();

    for(int i = 0; i < 10; i++) {
        insertH(list,i);
    }

    reverse(list);

    display(list);

    destroy(list);
}

void test_merge(void) {
    List *list = init();
    List *tsil = init();

    for(int i = 0; i < 10; i++) {
        insertT(list,i);
    }

    for(int i = 11; i < 20; i++) {
        insertT(tsil,i);
    }

    merge(list,tsil);

    display(list);

    destroy(list);
}

void test_query(void) {
    List *list = init();
    int ret = -1;

    for(int i = 0; i < 10; i++) {
        insertT(list,i);
    }

    for(int i = 0; i < 10; i++) {
        query(list,i,&ret);
        assert(ret == i);
    }

    destroy(list);
}

void test_copy(void) {
    List *list = init();
    List *tsil = NULL;
    int val1 = -1;
    int val2 = -1;
    
    for(int i = 1; i < 10; i++) {
        insertT(list,i);
    }

    tsil = copy(list);

    while(empty(list)) {
        query(list,0,&val1);
        query(tsil,0,&val2);
        assert(val1 = val2);
        deleteH(list);
        deleteH(tsil);
    }

    destroy(list);
    destroy(tsil);
}

void test_conversion(void) {
    int* arr = calloc(10, sizeof(int));
    List *list = NULL;
    
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

    test_search();

    test_reverse();

    test_merge();

    test_query();

    test_copy();

    test_conversion();

    return 0;
}

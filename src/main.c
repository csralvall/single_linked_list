#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../inc/int_list.h"

void test_create(void) {
    List *list = init();
    destroy(list,NULL);
}

void test_insert(void) {
    List *list = init();

    for(int i = 20; i >= 0; i-=2) {
        prepend(list,i);
    }

    for(int i = 1; i < 19; i+=2) {
        insert_pre(list,i,i);
    }

    for(int i = 21; i < 30; i+=2) {
        append(list,i);
    }

    for(int i = 21; i < 30; i+=2) {
        insert_pos(list,i+1,i);
    }

    display(list,NULL);

    destroy(list,NULL);
}

void test_delete(void) {
    List *list = init();

    for(int i = 1; i < 10; i++) {
        append(list,i);
    }

    display(list,NULL);

    for(int i = 1; i < 3; i++) {
        remove_from(list,i,NULL);
    }

    display(list,NULL);

    for(int i = 0; i < 3; i++) {
        remove_tail(list,NULL);
    }

    display(list,NULL);

    for(int i = 0; i < 2; i++) {
        remove_head(list,NULL);
    }

    destroy(list,NULL);
}

void test_size(void) {
    List *list = init();

    for(int i = 0; i < 1000; i++) {
        append(list,i);
    }

    assert(1000 == size(list));

    destroy(list,NULL);
}

void test_search(void) {
    List *list = init();

    for(int i = 0; i < 10; i++) {
        append(list,i);
    }

    assert(-1 == search(list,11));

    assert(8 == search(list,9));

    destroy(list,NULL);
}

void test_reverse(void) {
    List *list = init();

    for(int i = 0; i < 10; i++) {
        prepend(list,i);
    }

    reverse(list);

    display(list,NULL);

    destroy(list,NULL);
}

void test_merge(void) {
    List *list = init();
    List *tsil = init();

    for(int i = 0; i < 10; i++) {
        append(list,i);
    }

    for(int i = 11; i < 20; i++) {
        append(tsil,i);
    }

    merge(list,tsil);

    display(list,NULL);

    destroy(list,NULL);
}

void test_query(void) {
    List *list = init();
    int ret = -1;

    for(int i = 0; i < 10; i++) {
        append(list,i);
    }

    for(int i = 0; i < 10; i++) {
        query(list,i,&ret);
        assert(ret == i);
    }

    destroy(list,NULL);
}

void test_copy(void) {
    List *list = init();
    List *tsil = NULL;
    int val1 = -1;
    int val2 = -1;
    
    for(int i = 1; i < 10; i++) {
        append(list,i);
    }

    tsil = copy(list);

    while(empty(list)) {
        query(list,0,&val1);
        query(tsil,0,&val2);
        assert(val1 = val2);
        remove_head(list,NULL);
        remove_head(tsil,NULL);
    }

    destroy(list,NULL);
    destroy(tsil,NULL);
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

    list = arr2list(arr, 10, NULL);

    display(list,NULL);

    destroy(list,NULL);

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

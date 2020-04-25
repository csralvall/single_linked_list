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
    mag* arr_mag = calloc(40, sizeof(mag));

    for(int i = 30; i < 40; i++) {
        arr_mag[i] = create_mag(3);
        fill_mag(arr_mag[i]);
        append(list,arr_mag[i]);
    }

    for(int i = 20; i < 30; i++) {
        arr_mag[i] = create_mag(3);
        fill_mag(arr_mag[i]);
        prepend(list,arr_mag[i]);
    }

    for(int i = 10; i < 20; i++) {
        arr_mag[i] = create_mag(3);
        fill_mag(arr_mag[i]);
        insert_pre(list,arr_mag[i],i);
    }

    for(int i = 0; i < 10; i++) {
        arr_mag[i] = create_mag(3);
        fill_mag(arr_mag[i]);
        insert_pos(list,arr_mag[i],i);
    }

    display(list,show_mag);

    destroy(list,delete_mag);

    free(arr_mag);
}

void test_delete(void) {
    List *list = init();
    mag* arr_mag = calloc(10, sizeof(mag));

    for(int i = 0; i < 10; i++) {
        arr_mag[i] = create_mag(3);
        fill_mag(arr_mag[i]);
        append(list,arr_mag[i]);
    }

    display(list,show_mag);

    for(int i = 1; i < 3; i++) {
        remove_from(list,i,delete_mag);
    }

    display(list,show_mag);

    for(int i = 0; i < 3; i++) {
        remove_tail(list,delete_mag);
    }

    display(list,show_mag);

    for(int i = 0; i < 2; i++) {
        remove_head(list,delete_mag);
    }

    destroy(list,delete_mag);

    free(arr_mag);
}

void test_size(void) {
    List *list = init();
    mag* arr_mag = calloc(1000, sizeof(mag));


    for(int i = 0; i < 1000; i++) {
        arr_mag[i] = create_mag(1);
        fill_mag(arr_mag[i]);
        append(list,arr_mag[i]);
    }

    assert(1000 == size(list));

    destroy(list,delete_mag);

    free(arr_mag);
}

/*
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

    list = arr2list(arr, 10);

    display(list,NULL);

    destroy(list,NULL);

    free(arr);
}
*/

int main(void) {

    test_create();

    test_insert();

    test_delete();

    test_size();

/*
    test_search();

    test_reverse();

    test_merge();

    test_query();

    test_copy();

    test_conversion();
*/

    return 0;
}

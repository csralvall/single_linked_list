#include <stdio.h>
#include <stdlib.h>
#include "../inc/single_linked.h"

void testInsertDelete(void) {
    list_t list = lCreate(20);
    lDisplay(list);
    printf("\n");

    for(int i = 19; i >= 0; i-=2) {
        list = lInsertH(list,i);
        lDisplay(list);
        printf("\n");
    }

    for(int i = 1; i < 19; i+=2) {
        lInsertPre(list,i+1,i);
        lDisplay(list);
        printf("\n");
    }

    for(int i = 21; i < 30; i+=2) {
        if(!lInsertT(list,i)) {
            lDisplay(list);
        }
        printf("\n");
    }

    for(int i = 21; i < 30; i+=2) {
        lInsertPos(list,i+1,i);
        lDisplay(list);
        printf("\n");
    }

    for(int i = 29; i > 20; i--) {
        lDeletePos(list,i);
        lDisplay(list);
        printf("\n");
    }

    for(int i = 0; i < 10; i++) {
        list = lDeleteH(list);
        lDisplay(list);
        printf("\n");
    }

    int ret = lSearch(list,15);

    if(ret != -1) {
        printf("It is in pos %i.\n", ret);
    } else {
        printf("Not finded.\n");
    }

    ret = lSearch(list,9);
    if(ret != -1) {
        printf("It is in pos %i.\n", ret);
    } else {
        printf("Not finded.\n");
    }


    for(int i = 10; i < 21; i++) {
        list = lDeleteT(list);
        lDisplay(list);
        printf("\n");
    }


    if(list == NULL) {
        printf("All is OK.\n");
    }
}

void testCopy(void) {
    list_t list = lCreate(0);
    
    for(int i = 1; i < 10; i++) {
        lInsertT(list,i);
        lDisplay(list);
        printf("\n");
    }

    list_t tsil = lCopy(list);
    lDisplay(tsil);
    tsil = lReverse(tsil);
    lDisplay(tsil);
    printf("\n");

    list = lMerge(list,tsil);
    lDisplay(list);
    printf("\n");

    printf("size of merged list: %i.\n", lSize(list));

    lDestroy(list);
}

void testConversion(void) {
    int* arr = calloc(10, sizeof(int));
    list_t list = NULL;
    
    if(arr == NULL) {
        fprintf(stderr,"testConversion::ERROR - calloc failed.\n");
    }

    for(int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    list = lArrToList(arr, 10);
    lDisplay(list);
    printf("\n");

    lDestroy(list);

    free(arr);
}

int main(void) {

    //testInsertDelete();

    //testCopy();

    testConversion();

    return 0;
}

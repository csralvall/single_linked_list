#include <stdio.h>
#include <stdlib.h>
#include "../inc/magazine.h"

struct magazine {
    int length;
    int* pages;
};

typedef struct magazine* mag;

mag create_mag(int length) {
    mag m = calloc(1, sizeof(struct magazine));
    if(m == NULL) {
        fprintf(stderr,"create_mag::ERROR - alloc failed.\n");
    }
    m->length = length;
    m->pages = calloc(length, sizeof(int));
    if(m->pages == NULL) {
        fprintf(stderr,"create_mag::ERROR - alloc for pages failed.\n");
        exit(1);
    }

    return m;
}

void fill_mag(mag m) {
    for(int i = 0; i < (m->length); i++) {
        m->pages[i] = i;
    }
}

int show_mag(mag m) {
    printf("[");
    for(int i = 0; i < (m->length); i++) {
        printf("page :: %i ||", m->pages[i]);
    }
    printf("]");

    return 0;
}

int delete_mag(mag m) {
    free(m->pages);
    free(m);
    m = NULL;

    return 0;
}


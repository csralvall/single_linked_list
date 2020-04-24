#include <stdlib.h>

typedef struct magazine* mag;

mag create_mag(int length);

void fill_mag(mag m);

int show_mag(mag m);

int delete_mag(mag m);

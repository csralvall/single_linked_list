#ifndef INT_LIST_INCLUDED
#define INT_LIST_INCLUDED

#undef TYPE

#define TYPE int

/* The folowing line allows to use
 * own made names (THING). This also allows
 * the use of this structure multiple
 * times inside a project.
 *
 * e.g.: TYPED(THING) d_##THING
 */
#define TYPED(THING) THING

#include "single_linked.h"

#endif

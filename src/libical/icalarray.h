/*======================================================================
 FILE: icalarray.h
 CREATOR: Damon Chaplin 07 March 2001

 (C) COPYRIGHT 2001, Ximian, Inc.

 This program is free software; you can redistribute it and/or modify
 it under the terms of either:

    The LGPL as published by the Free Software Foundation, version
    2.1, available at: http://www.gnu.org/licenses/lgpl-2.1.html

 Or:

    The Mozilla Public License Version 1.0. You may obtain a copy of
    the License at http://www.mozilla.org/MPL/
======================================================================*/

#ifndef ICALARRAY_H
#define ICALARRAY_H

/** @file icalarray.h
 *
 *  @brief An array of arbitrarily-sized elements which grows
 *  dynamically as elements are added.
 */

typedef struct _icalarray icalarray;
struct _icalarray {
    size_t element_size;
    size_t increment_size;
    size_t num_elements;
    size_t space_allocated;
    void **chunks;
};

icalarray *icalarray_new(size_t element_size, size_t increment_size);

icalarray *icalarray_copy(icalarray *array);

void icalarray_free(icalarray *array);

void icalarray_append(icalarray *array, const void *element);

void icalarray_remove_element_at(icalarray *array, size_t position);

void *icalarray_element_at(icalarray *array, size_t position);

void icalarray_sort(icalarray *array, int (*compare)(const void *, const void *));

#endif /* ICALARRAY_H */

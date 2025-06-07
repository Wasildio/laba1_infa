#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include "TypesInfo.h"

typedef struct {
    void* data;
    size_t size;
    TypeInfo_t* typeInfo;
} Vector;

Vector* Vector_create(size_t size, TypeInfo_t* typeInfo);
void Vector_destroy(Vector* vec);
void Vector_sum(Vector* a, Vector* b, Vector* result);
void Vector_dot(Vector* a, Vector* b, void* result);

#endif // VECTOR_H

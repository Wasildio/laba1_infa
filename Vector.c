#include "Vector.h"
#include "TypesInfo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>//необзятательно

Vector* Vector_create(size_t size, TypeInfo_t* typeInfo) {
	Vector* vec = malloc(sizeof(Vector));
	vec->size = size;
	vec->typeInfo = typeInfo;
	vec->data = malloc(size * typeInfo->size);
	return vec;
}

void Vector_destroy(Vector* vec) {
	free(vec->data);
	free(vec);
}

void Vector_sum(Vector* a, Vector* b, Vector* result) {
    size_t elem_size = a->typeInfo->size;

    for (size_t i = 0; i < a->size; ++i) {
        void* elem_a = (char*)a->data + i * elem_size;
        void* elem_b = (char*)b->data + i * elem_size;
        void* elem_res = (char*)result->data + i * elem_size;

        a->typeInfo->sum(elem_a, elem_b, elem_res);
    }
}

void Vector_dot(Vector* a, Vector* b, void* result) {
    void* temp = malloc(a->typeInfo->size);
    memset(result, 0, a->typeInfo->size);

    for (size_t i = 0; i < a->size; ++i) {
        void* elem_a = (char*)a->data + i * a->typeInfo->size;
        void* elem_b = (char*)b->data + i * a->typeInfo->size;

        a->typeInfo->prod(elem_a, elem_b, temp);
        a->typeInfo->sum(result, temp, result);
    }
    free(temp);
}

#ifndef COMPLEX_H
#define COMPLEX_H

#include "TypesInfo.h"

typedef struct {
	double RE;
	double IM;
} Complex;


extern TypeInfo_t ComplexTypeInfo;


void Complex_sum(void* a, void* b, void* result);

void Complex_diff(void* a, void* b, void* result);

void Complex_prod(void* a, void* b, void* result);

void Complex_div(void* a, void* b, void* result);

#endif //COMPLEX_H

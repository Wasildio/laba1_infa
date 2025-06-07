#ifndef DOUBLE_H
#define DOUBLE_H

#include "TypesInfo.h"

typedef struct {
	double value;
} Double;

extern TypeInfo_t DoubleTypeInfo;

void Double_sum(void* a, void* b, void* result);

void Double_dif(void* a, void* b, void* result);

void Double_prod(void* a, void* b, void* result);

void Double_div(void* a, void* b, void* result);

#endif //DOUBLE_H

#ifndef QUATERNION_H
#define QUATERNION_H

#include "TypesInfo.h"

typedef struct {
	double RE;
	double IM1;
	double IM2;
	double IM3;
} Quaternion;

extern TypeInfo_t QuaternionTypeInfo;

void Quaternion_sum(void* a, void* b, void* result);

void Quaternion_diff(void* a, void* b, void* result);

void Quaternion_prod(void* a, void* b, void* result);

void Quaternion_div(void* a, void* b, void* result);

void Quaternion_print(const Quaternion* q);

#endif

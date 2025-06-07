#ifndef INTEGER_H
#define INTEGER_H

#include "TypesInfo.h"
////////////////////////////////////////////////
typedef struct {
	int value;
} Integer;
////////////////////////////////////////////////

// Инициализация Typeinfo дляя Integer
extern TypeInfo_t IntegerTypeInfo;
/////////////////////////////////////////////////
void Integer_sum(void* a, void* b, void* result);

void Integer_diff(void* a, void* b, void* result);

void Integer_prod(void* a, void* b, void* result); 

void Integer_div(void* a, void* b, void* result);

#endif //INTEGER_H











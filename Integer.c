#include "Integer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Integer_sum(void* a, void* b, void* result) {
	Integer* num_a = (Integer*)a;
	Integer* num_b = (Integer*)b;
	Integer* num_result = (Integer*)result;
	num_result->value = num_a->value + num_b->value;
}

void Integer_diff(void* a, void* b, void* result) {
	Integer* num_a = (Integer*)a;
	Integer* num_b = (Integer*)b;
	Integer* num_result = (Integer*)result;
	num_result->value = num_a->value - num_b->value;
}

void Integer_prod(void* a, void* b, void* result) {
	Integer* num_a = (Integer*)a;
	Integer* num_b = (Integer*)b;
	Integer* num_result = (Integer*)result;
	num_result->value = num_a->value * num_b->value;
}

/*void Integer_div(void* a, void* b, void* result) {
	Integer* num_a = (Integer*)a;
	Integer* num_b = (Integer*)b;
	Integer* num_result = (Integer*)result;
	num_result->value = num_a->value/num_b->value;
}*/

TypeInfo_t IntegerTypeInfo = {
	.size = sizeof(Integer),
	.diff = Integer_diff,
	.prod = Integer_prod,
	.sum = Integer_sum,
	.type = INTEGER_TYPE
};

#include "Double.h"


void Double_sum(void* a, void* b, void* result){
	Double* num_a = (Double*)a;
	Double* num_b = (Double*)b;
	Double* num_result = (Double*)result;
	num_result->value = num_a->value + num_b->value;
}

void Double_diff(void* a, void* b, void* result){
	Double* num_a = (Double*)a;
	Double* num_b = (Double*)b;
	Double* num_result = (Double*)result;
	num_result->value = num_a->value - num_b->value;
}

void Double_prod(void* a, void* b, void* result){
	Double* num_a = (Double*)a;
	Double* num_b = (Double*)b;
	Double* num_result = (Double*)result;
	num_result->value = num_a->value * num_b->value;
}

/*void Double_div(void* a, void* b, void* result){
	Double* num_a = (Double*)a;
	Double* num_b = (Double*)b;
	Double* num_result = (Double*)result;
	num_result->value = num_a->value / num_b->value;
}*/

TypeInfo_t DoubleTypeInfo = {
	.size = sizeof(Double),
	.diff = Double_diff,
	.prod = Double_prod,
	.sum = Double_sum,
	.type = DOUBLE_TYPE
};

#include "Quaternion.h"
#include <stdio.h>

void Quaternion_print(const Quaternion* q) {
	printf("%.2f + %.2fi + %2.fj + %2.fk",q->RE, q->IM1, q->IM2, q->IM3);
}

void Quaternion_sum(void* a, void* b, void* result){
	Quaternion* num_a = (Quaternion*)a;
	Quaternion* num_b = (Quaternion*)b;
	Quaternion* num_result = (Quaternion*)result;
	num_result->RE = num_a->RE + num_b->RE;
	num_result->IM1 = num_a->IM1 + num_b->IM1;
	num_result->IM2 = num_a->IM2 + num_b->IM2;
	num_result->IM3 = num_a->IM3 + num_b->IM3;
}

void Quaternion_diff(void* a, void* b, void* result){
	Quaternion* num_a = (Quaternion*)a;
	Quaternion* num_b = (Quaternion*)b;
	Quaternion* num_result = (Quaternion*)result;
	num_result->RE = num_a->RE - num_b->RE;
	num_result->IM1 = num_a->IM1 - num_b->IM1;
	num_result->IM2 = num_a->IM2 - num_b->IM2;
	num_result->IM3 = num_a->IM3 - num_b->IM3;
}
void Quaternion_prod(void* a, void* b, void* result){
	Quaternion* num_a = (Quaternion*)a;
	Quaternion* num_b = (Quaternion*)b;
	Quaternion* num_result = (Quaternion*)result;
	num_result->RE = num_a->RE * num_b->RE - num_a->IM1 * num_b->IM1 - num_a->IM2 * num_b->IM2 - num_a->IM3 * num_b->IM3;
	num_result->IM1 = num_a->RE * num_b->IM1 + num_a->IM1 * num_b->RE + num_a->IM2 * num_b->IM3 - num_a->IM3 * num_b->IM2;
	num_result->IM2 = num_a->RE * num_b->IM2 - num_a->IM1 * num_b->IM3 + num_a->IM2 * num_b->RE + num_a->IM3 * num_b->IM1;
	num_result->IM3 = num_a->RE * num_b->IM3 + num_a->IM1 * num_b->IM2 - num_a->IM2 * num_b->IM1 + num_a->IM3 * num_b->RE;
}

/*void Quaternion_div(void* a, void* b, void* result){
	Quaternion* num_a = (Quaternion*)a;
	Quaternion* num_b = (Quaternion*)b;
	Quaternion* num_result = (Quaternion*)num_result;
	Quaternion inv_b;
	inv_b->RE = 
	inv_b->IM1 =
	inv_b->IM2 = 
	inv_b->IM3 = 
}*/


TypeInfo_t QuaternionTypeInfo = {
	.size = sizeof(Quaternion),
	.sum = Quaternion_sum,
	.diff = Quaternion_diff,
	.prod = Quaternion_prod,
	.type = QUATERNION_TYPE
};

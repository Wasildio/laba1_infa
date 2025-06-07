#include "Complex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h> //зОчем?

void Complex_sum(void* a, void* b, void* result){
	Complex* num_a = (Complex*)a;
	Complex* num_b = (Complex*)b;
	Complex* num_result = (Complex*)result;
	num_result->RE = num_a->RE + num_b->RE;
	num_result->IM = num_a->IM + num_b->IM;
}

void Complex_diff(void* a, void* b, void* result){
	Complex* num_a = (Complex*)a;
	Complex* num_b = (Complex*)b;
	Complex* num_result = (Complex*)result;
	num_result->RE = num_a->RE - num_b->RE;
	num_result->IM = num_a->IM - num_b->IM;
}

void Complex_prod(void* a, void* b, void* result){
	Complex* num_a = (Complex*)a;
	Complex* num_b = (Complex*)b;
	Complex* num_result = (Complex*)result;
	num_result->RE = num_a->RE * num_b->RE - num_a->IM * num_b->IM;
	num_result->IM = num_a->RE * num_b->IM + num_a->IM * num_b->RE;
}

/*void Complex_div(void* a, void* b, void* result){
	Complex* num_a = (Complex*)a;
	Complex* num_b = (Complex*)b;
	Complex* num_result = (Complex*)result;
	double denom = num_b->RE * num_b->RE + num_b->IM * num_b->IM;
	num_result->RE = (num_a->RE * num_b->RE + num_a->IM * num_b->IM) / denom;
	num_result->IM = (num_a->IM * num_b->RE - num_a->RE * num_b->IM)/ denom;
}*/

TypeInfo_t ComplexTypeInfo = {
	.size = sizeof(Complex),
	.diff = Complex_diff,
	.prod = Complex_prod,
	.sum = Complex_sum,
	.type = COMPLEX_TYPE
};


#include <stdio.h>
#include <stdlib.h>

typedef struct TypeInfo {
	size_t size;
	void (*diff) (void*, void*);
	void (*sum) (void*, void*);
	void (*prod) (void*, void*);
} TypeInfo_t; 


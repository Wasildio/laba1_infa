#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include "Integer.h"
#include "Double.h"
#include "Complex.h"
#include "Quaternion.h"

void print_result(void* result, TypeInfo_t* typeinfo) {
    if (typeinfo == &IntegerTypeInfo) {
        printf("%d ", ((Integer*)result)->value);
    } else if (typeinfo == &DoubleTypeInfo) {
        printf("%f ", ((Double*)result)->value);
    } else if (typeinfo == &ComplexTypeInfo) {
        Complex* z = (Complex*)result;
        printf("%f + %fi", z->RE, z->IM);
    } else if (typeinfo == &QuaternionTypeInfo) {
        Quaternion_print((Quaternion*)result);
    }
    printf("\n");
}

void input_vector(Vector* vector, const char* name, TypeInfo_t* typeinfo) {
    printf("Введите элементы вектора %s:\n", name);
    for (int i = 0; i < vector->size; i++) {
        if (typeinfo == &IntegerTypeInfo) {
            int val;
            printf("[%d]: ", i);
            scanf("%d", &val);
            ((Integer*)vector->data)[i].value = val;
        } else if (typeinfo == &DoubleTypeInfo) {
            double val;
            printf("[%d]: ", i);
            scanf("%lf", &val);
            ((Double*)vector->data)[i].value = val;
        } else if (typeinfo == &ComplexTypeInfo) {
            double re, im;
            printf("[%d] (RE IM): ", i);
            scanf("%lf %lf", &re, &im);
            ((Complex*)vector->data)[i].RE = re;
            ((Complex*)vector->data)[i].IM = im;
        } else if (typeinfo == &QuaternionTypeInfo) {
            double re, i1, i2, i3;
            printf("[%d] (RE IM1 IM2 IM3): ", i);
            scanf("%lf %lf %lf %lf", &re, &i1, &i2, &i3);
            ((Quaternion*)vector->data)[i].RE = re;
            ((Quaternion*)vector->data)[i].IM1 = i1;
            ((Quaternion*)vector->data)[i].IM2 = i2;
            ((Quaternion*)vector->data)[i].IM3 = i3;
        }
    }
}

int main() {
    int type_choice, op_choice, size;

    printf("Выберите тип данных:\n");
    printf("1. Целые\n2. Вещественные\n3. Комплексные\n4. Кватернионы\n");
    scanf("%d", &type_choice);

    printf("Выберите операцию:\n");
    printf("1. Векторное сложение\n2. Скалярное произведение\n");
    scanf("%d", &op_choice);

    printf("Введите размер векторов: ");
    scanf("%d", &size);

    TypeInfo_t* typeinfo = NULL;
    switch (type_choice) {
        case 1: typeinfo = &IntegerTypeInfo; break;
        case 2: typeinfo = &DoubleTypeInfo; break;
        case 3: typeinfo = &ComplexTypeInfo; break;
        case 4: typeinfo = &QuaternionTypeInfo; break;
        default: printf("Неверный выбор типа\n"); return 1;
    }

    Vector* a = Vector_create(size, typeinfo);
    Vector* b = Vector_create(size, typeinfo);

    input_vector(a, "A", typeinfo);
    input_vector(b, "B", typeinfo);

    if (op_choice == 1) {
        Vector* result = Vector_create(size, typeinfo);
        Vector_sum(a,b,result);
	printf("Результат: ");
        for (int i = 0; i < size; i++) {
            print_result((char*)result->data + i * typeinfo->size, typeinfo);
        }
        Vector_destroy(result);
    } else if (op_choice == 2) {
        void* dot = malloc(typeinfo->size);
        Vector_dot(a, b, dot);
        printf("Результат скалярного произведения: ");
        print_result(dot, typeinfo);
        free(dot);
    } else {
        printf("Неверная операция\n");
    }

    Vector_destroy(a);
    Vector_destroy(b);

    return 0;
}


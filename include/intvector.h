#ifndef INTVECTOR_H
#define INTVECTOR_H
#include "stdio.h"
#include "vector.h"


void print_int_vector(void *element){
    printf("%.2f ", *(int *)element);
}

void sum_int_vector(void *result, void *a, void *b){
    *(int *)result = *(int *)a + *(int *)b;
}

double multiply_int_vector(void *a, void *b){
    return *(int *)a * *(int *)b;
}

Vector* create_int_vector(){
    return create_vector(sizeof(int), print_int_vector, sum_int_vector, multiply_int_vector);
}

#endif
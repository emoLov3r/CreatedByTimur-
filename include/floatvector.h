#ifndef FLOATVECTOR_H
#define FLOATVECTOR_H
#include "stdio.h"
#include "vector.h"


void print_float_vector(void *element){
    printf("%.2f ", *(float *)element);
}

void sum_float_vector(void *result, void *a, void *b){
    *(float *)result = *(float *)a + *(float *)b;
}

double multiply_float_vector(void *a, void *b){
    return *(float *)a * *(float *)b;
}

Vector* create_float_vector(){
    return createVector(sizeof(float), print_float_vector, sum_float_vector, multiply_float_vector);
}

#endif
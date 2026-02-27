#ifndef VECTOR_H
#define VECTOR_H
#include <stddef.h>


typedef struct{
    size_t lenght;
    size_t capacity;
    size_t element_size;
    void* data;
    
    void (*print_element)(void *);
    void (*sum_elements)(void *, void *, void *);
    double (*multiply_elements) (void *, void *);
}Vector;


Vector* create_vector(size_t element_size, void(*print_elements)(void*),
                        void(*add_elements)(void*, void*, void*), 
                        double(multiply_elements)(void*, void*));
void push_vector(Vector *v, void* value);
void* get_vector(Vector *v, size_t index);
void free_vector(Vector *v);
Vector* sum_vector(Vector *v1, Vector *v2);
double multiply_vector(Vector *v1, Vector *v2);
void print_vector(Vector *v);

#endif

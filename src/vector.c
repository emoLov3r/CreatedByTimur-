#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

Vector* create_vector (size_t element_size, void(*print_elements)(void*),
                        void(*sum_elements)(void*, void*, void*), 
                        double(multiply_elements)(void*, void*)){
    Vector* v = (Vector*)calloc(1, sizeof(Vector));
    if (v == NULL){
        printf("Memory not allocated\n");
        return NULL;
    }           
    
    size_t initial_capacity = 10;
    v -> data = calloc(element_size, initial_capacity);
    if (v -> data == NULL){
        free(v);
        return NULL;
    }

    v -> element_size = element_size;
    v -> lenght = 0;
    v -> capacity = initial_capacity;
    v -> print_element = print_elements;
    v -> sum_elements = sum_elements;
    v -> multiply_elements = multiply_elements;
    return v;
}


void push_vector (Vector *v, void* value){
    if(v == NULL || value == NULL){
        return;
    }
    if (v -> lenght == v -> capacity) {
        size_t new_capacity = v -> capacity * 2;
        size_t new_data = realloc(v -> data, v -> capacity * v -> element_size);
        if (v -> data == NULL){
            return;
        }
        v -> data = new_data; // Меняем указатели
        v -> capacity = new_capacity; // Меняем значение
    }

    char* target = (char* )v -> data + (v -> lenght * v -> element_size); // Итерируемся до места добавления нового элемента
    memcpy(target, value, v -> element_size); // Добавляем элемент

    v -> lenght++; // Так как добавили новый элемент, увеличиваем размер динамиечского массива.
    return;
}

void* get_vector(Vector *v, size_t index){
    if (index < v->lenght){
        return (char *)v -> data + (index * v -> element_size);
    }
    else{
        return -1;
    }
}


void print_vector(Vector *v){
    if (v != NULL || v -> print_element != NULL) {
        for (size_t i = 0; i < v -> lenght; i++){
            void* elem = get_vector(v, i);
            v -> print_element(elem);
            if (i < v -> lenght - 1) {
                printf(", ");
        }
        }
        printf("\n");
    }
    else{
        return;
    }
}

Vector* sum_vector(Vector *v1, Vector *v2){
    if (v1 == NULL || v2 == NULL || v1 -> lenght != v2 -> lenght){
        return NULL;
    }
    Vector* result = create_vector(v1 -> element_size, v1 -> print_element, v1 -> sum_elements, v1 -> multiply_elements);
    if (result ==NULL){
        return NULL;
    }

    for (size_t i = 0; i < v1 ->lenght; i++){
        void* sum = calloc(1 ,v1 -> element_size);
        if (sum ==NULL){
            vector_free(result);
            return NULL;
        }
        void* elements1 = get_vector(v1, i);
        void* elements2 = get_vector(v2, i);
        v1 -> sum_elements(sum, elements1, elements2);
        push_vector(result, sum);
        free(sum);
    }
}

double multiply_vector(Vector *v1, Vector *v2){
    if (v1 == NULL || v2 == NULL || v1 -> lenght != v2 -> lenght){
        return 0.0;
    }
    double result = 0.0;

    for(size_t i = 0; i < v1 -> lenght; i++){
        void* elements1 = get_vector(v1, i);
        void* elements2 = get_vector(v2, i);
        result += v1 -> multiply_elements(elements1, elements2);
    }

    return result;
}

void freeVector(Vector *v){
    free(v -> data);
    v -> data = NULL;
    v -> lenght = 0;
    v -> capacity = 0;
}
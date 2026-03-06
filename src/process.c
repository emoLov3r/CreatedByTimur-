#include <stdio.h>
#include "../include/process.h"

#include "../include/intvector.h"
#include "../include/floatvector.h"


void print_menu() {
    printf("===================================\n");
    printf("        КОНСОЛЬНОЕ МЕНЮ            \n");
    printf("===================================\n");
    printf("           ТИПЫ ДАННЫХ             \n");
    printf("1. Работа с вектором целых чисел.\n");
    printf("2. Работа с вектором дробных чисел.\n");
    printf("0. Выход.\n");
    printf("===================================\n");
    printf("Ваш выбор: ");
}

void int_input(Vector* v) {
    int count, value;
    printf("Количество чисел: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("Введите %d число: ", i + 1);
        scanf("%d", &value);
        push_vector(v, &value);
    }
}

void float_input(Vector* v) {
    int count;
    float value;
    printf("Количество чисел: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("Введите %d число: ", i + 1);
        scanf("%f", &value);
        push_vector(v, &value);
    }
}


void process(int choice) {
    Vector* v1 = NULL;
    Vector* v2 = NULL;

    switch (choice) {
        case 1:
            printf("=== Работа с вектором целых чисел ===\n");
            v1 = create_int_vector();
            v2 = create_int_vector();
            printf("Введите элементы первого вектора.\n");
            int_input(v1);
            printf("Введите элементы второго вектора.\n");
            int_input(v2);
            break;
        case 2:
            printf("=== Работа с вектором дробных чисел ===\n");
            v1 = create_float_vector();
            v2 = create_float_vector();
            printf("Введите элементы первого вектора.\n");
            float_input(v1);
            printf("Введите элементы второго вектора.\n");
            float_input(v2);
            break;
        case 0:
            printf("Выход из программы!\n");
            return;
        default:
            printf("Неправильный выбор! Повторите еще раз!\n");
    }

    
    printf("\nПервый вектор: ");
    print_vector(v1);
    printf("\nВторой вектор: ");
    printf("\n");
    print_vector(v2);

    Vector* sum = sum_vector(v1, v2);
    printf("Сумма векторов: ");
    print_vector(sum);

    double result = multiply_vector(v1, v2);
    printf("Скалярное произведение: %.2f\n", result);

    free_vector(v1);
    free_vector(v2);
    free_vector(sum);
}

#include "stdio.h"
#include "../include/process.h"

int main(void) {
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        process(choice);
    } while (choice != 0);
}
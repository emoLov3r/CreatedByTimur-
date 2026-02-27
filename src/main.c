#include "vector.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    Vector v1, v2, v3;
    createIntVector(&v1, 3);
    createIntVector(&v2, 3);
    createIntVector(&v3, 3);

    pushVector(&v1, 10);
    pushVector(&v1, 20);
    pushVector(&v1, 30); // Вызовет реаллокацию

    
    pushVector(&v2, 10);
    pushVector(&v2, 20);
    pushVector(&v2, 30);

    sumVector(&v1, &v2, &v3);
    multiplyVector(&v1, &v2, &v3);

    printVector(&v1);
    printVector(&v2);
    printVector(&v3);

    freeVector(&v1);
    freeVector(&v2);
    freeVector(&v3);
    return 0;
}
// main.c

#include "matrix.h"
#include <stdio.h>

int main() {
    int input_size = 10;

    double input_data[input_size * input_size];
    for (int i = 0; i < input_size * input_size; i++) {
        input_data[i] = (double)(rand() % 100);
    }

        return 0;
}
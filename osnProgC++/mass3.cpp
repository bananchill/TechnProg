#include <iostream>
#include <stdlib.h>


void print_array(int n, int *values) {
    for (int i = 0; i < n; ++i) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
}

void shift_right(int *a, int length) {
    if (0 == length)
        return;
    int first = a[0];

    for (int i = 1; i < length; ++i)
        a[i - 1] = a[i];

    a[length - 1] = first;
}

void shift_right_on(int *a, int length, int shift_size) {
    if (length > shift_size) {
        shift_size = shift_size % length;
        shift_size = length - shift_size;

        for (int i = 0; i < shift_size; ++i) {
            shift_right(a, length);
        }
        print_array(length, a);
    } else {
        std::cout << "the entered size is smaller than the shift" << std::endl;
    }

}

void dynamicMass(const int length, int shift_size) {
    int *mass = new int[length];

    for (int i = 0; i < length; ++i) {
        mass[i] = rand() % 10;
        std::cout << mass[i] << "  ";
    }

    std::cout << std::endl;
    shift_right_on(mass, length, shift_size);
}

void task1(int shift_size) {
    int mass[] = {1, 2, 2, 3, 4, 5, 6, 7, 8};
    shift_right_on(mass, sizeof(mass) / sizeof(*mass), shift_size);
}

void task2(int shift_size) {
    int mass[] = {1, 2, 2, 3, 7, 8};
    shift_right_on(mass, sizeof(mass) / sizeof(*mass), shift_size);
}

void task3(int shift_size) {
    int mass[] = {1, 2, 67, 2};
    shift_right_on(mass, sizeof(mass) / sizeof(*mass), shift_size);
}

int main() {
    int length;
    std::cout << "Input size mass ";
    std::cin >> length;
    int shift_size;
    std::cout << "enter the shift number ";
    std::cin >> shift_size;
    if (length <= 0 && shift_size <= 0) {
        std::cout << "input correct value";
        exit(1);
    }
    dynamicMass(length, shift_size);
    task1(shift_size);
    task2(shift_size);
    task3(shift_size);

    return 0;
}
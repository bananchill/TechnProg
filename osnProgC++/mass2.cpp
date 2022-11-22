#include <iostream>

void printMass(const int *mass, const int len) {
    for (int i = 0; i < len; i++) {
        std::cout << mass[i] << "   ";
    }

    std::cout << std::endl << std::endl << std::endl;
}

void sort(int *mass, const int len) {
    for (int c1 = 0; c1 < len - 1; ++c1) {
        if (mass[c1] >= 0) {
            for (int c2 = c1 + 1; c2 < len; ++c2)
                if (mass[c1] > mass[c2] && mass[c1] >= 0 && mass[c2] >= 0) {
                    int tmp = mass[c1];
                    mass[c1] = mass[c2];
                    mass[c2] = tmp;
                }
        }
    }

    printMass(mass, len);
}

int main() {
    int arr1[5] = {1, 2, -3, 4, -5};
    int arr2[6] = {-10, 4, 1, -15, 3, -10};
    int size = 0;

    std::cout << std::endl << std::endl << "Randomize" << std::endl << "--------------------" << std::endl
              << "Enter size of array: ";
    std::cin >> size;

    int *array = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 41 - 21;    // -20 ... 20
    }

    sort(arr1, sizeof(arr1) / sizeof(*arr1));
    sort(arr2, sizeof(arr2) / sizeof(*arr2));
    sort(array, _msize(array) / sizeof(int));


    if (array) {
        delete[] array;
    }

    return 0;
}
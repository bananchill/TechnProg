#include <iostream>
#include <cmath>

void searchDuplicate(const int *arr, const int m, const int n) {
    int countDuplicate = 0;
    for (int i = m; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) {
                countDuplicate++;
            }
        }
        if (countDuplicate > 0) {
            std::cout << "there are duplicate values in the array" << std::endl;
            break;
        }
    }
    if (countDuplicate == 0)
        std::cout << "there are not duplicate values in the array" << std::endl;

}

void dynamicMass(const int length, const int m, const int n) {
    int *mass = new int[length];

    for (int i = 0; i < length; ++i) {
        mass[i] = rand() % 10;
        std::cout << mass[i];
    }

    searchDuplicate(mass, m, n);
}

void notDynamicMass() {
    int mass[] = {1, 2, 2, 3, 4, 5, 6, 7, 8};
    searchDuplicate(mass, 0, sizeof(mass) / sizeof(*mass));
}

void notDynamicMass2() {
    int mass[] = {1, 2, 2, 3, 7, 8};
    searchDuplicate(mass, 0, sizeof(mass) / sizeof(*mass));
}

void notDynamicMass3() {
    int mass[] = {1, 2, 67, 2};
    searchDuplicate(mass, 0, sizeof(mass) / sizeof(*mass));
}

int main() {
    int length;
    std::cout << "Input the length massive= ";
    std::cin >> length;
    std::cout << "Input range" << std::endl;
    std::cout << "\n" << "m= ";
    int m, n;
    std::cin >> m;
    std::cout << "n= ";
    std::cin >> n;
    if (m > n || n < 0 || m < 0 || n > length || m > length) {
        std::cout << "input correct value";
        exit(1);
    }
    dynamicMass(length, m, n);
    notDynamicMass();
    notDynamicMass2();
    notDynamicMass3();

    return 0;
}

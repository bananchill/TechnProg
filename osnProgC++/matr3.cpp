#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>
#include <cmath>

int **getMatrixByFile(std::ifstream &fin, size_t &matrixSizeToSet) {
    size_t matrixSize = 0;
    fin >> matrixSize;
    matrixSizeToSet = matrixSize;

    int **result  = new int *[matrixSize];
    for (size_t i = 0; i < matrixSize; i++) {
        result[i] = new int[matrixSize];
    }

    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixSize; j++) {
            int b = 0;
            fin >> b;
            result[i][j] = b;
        }
    }

    return result;
}

int *getSumSideDiagonal(int **mass, const size_t matrixSize ) {
    short i, k;
    int *sum = new int[matrixSize];

    for (k = 0; k < matrixSize - 1; ++k)
        for (i = 0; i < k + 1; ++i)
            sum[k] += mass[i][i];

    for (k = matrixSize / 2; k < matrixSize; ++k)
        for (i = k - **mass / 2 + 1; i < matrixSize; ++i)
            sum[k] += mass[i][i];

    return sum;
}

void printSum(int *sum, const size_t matrixSize) {
    setlocale(LC_ALL, "Russian");
    int i, max = 0;
    std::cout << "\nSums of elements of diagonals parallel to the side:\n";
    for (i = 0; i < matrixSize; ++i)
        std::cout << sum[i] << ' ';

    for (i = 0; i < matrixSize; ++i)
        if (sum[i] > max)
            max = sum[i];
    std::cout << "\n\nMaximum amount:\n" << max << std::endl;
}

void delElInMatr(int **matrix, const size_t matrixSize) {
    for (size_t i = 0; i < matrixSize; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int **matrix, const size_t matrixSize) {
    std::cout << "--------------------------------------------------------------" << std::endl;
    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixSize; j++) {
            std::cout << matrix[i][j] << "   ";
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------------------------------------------------" << std::endl;

}

int main() {
    setlocale(LC_ALL, "Russian");

    size_t matrixSize = 0;
    std::ifstream file("C:\\Users\\maksm\\Desktop\\mash\\1.txt", std::ios::in | std::ios::binary);

    if (!file) {
        std::cout << "File is not open";
        exit(0);
    }


    while (!file.eof()) {
        int **matrix = getMatrixByFile(file, matrixSize);
        printMatrix(matrix, matrixSize);
        int *sum = getSumSideDiagonal(matrix, matrixSize);
        printSum(sum, matrixSize);
        delElInMatr(matrix, matrixSize);
    }

    file.close();

    system("pause");
    return 0;
}
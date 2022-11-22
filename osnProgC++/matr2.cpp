//
// Created bx maksm on 21.11.2022.
//
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>
#include <cmath>


using namespace std;

int **getMatrixByFile(std::ifstream &fin, size_t &matrixSizeToSet) {
    int **result = nullptr;

    size_t matrixSize = 0;
    fin >> matrixSize;
    matrixSizeToSet = matrixSize;

    result = new int *[matrixSize];
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

void showMatrix(int const *const *const matrix, const size_t matrixSize) {
    std::cout << "--------------------------------------------------------------" << std::endl;
    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixSize; j++) {
            std::cout << matrix[i][j] << "   ";
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------------------------------------------------" << std::endl;

}

float **Decision(int const *const *const A, const size_t matrixSize) { //Функция рассчётов
    float **second = new float *[matrixSize];

    for (size_t i = 0; i < matrixSize; i++) {
        second[i] = new float[matrixSize];
    }

    for (int i = 0; i < matrixSize; ++i) {
        int cnt = 0;
        float sum = 0;
        for (int j = 0; j < matrixSize; ++j) {
            for (int i1 = i - 1; i1 <= i + 1; i1++)
                for (int j1 = j - 1; j1 <= j + 1; j1++)
                    if (i1 >= 0 && i1 < matrixSize && j1 >= 0 && j1 < matrixSize && (i1 != i || j1 != j)) {
                        sum += A[i1][j1];
                        ++cnt;
                    }
            second[i][j] = sum / cnt;
            cnt = 0;
            sum = 0;
        }
    }

    cout << "\nFlat Matrix: " << endl;
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            cout << second[i][j] << "   ";
        }
        cout << "\n\n";
    }

    return second;
}

void summ(float const *const *const A) { //Функция рассчётов
    int sum = 0;
    for (int i = 0; i < **A; i++)
        for (int j = 0; j < i; j++)
            sum += abs(A[i][j]);

    cout << "-------------------------Sum ABS-------------------" << std::endl;
    cout << sum << std::endl;
    cout << "-----------------------------------------------" << std::endl;
}

void deleteMatrix(float **matrix, const size_t matrixSize) {
    for (size_t i = 0; i < matrixSize; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


int main() {
    setlocale(LC_ALL, "Russian");

    size_t matrixSize = 0;
    std::ifstream file("C:\\Users\\maksm\\Desktop\\Rus1\\1.txt", ios::in | ios::binary);

    if (!file) {
        std::cout << "File is not open";
        exit(0);
    }

    while (!file.eof()) {
        int **matrix = getMatrixByFile(file, matrixSize);
        showMatrix(matrix, matrixSize);
        float **flatMatrix = Decision(matrix, matrixSize);
        summ(flatMatrix);
        deleteMatrix((float **) matrix, matrixSize);
        deleteMatrix(flatMatrix, matrixSize);
    }

    file.close();

    return 0;
}
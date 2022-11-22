//
// Created by maksm on 14.11.2022.
//
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int N;
    std::ofstream out;
    out.open("C:\\Users\\maksm\\Documents\\aaa.txt");

    while (true) {
        std::cout << "Input N = ";
        std::cin >> N;
        if (N == 0) {
            break;
        }
        int secondIk = 0, secondJk = 0, j = 0, i = 0, Jc = 0, switcher = 0, Ic = 0, Ring = 0, Xs = 0, Coef = 0;
        int **a = new int *[N];
        for (int i = 0; i < N; i++) {
            a[i] = new int[N];
        }

        for (int ik = 0; ik < N; ik++)
            for (int jk = 0; jk < N; jk++)
                a[ik][jk] = 0;

        for (int ik = N - 1; 0 <= ik; ik--) {
            for (int jk = 0; jk < N; jk++) {
                j = secondJk + 1;
                Jc = abs(j - N / 2 - 1) + (j - 1) / (N / 2) * ((N - 1) % 2);
                i = secondIk + 1;
                switcher = (j - i + N) / N;
                Ic = abs(i - N / 2 - 1) + (i - 1) / (N / 2) * ((N - 1) % 2);
                Ring = N / 2 - (abs(Ic - Jc) + Ic + Jc) / 2;
                Xs = i - Ring + j - Ring - 1;
                Coef = 4 * Ring * (N - Ring);
                a[ik][jk] = Coef + switcher * Xs + abs(switcher - 1) * (4 * (N - 2 * Ring) - 2 - Xs);
                secondIk++;
            }
            secondIk = 0;
            secondJk++;
        }

        for (int ik = 0; ik < N; ik++) {
            for (int jk = 0; jk < N; jk++) {
                printf("%02d ", a[ik][jk]);
                if (out.is_open()) {
                    out << a[ik][jk] << " ";
                }
            }
            out << std::endl;
            cout << endl;
        }
        out << std::endl << std::endl;
    }
    std::cout << "End of program" << std::endl;
    return 0;
}
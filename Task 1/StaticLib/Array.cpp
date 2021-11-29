#include <iostream>
#include <iomanip>

int getSize() {
    int k;
    while (true) {
        std::cout << "Enter number of rows and columns: ";
        std::cin >> k;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Incorrect input. Try again.\n";
            continue;
        }

        if (k <= 0) {
            std::cout << "Incorrect input. Try again.\n";
            continue;
        }
        else {
            break;
        }
    }
    return k;
}

double** createArray(int n) {
    double** array = new double* [n];

    for (int i = 0; i < n; i++) {
        array[i] = new double[n];
    }

    return array;
}

void fillingArrayC(double** array, int n) {
    std::cout << "Filling array C:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = (pow(i, 2) + pow(j, 2)) / ((double)i + (double)j + 1);
        }
    }
}

void fillingArrayD(double** array, int n) {
    std::cout << "Filling array D:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= 8) {
                array[i][j] = pow(i, 2) + pow(j, 2);
            }
            else if (i > 8) {
                array[i][j] = (pow(i, 2) + pow(j, 2)) / 2;
            }
        }
    }
}

void outPutArray(double** array, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(4) << std::setprecision(3) << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void findSumOfMainDiag(double** array, int n) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += array[i][i];
    }
    std::cout << "Sum of main diag of array C:" << sum << std::endl;
}

void findSumOfSideDiag(double** array, int n) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += array[i][n - 1 - i];
    }
    std::cout << "Sum of side diag of array C:" << sum << std::endl;
}

void deleteArray(double** array, int n) {
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;
}
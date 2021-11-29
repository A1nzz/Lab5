#include <iostream>
#include <iomanip>

int getRows() {
    int n;
    while (true) {
        std::cout << "Enter number of rows: ";
        std::cin >> n;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Incorrect input. Try again.\n";
            continue;
        }

        if (n <= 0) {
            std::cout << "Incorrect input. Try again.\n";
            continue;
        }
        else {
            break;
        }
    }
    return n;
}

int getColumns() {
    int n;
    while (true) {
        std::cout << "Enter number of columns: ";
        std::cin >> n;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Incorrect input. Try again.\n";
            continue;
        }

        if (n <= 0) {
            std::cout << "Incorrect input. Try again.\n";
            continue;
        }
        else {
            break;
        }
    }
    return n;
}

int** createArray(int rows, int columns) {
    int** array = new int* [rows];

    for (int i = 0; i < rows; i++) {
        array[i] = new int[columns];
    }

    return array;
}

void fillingArray(int** array, int rows, int columns) {
    std::cout << "Filling array:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cin >> array[i][j];
        }
    }
}

void outPutArray(int** array, int rows, int columns) {
    std::cout << "Your array: " << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int getNumberOfElements(int** array, int rows, int columns) {
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < columns; j += 2) {
            if (array[i][j] % 2 == 1) {
                k++;
            }
        }
    }
    return k;
}

void fillingNewArray(int** array, int* newArray, int rows, int columns) {
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < columns; j += 2) {
            if (array[i][j] % 2 == 1) {
                newArray[k] = array[i][j];
                k++;
            }
        }
    }
}

void outPutNewArray(int* array, int length) {
    std::cout << std::endl << "New Array: " << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << "\t";
    }
}

double getArithmeticMeanOfArray(int* array, int length) {
    double sum = 0;
    if (length == 0) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    double arithmeticMean = sum / (double)length;
    return arithmeticMean;
}

void deleteArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

void deleteNewArray(int* array) {
    delete[] array;
}

int main() {

    int rows = getRows();
    int columns = getColumns();

    int** array = createArray(rows, columns);

    fillingArray(array, rows, columns);
    outPutArray(array, rows, columns);

    int numberOfElementsOfNewArray = getNumberOfElements(array, rows, columns);
    int* newArray = new int[numberOfElementsOfNewArray];
    fillingNewArray(array, newArray, rows, columns);
    outPutNewArray(newArray, numberOfElementsOfNewArray);

    std::cout << std::endl << "Arithmetic mean: " << getArithmeticMeanOfArray(newArray, numberOfElementsOfNewArray) << std::endl;

    deleteArray(array, rows);
    deleteNewArray(newArray);

    return 0;
}
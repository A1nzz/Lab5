#include <iostream>
#include <iomanip>

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
            std::cout << std::setw(4) << std::setprecision(3) << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int getNumberOfElmentsOfNewArray(int** array, int rows, int columns) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < rows) {
        if (array[i][j] % 2 == 0) {
            k++;
        }
        i++;
        j++;
    }
    return k;
}

int* createNewArray(int elements) {
    int* newArray = new int[elements];
    return newArray;
}

void fillingNewArray(int** array, int* newArray, int rows, int columns) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < rows) {
        if (array[i][j] % 2 == 0) {
            newArray[k] = array[i][j];
            k++;
        }
        i++;
        j++;
    }
}

void outPutNewArray(int* newArray, int elements) {
    std::cout << "New array: " << std::endl;
    for (int i = 0; i < elements; i++) {
        std::cout << newArray[i] << "\t";
    }
}

int getCompositionOfElementsOfNewArray(int* newArray, int elements) {
    int comp = 1;
    for (int i = 0; i < elements; i++) {
        comp *= newArray[i];
    }

    return comp;
}

//Delete arrays
void deleteArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

void deleteNewArray(int* newArray) {
    delete[] newArray;
}

//main

int main(){
    const int n = 5;
    const int k = 6;

    int** array = createArray(n, k);
    fillingArray(array, n, k);
    outPutArray(array, n, k);

    int NumberOfElementsOfNewArray = getNumberOfElmentsOfNewArray(array, n ,k);
    int* newArray = createNewArray(NumberOfElementsOfNewArray);
    fillingNewArray(array, newArray, n, k);
    outPutNewArray(newArray, NumberOfElementsOfNewArray);

    std::cout << std::endl << "Composition of elements: " << getCompositionOfElementsOfNewArray(newArray, NumberOfElementsOfNewArray);

    deleteArray(array, n);
    deleteNewArray(newArray);
    return 0;
}
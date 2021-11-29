#include <iostream>
#include <iomanip>
#include <ctime>

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

double** createArray(int rows, int columns) {
    double** array = new double* [rows];

    for (int i = 0; i < rows; i++) {
        array[i] = new double[columns];
    }

    return array;
}

void fillingArray(double** array, int rows, int columns) {
    srand(time(0));
    std::cout << "Filling array:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = (double)(rand() % 100) / 10;
        }
    }
}

void outPutArray(double** array, int rows, int columns) {
    std::cout << "Your array: " << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << std::setw(4) << std::setprecision(3) << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void indexesOfNullElements(double** array, int rows, int columns) {
    std::cout << "Indexes of Null elements: " << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (array[i][j] == 0) {
                std::cout << "Row: " << i << " Column: " << j << std::endl;
            }
        }
    }
}

void numberOfNullElements(double** array, int rows, int columns) {
    std::cout << "Number of Null elements: " << std::endl;
    int s = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (array[i][j] == 0) {
                s++;
            }
        }
    }
    std::cout << s << std::endl;
}

void reverseArray(double** array, int rows, int columns) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < (columns / 2); j++) {
            double temp = array[i][columns - j - 1];
            array[i][columns - j - 1] = array[i][j];
            array[i][j] = temp;
        }
    }  

    for (int i = 0; i < (rows / 2); i++) {
        for (int j = 0; j < columns; j++) {
            double temp = array[rows - i - 1][j];
            array[rows - i - 1][j] = array[i][j];
            array[i][j] = temp;
        }
    }
}

void deleteArray(double** array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

int main() {
   
    int rows = getRows();
    int columns = getColumns();

    double** array = createArray(rows, columns);
   
    fillingArray(array, rows, columns);
    outPutArray(array, rows, columns);

    indexesOfNullElements(array, rows, columns);
    numberOfNullElements(array, rows, columns);

    reverseArray(array, rows, columns);
    outPutArray(array, rows, columns);

    deleteArray(array, rows);

    return 0;
}
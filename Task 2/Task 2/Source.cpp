#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>

int getSize() {
    int n;
    while (true) {
        std::cout << "Enter number of elements: ";
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

int* createArray(int n) {
    int* array = new int[n];
    return array;
}

void fillingArray(int* array, int n) {
    std::cout << "Filling array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
}

void outPutArray(int* array, int n) {
    std::cout << std::endl << "Your Array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << "\t";
    }
}

void deleteArray(int* array) {
    delete[] array;
}


int main() {
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    typedef bool (*isexist) (int* , int, int);
    isexist isExist;
    isExist = (isexist)GetProcAddress(load, "isExist");

    int n = getSize();


    int* array = createArray(n);
    fillingArray(array, n);
    outPutArray(array, n);

    if (isExist(array, n / 3, 0) || isExist(array, n, n / 3) ){
        std::cout << std::endl << "Exist";
    }
    else {
        std::cout << std::endl << "NOT Exist";
    }
    
  
    deleteArray(array);
    FreeLibrary(load);
	return 0;
}
#include <iostream>
#include <iomanip>
#include "..\StaticLib\header.h";

int main() {
    int k = getSize();

    std::cout << "Array C:" << std::endl;
    double** arrayC = createArray(k);
    fillingArrayC(arrayC, k);
    outPutArray(arrayC, k);
    findSumOfMainDiag(arrayC, k);
    findSumOfSideDiag(arrayC, k);
    deleteArray(arrayC, k);

    std::cout << "\n\nArray D:" << std::endl;
    double** arrayD = createArray(k);
    fillingArrayD(arrayD, k);
    outPutArray(arrayD, k);
    findSumOfMainDiag(arrayD, k);
    findSumOfSideDiag(arrayD, k);
    deleteArray(arrayD, k);
    
	return 0;
}
#include <cmath>
extern "C" __declspec(dllexport) bool isExist(int* array, int n, int i) {
    if (i > n - 1) {
        return false;
    }

    if (pow(pow(array[i], 2) + 2, 1.0 / 3) < 10) {
        return true;
    }
    else {
        return isExist(array, n, ++i);
    }
}
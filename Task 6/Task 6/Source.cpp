#include <iostream>

int getN() {
    int n;
    while (true) {
        std::cout << "Enter n: ";
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

int findLargestOddCommonDivisor(int n) {
	for (int i = n; i > 0; i--) {
		if (n % i == 0 && i % 2 == 1) {
			return i;
		}
	}
}

int findSum(int value) {
	int sum = 0;
	for (int i = value; i > 0; i--) {
		sum += findLargestOddCommonDivisor(i);
	}
	return sum;
}

int main() {
    int cases = 1;
    while (cases < 4) {
        int n = getN();

        std::cout << "Result: " << findSum(n) << std::endl;
        cases++;
    }
    

	return 0;
} 
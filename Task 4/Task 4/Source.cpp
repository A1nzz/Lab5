#include <iostream>

int getp() {
	int p;
	while (true) {
		std::cout << "Enter p: ";
		std::cin >> p;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}

		if (p <= 0) {
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}
		else {
			break;
		}
	}
	return p;
}

int getq() {
	int q;
	while (true) {
		std::cout << "Enter q: ";
		std::cin >> q;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}

		if (q <= 0) {
			std::cout << "Incorrect input. Try again.\n";
			continue;
		}
		else {
			break;
		}
	}
	return q;
}

long long functionF(long long n) {
	if (n % 10 > 0) {
		return n % 10;
	}
	else if (n == 0) {
		return 0;
	}
	else {
		return functionF(n / 10);
	}
}

long long functionS(long long p, long long q) {
	long long s = 0;
	for (long long i = p; i <= q; i++) {
		s += functionF(i);
	}
	return s;
}

int main() {
	int cases = 1;
	while (cases < 5) {
		int p = getp();
		int q = getq();
		std::cout << "S = " << functionS(p, q) << std::endl;
		cases++;
	}
	
	return 0;
}
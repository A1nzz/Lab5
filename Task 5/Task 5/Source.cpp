#include <iostream>

unsigned long long PowMod(unsigned long long x, unsigned long long y, unsigned long long n) {
    if (!y) return 1;
    if (y & 1) return (x * PowMod((x * x) % n, y / 2, n)) % n;
    return PowMod((x * x) % n, y / 2, n);
}

int main() {
    unsigned long long k, n, t;
    
    int cases = 1;
    while (cases < 6) {
        std::cout << "Enter n, k, t: ";
        std::cin >> k >> n >> t;
        if (k <= 0 || k >= pow(10, 19) || n <= 0 || n >= pow(10, 19) || t <= 0 || t >= 10) {
            break;
        }
        unsigned long long m = 1;
        for (unsigned long long i = 0; i < t; i++) {
            m *= 10;
        }
        unsigned long long res = PowMod(k % m, n, m);
        std::cout << "Case#" << cases << ": " << res << std::endl;
        cases++;
    }
    return 0;
}
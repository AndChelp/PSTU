#include <iostream>
#include <cmath>

int main() {
    int m, n = 10;
    std::cout << m - ++n << "\n";
    m = n = 10;
    std::cout << (++m > --n) << "\n";
    m = n = 10;
    std::cout << (--m < ++n);
}
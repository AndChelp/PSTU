#include <iostream>
#include <cmath>

int main() {
    double eps = pow(10, -4);
    int n = 1;
    double sum = 0;
    double a;
    do {
        a = 1 / pow(2, n) + 1 / pow(3, n);
        sum += a;
        n++;
    } while (a > eps);
    std::cout << "Ответ: " << sum;
}

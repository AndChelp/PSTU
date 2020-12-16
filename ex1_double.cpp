#include <iostream>
#include <cmath>

int main() {
    double a = 1000;
    double b = 0.0001;

    double ab$3 = pow(a - b, 3);
    double a$3 = pow(a, 3);
    double b$2 = pow(b, 2);
    double _3ab$2 = 3 * a * b$2;
    double upper = ab$3 - (a$3 - _3ab$2);

    double b$3 = pow(b, 3);
    double a$2 = pow(a,2);
    double _3a$2b = 3 * a$2 * b;
    double lower = b$3 - _3a$2b;

    std::cout << upper / lower;
}
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
    float a = 1000;
    float b = 0.0001;

    float ab$3 = pow(a - b, 3);
    float a$3 = pow(a, 3);
    float b$2 = pow(b, 2);
    float _3ab$2 = 3 * a * b$2;
    float upper = ab$3 - (a$3 - _3ab$2);

    float b$3 = pow(b, 3);
    float a$2 = pow(a,2);
    float _3a$2b = 3 * a$2 * b;
    float lower = b$3 - _3a$2b;

    cout << fixed << setprecision(10) << upper / lower;
}
#include <iostream>
#include <complex>

using namespace std;

double diff(double a, double b) {
    return a - b;
}

complex<double> diff(complex<double> a, complex<double> b) {
    return a - b;
}

int main() {
    double a = 2.0, b = 1.0;
    cout << "Вещественное: " << a << "-" << b << "=" << diff(a, b) << "\n";

    complex<double> a1(1.0, 2.0), b2(2.0, 1.0);
    cout << "Комлпексное: " << a1 << "-" << b2 << "=" << diff(a1, b2) << "\n";
}
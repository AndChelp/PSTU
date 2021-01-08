#include <iostream>

#define PI 3.14159265
#define E 2.71828182

using namespace std;
const double a = 0.1;
const double b = 1.0;
const double step = (b - a) / 10;

int fact(int x) {
    int res = 1;
    for (int i = 1; i <= x; i++) {
        res = res * i;
    }
    return res;
}

void byE() {
    double e = 0.01;
    double summ, j;
    int i = 0;
    for (double x = a; x < b; x += step) {
        summ = 1;
        cout << "f(" << x << ")=";
        do {
            i++;
            j = cos(i * PI / 4) / fact(i) * pow(x, i);
            summ += j;
        } while (j >= e);
        cout << summ << "; ";
    }
}

void byN() {
    int n = 25;
    double summ;

    for (double x = a; x < b; x += step) {
        summ = 1;
        cout << "f(" << x << ")=";

        for (int i = 1; i <= n; ++i) {
            summ += cos(i * PI / 4) / fact(i) * pow(x, i);
        }
        cout << summ << "; ";
    }
}

#include <cmath>

void exact() {
    for (double x = a; x < b; x += step) {
        cout << "f(" << x << ")="
             << pow(E, x * cos(PI / 4) * cos(x * sin(PI / 4)))
             << "; ";
    }
}

int main() {
    cout << "Точное значение: \n";
    exact();
    cout << "\nВычисление по N: \n";
    byN();
    cout << "\nВычисление по E: \n";
    byE();
}
#include <iostream>

using namespace std;
int main() {
    int m, n = 10;
    cout << m - ++n << "\n";
    m = n = 10;
    cout << (++m > --n) << "\n";
    m = n = 10;
    cout << (--m < ++n);
}
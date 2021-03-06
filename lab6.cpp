#include <iostream>

void shift(char *string, int from, int size) {
    char number = string[from];
    while (from++ < size) {
        string[from - 1] = string[from];
    }
    string[size] = number;
}

int main() {
    char str[256];
    std::cout << "Строка: ";
    gets_s(str);
    //gets(str); //removed since C++14
    int strLength = strlen(str);
    int uncheckedLength = strLength;
    for (int i = 0; i < uncheckedLength; ++i) {
        //согласно ASCII, коды всех цифр находятся между 48 и 57
        if (str[i] >= 48 && str[i] <= 57) {
            uncheckedLength--;
            shift(str, i--, strLength - 1);
        }
    }
    std::cout << "Результат: " << str;
}
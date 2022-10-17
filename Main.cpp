#include <iostream>
#include "calc.h"
#include "brain.cpp"

int main() {
    Calc calc;
    string stri = calc.input();
    stack<int> numsy = calc.nums;
    brain(stri, numsy);
    return 0;
}

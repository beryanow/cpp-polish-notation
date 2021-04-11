#include <iostream>
#include "SimpleReversePolishCalculator.h"

int main() {
    std::cout << "Результат выражения (5 2 - 10 *) : ";
    simple_reverse_polish_calculator("5 2 - 10 *");

    std::cout << "Результат выражения (10 0 /) : ";
    simple_reverse_polish_calculator("10 0 /");

    std::cout << "Результат выражения (10 5 ^) : ";
    simple_reverse_polish_calculator("10 5 ^");

    std::cout << "Результат выражения (10.5 5 / 3.5 2 * +) : ";
    simple_reverse_polish_calculator("10.5 5 / 3.5 2 * +");

    std::cout << "Результат выражения (5 5 + 5 * 10 / 7 + 3 *) : ";
    simple_reverse_polish_calculator("5 5 + 5 * 10 / 7 + 3 *");

    std::cout << "Результат выражения (5 3 + 6 3 + 5 + 12 - *) : ";
    simple_reverse_polish_calculator("5 3 + 6 3 + 5 + 12 - *");

    return 0;
}
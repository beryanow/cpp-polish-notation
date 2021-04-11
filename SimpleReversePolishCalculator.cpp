#include "SimpleReversePolishCalculator.h"

// занесение числа в стек
Void push(Stack &stack, Number number) {
    stack.push_back(number);
}

// получение числа из стека
Number pop(Stack &stack) {
    double result = stack.back();

    stack.pop_back();

    return result;
}

Token get_token(Text &expression) {
    size_t index = 0;
    Text rest_expression;

    // пропуск всех пробелов
    if (isblank(expression[index])) {
        while (isblank(expression[++index]));
    }

    // проверка на окончание выражения
    if (index >= expression.size()) {
        return {TermType::EMPTY, Text()};
    }

    // определение операции
    if (!isdigit(expression[index]) && expression[index] != '.') {
        char operation_symbol = expression[index++];

        // сохранение оставшейся части выражения
        while (index < expression.size()) {
            rest_expression += expression[index++];
        }

        expression = rest_expression;

        return {TermType(operation_symbol), Text()};
    }

    Text value = Text();

    // считывание следующего числа
    if (isdigit(expression[index])) {
        while (isdigit(expression[index])) {
            value += expression[index++];
        }
    }

    // считывание вещественного числа (его дробной части)
    if (expression[index] == '.') {
        value += expression[index++];

        while (isdigit(expression[index])) {
            value += expression[index++];
        }
    }

    // сохранение оставшейся части выражения
    while (index < expression.size()) {
        rest_expression += expression[index++];
    }

    expression = rest_expression;

    return {TermType::NUMBER, value};
}

Void simple_reverse_polish_calculator(Text expression) {
    Token token;
    Number number;
    Stack stack;

    while ((token = get_token(expression)).first != TermType::EMPTY) {
        switch (token.first) {
            case TermType::NUMBER:
                push(stack, stod(token.second));
                break;

            case TermType::SUM_OPERATION:
                push(stack, pop(stack) + pop(stack));
                break;

            case TermType::MUL_OPERATION:
                push(stack, pop(stack) * pop(stack));
                break;

            case TermType::SUB_OPERATION:
                push(stack, -pop(stack) + pop(stack));
                break;

            case TermType::DIV_OPERATION:
                number = pop(stack);
                if (number != 0)
                    push(stack, pop(stack) / number);
                else {
                    std::cout << "N/A [деление на ноль] " << std::endl;
                    return;
                }
                break;

            default:
                std::cout << "N/A [неизвестная операция " << char(token.first) << "]" << std::endl;
                return;
        }
    }

    std::cout << pop(stack) << std::endl;
}
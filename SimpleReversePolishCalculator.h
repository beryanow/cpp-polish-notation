#include <iostream>
#include <string>
#include <vector>
#include <utility>

enum class TermType {
    NUMBER = '0',
    SUM_OPERATION = '+',
    SUB_OPERATION = '-',
    MUL_OPERATION = '*',
    DIV_OPERATION = '/',
    EMPTY = '\0'
};

typedef double Number;
typedef std::string Text;
typedef void Void;
typedef std::pair<TermType, Text> Token;
typedef std::vector<double> Stack;

Token get_token(Text &);
Void push(Stack &, Number);
Number pop(Stack &);
Void simple_reverse_polish_calculator(Text);
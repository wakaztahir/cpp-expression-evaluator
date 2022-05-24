//
// Created by wakaztahir on 5/24/2022.
//

#pragma once

#include <stack>
#include <iostream>

double getDouble(char *&x);

double applyOp(const double *num1, const double *num2, const char *op);

int precedence(char op);

void solveSingle(std::stack<char> &ops, std::stack<double> &values);

double evaluateExpression(char *expression) {
    std::stack<char> ops;
    std::stack<double> values;

    while (*expression != '\0') {
        // skip whitespace
        if (*expression == ' ') {
            ++expression;
        } else if (*expression == '(') {
            ops.push('(');
            ++expression;
        } else if (*expression >= '0' && *expression <= '9') {
            values.push(getDouble(expression));
        } else if (*expression == ')') {
            while (!ops.empty() && ops.top() != '(') {
                solveSingle(ops, values);
            }
            if (!ops.empty()) ops.pop();
            ++expression;
        } else if (*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(*expression)) {
                solveSingle(ops, values);
            }
            ops.push(*expression);
            ++expression;
        } else {
            throw std::exception("unexpected character found");
        }
    }

    while (!ops.empty()) {
        solveSingle(ops, values);
    }

    return values.top();
}

void solveSingle(std::stack<char> &ops, std::stack<double> &values) {
    double value2 = values.top();
    values.pop();

    double value1 = values.top();
    values.pop();

    char op = ops.top();
    ops.pop();

    values.push(applyOp(&value1, &value2, &op));
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default :
            return 0;
    }
}

double getDouble(char *&x) {
    double number = 0;
    while (*x >= '0' && *x <= '9') {
        number *= 10;
        number += (*x - '0');
        x++;
    }
    if (*x == '.') {
        x++;
        double weight = 10;
        while (*x >= '0' && *x <= '9') {
            number += (*x - '0') / weight;
            weight *= 10;
            x++;
        }
    }
    return number;
}

double applyOp(const double *num1, const double *num2, const char *op) {
    switch (*op) {
        case '+':
            return *num1 + *num2;
        case '-':
            return *num1 - *num2;
        case '*':
            return *num1 * *num2;
        case '/':
            return *num1 / *num2;
        default :
            throw std::exception("unexpected operand encountered");
    }
}
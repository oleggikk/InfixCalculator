#ifndef INFIX_TO_POSTFIX_CONVERTER_H
#define INFIX_TO_POSTFIX_CONVERTER_H

#endif  // INFIX_TO_POSTFIX_CONVERTER_H

#include <iostream>
#include <string>
#include "Stack.h"

class InfixToPostfixConverter {
private:
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    bool isNumeric(char ch) {
        return ch >= '0' && ch <= '9';
    }

    int precedence(char ch) {
        if (ch == '+' || ch == '-')
            return 1;
        if (ch == '*' || ch == '/')
            return 2;
        return 0;
    }

public:
    std::string convert(const std::string& infix) {
        std::string postfix;
        Stack<char> stack;

        for (size_t i = 0; i < infix.length(); ++i) {
            char ch = infix[i];
            if (ch == ' ') {
                continue;
            } else if (isNumeric(ch)) {
                postfix += ch;
                while (i + 1 < infix.length() && isNumeric(infix[i + 1])) {
                    postfix += infix[i + 1];
                    ++i;
                }
                postfix += ' ';
            } else if (ch == '(') {
                stack.push(ch);
            } else if (ch == ')') {
                while (!stack.isEmpty() && stack.top() != '(') {
                    postfix += stack.pop();
                    postfix += ' ';
                }
                stack.pop();
            } else if (isOperator(ch)) {
                if (i == 0 || (isOperator(infix[i - 1]) && infix[i - 1] != ')')) {
                    postfix += '0';
                    postfix += ' ';
                }

                while (!stack.isEmpty() && stack.top() != '(' && precedence(stack.top()) >= precedence(ch)) {
                    postfix += stack.pop();
                    postfix += ' ';
                }
                stack.push(ch);
            }
        }

        while (!stack.isEmpty()) {
            postfix += stack.pop();
            postfix += ' ';
        }

        if (!postfix.empty() && postfix.back() == ' ') {
            postfix.pop_back();
        }

        return postfix;
    }
};

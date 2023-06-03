#include <iostream>
#include "InfixToPostfixConverter.h"
#include "Calculator.h"

int main()
{
    Calculator calculator;
    InfixToPostfixConverter converter;
    int result;
    std::string infixExpression = "";
    std::cout << "Enter the expression: " << std::endl;
    while (true)
    {
        std::getline(std::cin, infixExpression);
        if (infixExpression == "exit")
        {
            break;
        }
        try {
            std::string postfixExpression = converter.convert(infixExpression);
            std::cout << "Postfix expression: " << postfixExpression << std::endl;
            result = calculator.calculate(postfixExpression);
            std::cout << "Result: " << result << std::endl;
        }
        catch (std::runtime_error &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "Enter the expression or \"exit\" to exit: " << std::endl;
    }
    return 0;
}

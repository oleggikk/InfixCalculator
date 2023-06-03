#include <string>

class Calculator {
public:
    int calculate(const std::string& expression);

private:
    bool isNumber(const std::string& str);
    bool isOperator(const std::string& str);
    int performOperation(int operand1, int operand2, const std::string& op);
};

#include <stack>
#include <sstream>
#include <stdexcept>

int Calculator::calculate(const std::string& expression) {
    std::stack<int> stack;

    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (isNumber(token)) {
            int num = std::stoi(token);
            stack.push(num);
        } else if (isOperator(token)) {
            if (stack.size() < 2) {
                throw std::runtime_error("Error: Invalid expression");
            }
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();
            int result = performOperation(operand1, operand2, token);
            stack.push(result);
        } else {
            throw std::runtime_error("Error: Invalid expression");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Error: Invalid expression");
    }

    return stack.top();
}

bool Calculator::isNumber(const std::string& str) {
    return !str.empty() && std::isdigit(str[0]);
}

bool Calculator::isOperator(const std::string& str) {
    return str == "+" || str == "-" || str == "*" || str == "/";
}

int Calculator::performOperation(int operand1, int operand2, const std::string& op) {
    if (op == "+") {
        return operand1 + operand2;
    } else if (op == "-") {
        return operand1 - operand2;
    } else if (op == "*") {
        return operand1 * operand2;
    } else if (op == "/") {
        if (operand2 == 0) {
            throw std::runtime_error("Error: Division by zero");
        }
        return operand1 / operand2;
    }
    throw std::runtime_error("Error: Invalid operator");
}

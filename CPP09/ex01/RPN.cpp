/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:41:16 by sgarigli          #+#    #+#             */
/*   Updated: 2024/11/07 11:18:28 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &src) {
    *this = src;
}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
	{
    }
    return *this;
}

RPN::~RPN()
{
	
}

bool RPN::isOperator(const std::string &token)
{
    switch (token[0])
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}

bool RPN::isNumber(const std::string &token)
{
	if (token.empty())
		return false;
	for (size_t i = 0; i < token.size(); i++)
	{
		if (i == 0 && (token[i] == '+' || token[i] == '-'))
			continue;
		if (!std::isdigit(token[i]))
			return false;
	}
	if (token.size() > 1)
		return false;
	return true;
}

double RPN::applyOperator(const std::string &op, double a, double b) {
    if (op == "+")
		return (a + b);
    if (op == "-")
		return (a - b);
    if (op == "*")
		return (a * b);
    if (op == "/")
	{
        if (b == 0)
			throw std::runtime_error("Division by zero");
        return (a / b);
    }
    throw std::runtime_error("Invalid expression : " + op);
}

double RPN::evaluate(const std::string &expression)
{
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
	{
        if (isOperator(token))
		{
            if (stack.size() < 2)
				throw std::runtime_error("Invalid expression");
            double b = stack.top();
			stack.pop();
            double a = stack.top();
			stack.pop();
            double result = applyOperator(token, a, b);
            stack.push(result);
        } else if (isNumber(token))
		{
            try
			{
                double operand = std::stod(token);
                stack.push(operand);
            } catch (const std::invalid_argument &) {
                throw std::runtime_error("Invalid token: " + token);
            }
        }else 
		{
			throw std::runtime_error("Invalid token: " + token);
		}
    }
    if (stack.size() != 1)
		throw std::runtime_error("Invalid expression");
    return stack.top();
}
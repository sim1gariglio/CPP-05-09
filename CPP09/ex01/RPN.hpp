/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:41:18 by sgarigli          #+#    #+#             */
/*   Updated: 2024/11/07 10:55:08 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN
{
public:
    RPN();
    RPN(const RPN &src);
    RPN &operator=(const RPN &rhs);
    ~RPN();

    double evaluate(const std::string &expression);

private:
    bool isOperator(const std::string &token);
	bool isNumber(const std::string &token);
    double applyOperator(const std::string &op, double a, double b);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:48:24 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/15 11:49:40 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout<<"ScalarConverter Default constructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &New)
{
    *this = New;
	std::cout<<"ScalarConverter Copy constructor called\n";
}

ScalarConverter::~ScalarConverter()
{
	std::cout<<"ScalarConverter Destructor called\n";
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &New)
{
	std::cout<<"ScalarConverter Copy assignment operator called\n";
    (void)New;
	return(*this);
}

int CheckLimits(std::string str)
{
    if(str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return (1);
    }
    else if(str == "+inf" || str == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return (1);
    }
    else if(str == "-inf" || str == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return (1);
    }
    else
        return (0);
}


int CheckValid(std::string str)
{
    int i = -1;
    int p = 0;

    if (str.length() == 1)
        return (0);
    while (str[++i])
    {
        if(!isdigit(str[i]) && str[i] != '.' && str[i] != 'f' && str[i] != '+' && str[i] != '-')
        {
            std::cout << "Invalid input" << std::endl;
            return (1);
        }
        if (str[i] == 'f' && str[i + 1])
        {
            std::cout << "Invalid input" << std::endl;
            return (1);
        }
        if (str[i] == '.' && isdigit(str[i + 1]))
            p++;
        else if (str[i] == '.' && !isdigit(str[i + 1]))
        {
            std::cout << "Invalid input" << std::endl;
            return (1);
        }
        if ((str[i] == '+' || str[i] == '-') && i != 0)
        {
            std::cout << "Invalid input" << std::endl;
            return (1);
        }
    }
    if (p > 1)
    {
        std::cout << "Invalid input" << std::endl;
        return (1);
    }
    return (0);
}

int CheckType(std::string str)
{
    if (str.length() == 1 && !isdigit(str[0]))
        return (1);
    else if (str.find('f') == (str.length() - 1) && str.find('.'))
        return (2);
    else if (str.find('.') != std::string::npos)
        return (3);
    return (0);
}

int getPrecision(std::string str)
{
    int i = 0;
    int p = 0;

    if (str.find('.') == std::string::npos)
        return (1);
    while (str[i])
    {
        if (str[i] == '.')
            p = 1;
        if (p > 0)
            p++;
        if (str[i] == 'f')
            break;
        i++;
    }
    if (p > 4)
        return (4);
    return (p - 2);
}

void ScalarConverter::convert(std::string str)
{
    long double n = 0;
    int p;
    char c;
    int i;
    float f;
    double d;

    if (CheckLimits(str))
        return;
    if (CheckValid(str))
        return;
    n = CheckType(str);
    if (n == 0)
    {
        i = atoi(str.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (n == 1)
    {
        c = str[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (n == 2)
    {
        f = atof(str.c_str());
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    }
    else if (n == 3)
    {
        d = atof(str.c_str());
        i = static_cast<int>(d);
        c = static_cast<char>(d);
        f = static_cast<float>(d);
    }

    if (n == 3)
        p = getPrecision(str);
    else
        p = 1;
    if (n == 1)
        n = static_cast<long double>(c);
    else
        n = static_cast<long double>(atoll(str.c_str()));

    std::cout << "char: ";
    if (n <= 127 && n >= -128)
    {
        if (c < 32 || c > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << c << "'" << std::endl;
    }
    else
        std::cout << "Overflow" << std::endl;

    std::cout << "int: ";
    if (n <= INT_MAX && n >= INT_MIN)
        std::cout << i << std::endl;
    else
        std::cout << "Overflow" << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: ";
    if (n <= FLT_MAX && n >= -FLT_MAX)
            std::cout << f << "f" << std::endl;
    else
        std::cout << "Overflow" << std::endl;

    std::cout << std::fixed << std::setprecision(p);
    std::cout << "double: ";
    if (n <= DBL_MAX && n >= -DBL_MAX)
            std::cout << d << std::endl;
    else
        std::cout << "Overflow" << std::endl;
}
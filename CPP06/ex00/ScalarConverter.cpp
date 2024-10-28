/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:21:15 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/28 10:33:42 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

void emptyPrint() {
	std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: impossible" << std::endl
		<< "double: impossible" << std::endl;
}

bool ft_isInfNan(std::string str) {
	if (str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff") {
		std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: " << str[0] << "inff" << std::endl
		<< "double: " << str[0] << "inf" << std::endl;
		return (true);
	}
	if (str == "nan" || str == "nanf") {
		std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: " << "nanf" << std::endl
		<< "double: " << "nan" << std::endl;
		return (true);
	}
	return (false);
}

void printInt(long i) {
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;
}

void printChar(std::string str) {
	bool dot = false;
	double d = std::strtod(str.c_str(), NULL);
	if (d > 127 || d < 0) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	int i = 0;
	while (str[i]) {
		if (dot && str[i] != '0' && str[i] != 'f'){
			std::cout << "char: impossible" << std::endl;
			return ;
		}
		if (str[i] == '.')
			dot = true;
		i++;
	}
	if (d < ' ' || d > '~')
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'"<< std::endl;
}

int inputAnalyze(std::string str, int *precision) {
	if (str.empty())
		return (-1);
	if (((str[0] >= ' ' && str[0] < '0') || (str[0] > '9' && str[0] <= '~' )) && !str[1])
		return (0);
	bool isDouble = false;
	bool isNegative = false;
	size_t i = 0;
	if(str[i] == '-' || str[i] == '+') {
		i++;
		if(str[i] == '-')
			isNegative = true;
	}
	while (str[i]) {
		if (str[i] == '.' && (str[i + 1] < '0' || str[i + 1] > '9'))
			return (-1);
		else if (str[i] == '.' && i != 0 && isDouble == false)
			isDouble = true;
		else if (str[i] < '0' || str[i] > '9')
			break ;
		if (isDouble == true && str[i] != '.')
			(*precision)++;
		i++;
	}
	if (str[i] == 'f') {
		if (str.size() == i + 1)
			return (2);
		return (-1);
	}
	if (i == 0 || (isNegative == true && i == 1) || str.size() != i)
		return (-1);
	if (isDouble == true || str.length() > 12)
		return (3);
	return (1);
}

void convertFromChar(char c) {
	std::cout << "char: '" << c << "'" << std::endl
		<< "int: " << static_cast<int>(c) << std::endl
		<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl
		<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void convertFromInt(std::string str) {
	printChar(str);
	long i = std::strtol(str.c_str(), NULL, 10);
	printInt(i);
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl
		<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void convertFromFloat(std::string str, int precision) {
	if (precision == 0)
		precision++;
	printChar(str);
	float f = std::strtof(str.c_str(), NULL);
	printInt(static_cast<long>(f));
	std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl
		<< "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(f) << std::endl;
}

void convertFromDouble(std::string str, int precision) {
	if (precision == 0)
		precision++;
	printChar(str);
	double d = std::strtod(str.c_str(), NULL);
	printInt(static_cast<long>(d));
	std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(d) << "f" << std::endl
		<< "double: " << std::fixed << std::setprecision(precision) << d << std::endl;
}

void ScalarConverter::convert(std::string str) {
	int precision = 0;
	if (ft_isInfNan(str))
		return ;
	try {
		switch (inputAnalyze(str, &precision)) {
			case 0:
				convertFromChar(str[0]);
				break ;
			case 1:
				convertFromInt(str);
				break ;
			case 2:
				convertFromFloat(str, precision);
				break ;
			case 3:
				convertFromDouble(str, precision);
				break ;
			default:
				return (emptyPrint());
				break ;
		}
	}
	catch (std::exception &e) {
		std::cerr << "Error: at function " << e.what() <<std::endl;
	}
};
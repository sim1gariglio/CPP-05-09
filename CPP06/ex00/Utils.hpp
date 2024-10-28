/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:54:29 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/23 12:05:50 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

std::string getType(std::string str)
{
	// Check if the string is a char
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
        return "char";
    }

    // Check if the string is an int
    try {
        size_t pos;
        std::stoi(str, &pos);
        if (pos == str.length()) {
            return "int";
        }
    } catch (const std::invalid_argument &) {
        // Not an int
    } catch (const std::out_of_range &) {
        // Not an int
    }

    // Check if the string is a float
    try {
        size_t pos;
        std::stof(str, &pos);
        if (pos == str.length() || (pos == str.length() - 1 && (str.back() == 'f' || str.back() == 'F'))) {
            return "float";
        }
    } catch (const std::invalid_argument &) {
        // Not a float
    } catch (const std::out_of_range &) {
        // Not a float
    }

    // Check if the string is a double
    try {
        size_t pos;
        std::stod(str, &pos);
        if (pos == str.length()) {
            return "double";
        }
    } catch (const std::invalid_argument &) {
        // Not a double
    } catch (const std::out_of_range &) {
        // Not a double
    }

    return "unknown";
}

void convertChar(std::string str)
{
	int CharToInt = 0;
	float CharToFloat = 0;
	double CharToDouble = 0;
	
	CharToInt = static_cast<int>(str[0]);
	CharToFloat = static_cast<float>(str[0]);
	CharToDouble = static_cast<double>(str[0]);
}

void convertInt(std::string str)
{
	
}

void convertFloat(std::string str)
{
	
}

void convertDouble(std::string str)
{
	
}


#endif
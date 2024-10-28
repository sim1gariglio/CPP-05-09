/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:06:19 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/28 15:30:21 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void printInt(const int &x)
{
    std::cout << x << " ";
}

void printDouble(const double &x)
{
    std::cout << x << " ";
}

void printString(const std::string &str)
{
    std::cout << str << " ";
}

int main()
{
    // Test with an array of integers
    int intArray[] = {0, 1, 2, 3, 4};
    std::cout << "Integer array: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;

    // Test with an array of doubles
    double doubleArray[] = {0.1, 1.2, 2.3, 3.4, 4.5};
    std::cout << "Double array: ";
    iter(doubleArray, 5, printDouble);
    std::cout << std::endl;

    // Test with an array of strings
    std::string stringArray[] = {"Hello", "world", "this", "is", "a test"};
    std::cout << "String array: ";
    iter(stringArray, 5, printString);
    std::cout << std::endl;

    return 0;
}

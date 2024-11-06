/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:37:01 by sgarigli          #+#    #+#             */
/*   Updated: 2024/11/05 11:52:44 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

int main()
{
    srand(time(NULL));

    // Create an array of integers
    Array<int> numbers(MAX_VAL);
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    // Create a mirror array to compare
    int* mirror = new int[MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++)
    {
        mirror[i] = numbers[i];
    }

    // Test out-of-bounds access
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Print the numbers array
    std::cout << "Numbers array:" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << i << " " << numbers[i] << std::endl;
    }

    // Clean up dynamically allocated memory
    delete [] mirror;

    // Test copy constructor
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i * 10;
    }

    Array<int> intArrayCopy(intArray);
    std::cout << "Copied array:" << std::endl;
    for (unsigned int i = 0; i < intArrayCopy.size(); i++)
    {
        std::cout << i << " " << intArrayCopy[i] << std::endl;
    }

    return 0;
}
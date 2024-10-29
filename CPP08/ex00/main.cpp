/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:17:52 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/29 11:36:12 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iterator>
#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers = {2, 2, 3, 4, 5};

    try
    {
        std::vector<int>::iterator it = easyfind(numbers, 2);
        std::cout << "Element found: " << *it << " at position " << std::distance(numbers.begin(), it) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(numbers, 6);
        std::cout << "Element found: " << *it << " at position " << std::distance(numbers.begin(), it) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
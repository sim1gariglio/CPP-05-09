/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:48:13 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/15 11:49:43 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        if (argc == 1)
            std::cout << "Error: not enough arguments" << std::endl;
        else
            std::cout << "Error: too many arguments" << std::endl;
    }
    else
        ScalarConverter::convert(argv[1]);
    return (0);
}
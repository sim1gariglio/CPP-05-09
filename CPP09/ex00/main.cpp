/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:37:07 by sgarigli          #+#    #+#             */
/*   Updated: 2024/11/06 12:03:43 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc [input_filename]" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    exchange.readDatabase();
    exchange.processInput(argv[1]);

    return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:55:19 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/08 11:50:10 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors.hpp"

int main()
{
    try
    {
        Bureaucrat b("sgarigli", 5);
        std::cout << GREEN << b << RESET;
        b.incrementGrade();
        std::cout << GREEN << b << RESET;
        b.incrementGrade();
        std::cout << GREEN << b << RESET;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    try
    {
        Bureaucrat b("mruggier", 146);
        std::cout << GREEN << b << RESET;
        b.decrementGrade();
        std::cout << GREEN << b << RESET;
        b.decrementGrade();
        std::cout << GREEN << b << RESET;
		b.decrementGrade();
		std::cout << GREEN << b << RESET;
		b.decrementGrade();
		std::cout << GREEN << b << RESET;
		b.decrementGrade();
		std::cout << GREEN << b << RESET;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    try
    {
        Bureaucrat b("gduranti", 3);
        std::cout << GREEN << b << RESET;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    try
    {
        Bureaucrat b("lmicheli", 149);
        std::cout << GREEN << b << RESET;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    return 0;
}
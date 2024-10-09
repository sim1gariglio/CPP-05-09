/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:55:19 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/09 11:54:46 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Colors.hpp"

int main()
{
    try
    {
        Bureaucrat sgarigli("sgarigli", 1);
        Bureaucrat mruggier("mruggier", 50);
        Bureaucrat lmicheli("lmicheli", 100);
        Bureaucrat gduranti("gduranti", 150);

		PresidentialPardonForm formA("formA");
		RobotomyRequestForm formB("formB");
		ShrubberyCreationForm formC("formC");

		std::cout << CYAN << sgarigli << RESET;
		std::cout << CYAN << mruggier << RESET;
		std::cout << CYAN << lmicheli << RESET;
		std::cout << CYAN << gduranti << RESET;
        std::cout << CYAN << formA << RESET;
        std::cout << CYAN << formB << RESET;
        std::cout << CYAN << formC << RESET;
		
        sgarigli.signForm(formA);
        mruggier.signForm(formA);
        lmicheli.signForm(formA);
        gduranti.signForm(formA);

        sgarigli.signForm(formB);
        mruggier.signForm(formB);
        lmicheli.signForm(formB);
        gduranti.signForm(formB);

        sgarigli.signForm(formC);
        mruggier.signForm(formC);
        lmicheli.signForm(formC);
        gduranti.signForm(formC);
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    return 0;
}
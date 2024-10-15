/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:55:19 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/15 09:32:41 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Colors.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat sgarigli("sgarigli", 1);
        Bureaucrat mruggier("mruggier", 44);
        Bureaucrat lmicheli("lmicheli", 100);
        Bureaucrat gduranti("gduranti", 150);

		PresidentialPardonForm formA("sgarigli");
		RobotomyRequestForm formB("mruggier");
		ShrubberyCreationForm formC("lmicheli");

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

		Intern intern;

		AForm *formD = intern.makeForm("presidential pardon", "sgarigli");
		AForm *formE = intern.makeForm("robotomy request", "mruggier");
		AForm *formF = intern.makeForm("shrubbery creation", "lmicheli");
		
		sgarigli.signForm(*formD);
		mruggier.signForm(*formE);
		lmicheli.signForm(*formE);
		gduranti.signForm(*formF);

		sgarigli.executeForm(*formD);
		mruggier.executeForm(*formE);
		lmicheli.executeForm(*formF);
		gduranti.executeForm(*formF);


    }
    catch (const std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    return 0;
}
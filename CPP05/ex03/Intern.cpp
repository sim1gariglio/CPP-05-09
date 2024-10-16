/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:52:55 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/16 11:55:17 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &rhs)
{
	return (*this);
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *(Intern::*formPtr[3])(std::string target) = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};
	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			std::cout << CYAN << "Intern creates " << forms[i] << " form" << RESET << std::endl << std::endl;
			return ((this->*formPtr[i])(target));
		}
	}
	std::cout << RED << "Intern can't create " << form << " form" << RESET << std::endl;	
	return (NULL);
}
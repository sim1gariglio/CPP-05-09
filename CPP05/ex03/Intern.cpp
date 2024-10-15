/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:52:55 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/15 09:34:19 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"

Intern::Intern()
{
	_forms["shrubbery creation"] = &Intern::createShrubberyCreationForm;
	_forms["robotomy request"] = &Intern::createRobotomyRequestForm;
	_forms["presidential pardon"] = &Intern::createPresidentialPardonForm;
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
	_forms = rhs._forms;
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
    std::map<std::string, AForm *(Intern::*)(std::string)>::iterator it = _forms.find(form);
	if (it != _forms.end())
	{
		std::cout << YELLOW << "Intern creates " << form << RESET << std::endl << std::endl;
		return ((this->*(it->second))(target));
	}
	std::cout << "Form not found" << std::endl;
	return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:52:58 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/16 11:44:33 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <map>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &src);
    ~Intern();
    Intern &operator=(const Intern &rhs);
    AForm *makeForm(std::string form, std::string target);

private:
    AForm *createPresidentialPardonForm(std::string target);
    AForm *createRobotomyRequestForm(std::string target);
    AForm *createShrubberyCreationForm(std::string target);
};

#endif
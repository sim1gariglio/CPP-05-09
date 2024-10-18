/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:57:33 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/18 10:27:09 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Colors.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

Form &Form::operator=(Form const & rhs)
{
	if (this != &rhs)
	{
		*this = Form(rhs);
	}
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	if (_signed)
		throw Form::FormAlreadySignedException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << RESET << rhs.getName() << " << form grade to sign " << rhs.getGradeToSign() << ", form grade to execute " << rhs.getGradeToExecute() << ", ";
	if (rhs.getSigned())
		o << GREEN << "signed " << RESET << ">>" <<std::endl;
	else
		o << RED << "not signed " << RESET << ">>" <<std::endl;
	return o;
}

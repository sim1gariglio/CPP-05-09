/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:52:25 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/10 11:40:23 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too low");
				}
		};
		
		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form is already signed");
				}
		};
		
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form const & src);
		Form &operator=(Form const & rhs);
		~Form();
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
};
std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
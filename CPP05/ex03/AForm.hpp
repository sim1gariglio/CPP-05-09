/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:05:28 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/10 11:57:05 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "Colors.hpp"

class AForm
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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form is not signed");
				}
		};
		
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm const & src);
		AForm &operator=(AForm const & rhs);
		virtual ~AForm();
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
		
		virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif
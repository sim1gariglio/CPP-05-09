/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:34:45 by sgarigli          #+#    #+#             */
/*   Updated: 2024/11/07 11:51:14 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main ( int ac, char **av )
{
	if (ac == 1)
	{
		std::cout << "Usage: ./pmerge [numbers]" << std::endl;
		return 1;
	}
	if (ac == 2)
	{
		std::cout << "Please enter more than one number" << std::endl;
		return 1;
	}
	SortDeez sort(av + 1);
	return 0;
}
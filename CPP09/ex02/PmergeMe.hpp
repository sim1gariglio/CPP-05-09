/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:34:49 by sgarigli          #+#    #+#             */
/*   Updated: 2024/11/11 11:36:25 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <sstream>

class Sorting
{
private:
	std::list<int> m_list;
	std::vector<int> m_vector;

public:
	Sorting(char **av);
	Sorting(Sorting const &copy);
	~Sorting();
	Sorting &operator=(Sorting const &copy);

	void parse(char **av);
	void sort();

	bool isInt(std::string str);
};

#endif
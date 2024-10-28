/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:31:24 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/28 15:47:07 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {

	private:
		T* m_array;
		unsigned int m_size;	

	public:
		Array();
		Array(unsigned int n);
		Array(Array const& src);
		~Array();

		Array& operator=(Array const& src);
		T& operator[](unsigned int i);

		unsigned int size() const;
		class OutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:09:00 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/15 12:09:01 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout<<"Serializer Default constructor called\n";
}

Serializer::Serializer(const Serializer &New)
{
    *this = New;
	std::cout<<"Serializer Copy constructor called\n";
}

Serializer::~Serializer()
{
	std::cout<<"Serializer Destructor called\n";
}

Serializer& Serializer::operator=(const Serializer &New)
{
	std::cout<<"Serializer Copy assignment operator called\n";
    (void)New;
	return(*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}
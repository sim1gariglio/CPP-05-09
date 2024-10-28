/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Func.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:54:16 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/28 11:41:10 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_HPP
#define FUNC_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <tr1/random>

void init_rand(void);

class InitRandCaller
{
public:
	InitRandCaller()
	{
		init_rand();
	}
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
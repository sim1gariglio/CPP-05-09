/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:18:15 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/28 11:41:10 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Func.hpp"

int main(void)
{
	Base *base = generate();
	Base *base2 = generate();
	Base *base3 = generate();
	Base *base4 = NULL;
	Base &ref = *base;
	std::cout << "ref " << std::endl;
	identify(ref);
	std::cout << "pointer " << std::endl;
	identify(base);
	identify(*base);
	identify(base2);
	identify(*base2);
	identify(base3);
	identify(*base3);
	identify(base4);
	delete base;
	delete base2;
	delete base3;
	return 0;
}
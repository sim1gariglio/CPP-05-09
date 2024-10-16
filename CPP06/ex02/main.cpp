/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:09:15 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/15 12:09:16 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base *b;
    for (int i = 0; i < 10; i++)
    {
        if (i)
            std::cout << std::endl;
        b = generate();
        identify(b);
        identify(*b);
        delete b;
    }
    return (0);
}
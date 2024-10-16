/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:08:52 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/15 12:08:53 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data *data = new Data();
    uintptr_t raw = Serializer::serialize(data);
    Data *data2 = Serializer::deserialize(raw);

    std::cout << "Data is: " << data << std::endl;
    std::cout << "Data serialized as uintptr_t is: " << raw << std::endl;
    std::cout << "uintptr_t deserialized as Data is: " << data2 << std::endl;
    delete data;
    return (0);
}
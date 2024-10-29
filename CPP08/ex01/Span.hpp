/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:45:08 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/29 11:48:21 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

private:
    std::vector<int> numbers;
    unsigned int maxSize;
};

#endif // SPAN_HPP
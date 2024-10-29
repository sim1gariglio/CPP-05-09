/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:45:08 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/29 11:53:00 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxSize(0)
{
	
}

Span::Span(unsigned int N) : maxSize(N)
{
	
}

Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize)
{
	
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        numbers = other.numbers;
        maxSize = other.maxSize;
    }
    return *this;
}

Span::~Span() 
{
	
}

void Span::addNumber(int number)
{
    if (numbers.size() >= maxSize)
    {
        throw std::runtime_error("Span is already full");
    }
    numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
    {
        throw std::runtime_error("Not enough numbers to find a span");
    }

    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); ++i)
    {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < shortest)
        {
            shortest = span;
        }
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
    {
        throw std::runtime_error("Not enough numbers to find a span");
    }

    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());

    return max - min;
}
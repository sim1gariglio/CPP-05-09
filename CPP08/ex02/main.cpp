/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:08:25 by sgarigli          #+#    #+#             */
/*   Updated: 2024/10/29 12:34:40 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void testPushAndPop()
{
    std::cout << YELLOW << "Test: Push and Pop" << RESET << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << GREEN << "Top element after pushing 5 and 17: " << RESET << mstack.top() << std::endl; // Output: 17

    mstack.pop();
    std::cout << GREEN << "Size after popping top element: " << RESET << mstack.size() << std::endl; // Output: 1

    if (!mstack.empty())
    {
        mstack.pop();
        std::cout << GREEN << "Size after popping top element: " << RESET << mstack.size() << std::endl; // Output: 0
    }
    else
    {
        std::cout << RED << "Cannot pop from an empty stack!" << RESET << std::endl;
    }

    if (!mstack.empty())
    {
        mstack.pop();
        std::cout << GREEN << "Size after popping top element: " << RESET << mstack.size() << std::endl; // Output: 0
    }
    else
    {
        std::cout << RED << "Cannot pop from an empty stack!" << RESET << std::endl;
    }
}

void testIteration()
{
    std::cout << YELLOW << "Test: Iteration" << RESET << std::endl;

    MutantStack<int> mstack;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << GREEN << "Elements in stack:" << RESET << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite)
    {
        std::cout << CYAN << *it << RESET << std::endl;
        ++it;
    }
}

void testCopyConstructor()
{
    std::cout << YELLOW << "Test: Copy Constructor" << RESET << std::endl;

    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    MutantStack<int> copyStack(mstack);
    std::cout << GREEN << "Elements in copied stack:" << RESET << std::endl;
    MutantStack<int>::iterator it = copyStack.begin();
    MutantStack<int>::iterator ite = copyStack.end();
    while (it != ite)
    {
        std::cout << CYAN << *it << RESET << std::endl;
        ++it;
    }
}

void testAssignmentOperator()
{
    std::cout << YELLOW << "Test: Assignment Operator" << RESET << std::endl;

    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << GREEN << "Elements in assigned stack:" << RESET << std::endl;
    MutantStack<int>::iterator it = assignedStack.begin();
    MutantStack<int>::iterator ite = assignedStack.end();
    while (it != ite)
    {
        std::cout << CYAN << *it << RESET << std::endl;
        ++it;
    }
}

int main()
{
    testPushAndPop();
    std::cout << std::endl;
    testIteration();
    std::cout << std::endl;
    testCopyConstructor();
    std::cout << std::endl;
    testAssignmentOperator();
    return 0;
}

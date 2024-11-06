/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:37:01 by sgarigli          #+#    #+#             */
/*   Updated: 2024/11/06 12:18:09 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
        _exchange = rhs._exchange;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::readDatabase()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty() || line.find("date") != std::string::npos)
            continue;

        std::istringstream iss(line);
        std::string date;
        double rate;
        if (std::getline(iss, date, ','))
        {
            iss >> rate;
            _exchange[date] = rate;
        }
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open input file" << std::endl;
        return;
    }

    std::string line;
	std::getline(file, line);
	if (line != "date | value")
	{
		std::cerr << "Error: first line must be <date | value>" << std::endl;
		return;
	}
    while (std::getline(file, line))
    {
        std::string error;
        if (!checkLine(line, error))
        {
            std::cerr << "Error: " << error << " => " << line << std::endl;
            continue;
        }

        std::istringstream iss(line);
        std::string date;
        double value;
        if (std::getline(iss, date, '|'))
        {
            iss >> value;
            date = date.substr(0, date.find(" "));
            if (_exchange.find(date) != _exchange.end())
            {
                double exchangeRate = _exchange[date];
                double result = value * exchangeRate;
                std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
            }
            else
            {
                // Find the closest lower date
                std::map<std::string, double>::iterator it = _exchange.lower_bound(date);
                if (it != _exchange.begin())
                {
                    --it;
                    double exchangeRate = it->second;
                    double result = value * exchangeRate;
                    std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
                }
                else
                {
                    std::cerr << "Error: date not found in database => " << date << std::endl;
                }
            }
        }
    }
    file.close();
}

bool BitcoinExchange::checkLine(const std::string &line, std::string &error)
{
    size_t pos = line.find(" | ");
    if (pos == std::string::npos)
    {
        error = "bad input";
        return false;
    }

    std::string date = line.substr(0, pos);
    std::string valueStr = line.substr(pos + 3);

    if (!checkDate(date))
    {
        error = "bad input";
        return false;
    }

    try
    {
        double value;
        std::istringstream(valueStr) >> value;
        if (value < 0)
        {
            error = "not a positive number";
            return false;
        }
        if (value > 1000)
        {
            error = "too large a number";
            return false;
        }
    }
    catch (const std::exception &)
    {
        error = "bad input";
        return false;
    }

    return true;
}

bool BitcoinExchange::checkDate(const std::string &date)
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    int year, month, day;
    std::istringstream(date.substr(0, 4)) >> year;
    std::istringstream(date.substr(5, 2)) >> month;
    std::istringstream(date.substr(8, 2)) >> day;

    if (year > 9999)
        return false;

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Check for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}




/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Exception.hpp
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <string>

class Exception: std::exception{
    public:
        Exception(const std::string &message);
        ~Exception();

        const std::string &getMessage();
    protected:
    private:
        std::string message;
};

#endif /* !EXCEPTION_HPP_ */

/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Exception.cpp
*/

#include "../include/Exception.hpp"

Exception::Exception(const std::string &message): message(message)
{
}

Exception::~Exception()
{
}

const std::string &Exception::getMessage()
{
    return (this->message);
}
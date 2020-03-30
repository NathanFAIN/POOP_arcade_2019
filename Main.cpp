/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** main.cpp
*/

#include <string>
#include <iostream>
#include <string.h>
#include "exception/include/Exception.hpp"
#include "core/include/Core.hpp"

void helper(void)
{
    std::cout << "USAGE" << std::endl;
}

int main(int ac, char **av)
{
    try {
        if (ac != 2) {
            throw Exception("Invalid number of arguments.");
        }
    } catch (Exception &except) {
        std::cerr << except.getMessage() << std::endl;
        helper();
        return (84);
    }
    if (strcmp(av[1],"-h") == 0) {
        helper();
        return (0);
    }
    Core core;
    core.setGraphic(av[1]);
    core.setGames("games/libsnake.so");
    core.MainLoop();
    return (0);
}
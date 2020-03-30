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


typedef struct bytes_allocated_s
{
    int allocated;
} bytes_allocated_t;

bytes_allocated_t mem;

void printMem()
{
    std::cout << mem.allocated << std::endl;
}

void *operator new(size_t size)
{
    // std::cout << "allocate " << size << " byte(s)" << std::endl;
    mem.allocated += size;
    return (malloc(size));
}

void operator delete(void *ptr, size_t size)
{
    // std::cout << "delete " << size << " byte(s)" << std::endl;
    mem.allocated -= size; 
    free(ptr);
}

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
    std::cout << core;
    core.setGraphic(av[1]);
    core.setGames("games/libsnake.so");
    core.MainLoop();

    //---------leak-memory-checker----------
    // printMem();
    //-------------------------------------
    return (0);
}
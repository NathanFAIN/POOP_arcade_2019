/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "IGame.hpp"
#include <array>
#include <stdlib.h>

extern "C" void SnakeConstructor(void) __attribute__((constructor));
extern "C" void SnakeDestructor(void) __attribute__((destructor));

class Snake : public IGames {
    public:
        Snake();
        ~Snake();
        std::vector<std::vector<char>> simulate(Input key);
        std::string getScore();
        std::string getLife();
        void init() {};
        std::vector<InitTab> getInit();
        std::vector<std::vector<char>> restart(bool);
    protected:
    private:
        int _score, _life;
        std::vector<std::vector<char>> _map;
        std::array<int, 2> _head, _tail;
        Input _direction;
        const std::vector<InitTab> _tabInit;
};

#endif /* !SNAKE_HPP_ */

/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Centipede
*/

#ifndef CENTIPEDE_HPP_
#define CENTIPEDE_HPP_

#include "IGame.hpp"
#include <array>
#include <stdlib.h>

extern "C" void CentipedeConstructor(void) __attribute__((constructor));
extern "C" void CentipedeDestructor(void) __attribute__((destructor));

class Centipede : public IGames {
    public:
        Centipede();
        ~Centipede();
        void init() {};
        std::vector<std::vector<char>> simulate(Input key);
        std::string getScore();
        std::string getLife();
        std::vector<InitTab> getInit();
        std::vector<std::vector<char>> restart();
        std::vector<std::vector<char>> lose();
    protected:
    private:
        int _score, _life, _count, _toAppear;
        std::array<int, 2> _player, _lazer;
        std::vector<std::array<int, 3>> _centipedes;
        std::vector<std::vector<char>> _map;
        const std::vector<InitTab> _tabInit;
};

#endif /* !CENTIPEDE_HPP_ */

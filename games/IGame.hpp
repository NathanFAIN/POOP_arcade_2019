/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

#include <vector>
#include <string>
#include "../lib/InitTab.hpp"
#include "../core/include/Core.hpp"

class IGames {
    public:
        virtual ~IGames() = default;
        virtual void init() = 0;
        virtual std::vector<std::vector<char>> simulate(Input key) = 0;
        virtual std::string getScore() = 0;
        virtual std::string getLife() = 0;
        virtual std::vector<InitTab> getInit() = 0;

    protected:
    private:
};

#endif /* !IGAMES_HPP_ */

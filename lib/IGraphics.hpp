/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGraphics
*/

#ifndef IGRAPHICS_HPP_
#define IGRAPHICS_HPP_

#include "vector"
#include "string"
#include "InitTab.hpp"
#include "../core/include/Core.hpp"

class IGraphics {
    public:
        virtual ~IGraphics() = default;
        virtual void displayGame(const std::vector<std::vector<char>> &) = 0;
        virtual void init(const std::vector<InitTab> &) = 0;
        virtual void setScore(const std::string &) = 0;
        virtual void setLife(const std::string &) = 0;
        virtual Input getInput(void) const = 0;
    protected:
    private:
};

#endif /* !IGRAPHICS_HPP_ */

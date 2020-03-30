/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <algorithm>
#include <iostream>
#include <unistd.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <fcntl.h>
#include "Info.hpp"
#include "../../exception/include/Exception.hpp"
#include "../../lib/InitTab.hpp"
#include "../include/LibManager.hpp"

#ifdef __NCURSES_H
#undef KEY_UP
#undef KEY_DOWN
#undef KEY_LEFT
#undef KEY_RIGHT
#endif


enum __attribute__((packed)) Input {
    NONE = -1,
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    EXIT,
    PREV_GAME,
    NEXT_GAME,
    ENTER,
    PREV_GRAPH,
    NEXT_GRAPH
};

class IGraphics;
class IGames;

#include "../../games/IGame.hpp"
#include "../../lib/IGraphics.hpp"

class Core {
    public:
        Core();
        ~Core();

        // enum __attribute__((packed)) LibType {
        //     GAME,
        //     GRAPHICAL
        // };

        void MainLoop();

        const Info &getInfo(void) const;
        void setInfo(Info info);//should never happen
        IGraphics *getGraphic(void) const;
        void setGraphic(const std::string &libPath);
        IGames *getGame(void) const;
        void setGames(const std::string &libPath);

        const std::string getGraphicName(void) const;
        const std::string getGameName(void) const;

        // const std::string nameToPath(const std::string &name, LibType type) const;

    protected:
    private:
        Info _info;
        IGraphics *_Graphic;
        IGames *_Game;
};

std::ostream &operator<<(std::ostream &out, Core core);

#endif /* !CORE_HPP_ */

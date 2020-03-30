/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "../include/Core.hpp"

//-----------------ctor/dtor-----------------------
Core::Core(): _info(Info()), _Graphic(nullptr), _Game(nullptr)
{
}

Core::~Core()
{
}

//------------------Main-Loop----------------------
void Core::MainLoop() {
    // static_cast<IGames *>(this->_Game)->displayMenu();
    this->_Graphic->init(this->_Game->getInit());
    while (1) {
        usleep(100000);
        this->_Graphic->displayGame(this->_Game->simulate(this->_Graphic->getInput()));
    }
}

//--------------getters-&-setters-------------------
const Info &Core::getInfo(void) const
{
    return (this->_info);
}

void Core::setInfo(Info info)//should never happen
{
    this->_info = info;
}

IGraphics *Core::getGraphic(void) const
{
    return (this->_Graphic);
}

void Core::setGraphic(const std::string &libPath)
{
    if (this->_Graphic != nullptr) {
        LibManager<IGraphics>::closeLib(this->_Graphic);
    }
    this->_Graphic = LibManager<IGraphics>::openLib(libPath);
}

IGames *Core::getGame(void) const
{
    return (this->_Game);
}

void Core::setGames(const std::string &libPath)
{
    if (this->_Game != nullptr) {
        LibManager<IGames>::closeLib(this->_Game);
    }
    this->_Game = LibManager<IGames>::openLib(libPath);
}

//------------Info-interactions------------------
const std::string Core::getGraphicName(void) const
{
    if (this->_Graphic == nullptr) {
        return ("None");
    }
    return (this->_info.getGraphNames().at(this->_info.getGraphIdx()));
}

const std::string Core::getGameName(void) const
{
    if (this->_Game == nullptr) {
        return ("None");
    }
    return (this->_info.getGameNames().at(this->_info.getGameIdx()));
}


// //--------------Utilities--------------------------
// const std::string Core::nameToPath(const std::string &name, LibType type) const
// {
//     return ((type == this->GAME ? "./games/lib_arcade_" : "./lib/lib_arcade_") + name + ".so");
// }

//--------------Overload---------------------------
std::ostream &operator<<(std::ostream &out, Core core)
{
    out << "Graphic: " << core.getGraphicName() << std::endl << "Game: " << core.getGameName() << std::endl;
    return (out);
}
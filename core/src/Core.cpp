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
    // static_cast<IGames *>(this->_Game)->init();
    // static_cast<IGraphics *>(this->_Graphic)->init(static_cast<IGames *>(this->_Game)->getInit());
    // static_cast<IGraphics *>(this->_Graphic)->displayMenu ??
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

void *Core::getGraphic(void) const
{
    return (this->_Graphic);
}

void Core::setGraphic(void *lib)
{
    if (this->_Graphic != nullptr) {
        this->closeLib(this->_Graphic);
    }
    this->_Graphic = lib;
}

void *Core::getGame(void) const
{
    return (this->_Game);
}

void Core::setGames(void *game)
{
    if (this->_Game != nullptr) {
        this->closeLib(this->_Game);
    }
    this->_Game = game;
}

//-----------lib-handling-----------------------
void *Core::openLib(const std::string &pathLib)
{
    void *handle;
}

void Core::closeLib(void *lib)
{
    // dlclose(lib);
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


//--------------Utilities--------------------------
const std::string Core::nameToPath(const std::string &name, LibType type) const
{
    return ((type == this->GAME ? "./games/lib_arcade_" : "./lib/lib_arcade_") + name + ".so");
}

//--------------Overload---------------------------
std::ostream &operator<<(std::ostream &out, Core core)
{
    out << "Graphic: " << core.getGraphicName() << std::endl << "Game: " << core.getGameName() << std::endl;
    return (out);
}
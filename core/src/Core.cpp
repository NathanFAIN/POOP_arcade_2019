/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "../include/Core.hpp"

//-----------------ctor/dtor-----------------------
Core::Core(): _info(Info()), _Graphic(nullptr), _Game(nullptr), _isMenu(true)
{
    this->initInfoLib();
}

Core::~Core()
{
}

//------------------Initialization-----------------
void
Core::initInfoLib(void)
{
    DIR *dir = nullptr;
    struct dirent *dirp = nullptr;
    std::string key = ".so";

    dir = opendir("./lib");
    for (;(dirp = readdir(dir)) != nullptr;) {
        if (std::string(dirp->d_name).rfind(key) != std::string::npos) {
            std::cout << dirp->d_name << std::endl;
        }
    }
}

//------------------Main-Loop----------------------
void
Core::MainLoop() {
    this->_Graphic->init(this->_Game->getInit());

    //loop
    while (1) {

        //delay between each game tick (may be changed)
        usleep(100000);

        //handle Input
        Input current = this->_Graphic->getInput();
        if (current == EXIT) {
            if (this->_isMenu == false) {
                LibManager<IGames>::closeLib(&this->_Game);
                this->_isMenu = true;
            } else {
                this->closeLibs();
                break;
            }
        }

        //display and informations exchanges
        if (this->_isMenu == false) {
            //0 life left
            if (this->_Game->getLife() == "0") {
                LibManager<IGames>::closeLib(&this->_Game);
                this->_isMenu = true;
            }
            this->_Graphic->setLife(this->_Game->getLife());
            this->_Graphic->setScore(this->_Game->getScore());
            this->_Graphic->displayGame(this->_Game->simulate(current));
        } else {
            // this->_Graphic->displayMenu();
        }
    }
}

//--------------getters-&-setters-------------------
const Info &
Core::getInfo(void) const
{
    return (this->_info);
}

void
Core::setInfo(Info info)//should never happen
{
    this->_info = info;
}

IGraphics *
Core::getGraphic(void) const
{
    return (this->_Graphic);
}

void
Core::setGraphic(const std::string &libPath)
{
    if (this->_Graphic != nullptr) {
        LibManager<IGraphics>::closeLib(&this->_Graphic);
    }
    this->_Graphic = LibManager<IGraphics>::openLib(libPath);
}

IGames *
Core::getGame(void) const
{
    return (this->_Game);
}

void
Core::setGames(const std::string &libPath)
{
    if (this->_Game != nullptr) {
        LibManager<IGames>::closeLib(&this->_Game);
    }
    this->_Game = LibManager<IGames>::openLib(libPath);
}

//------------Info-interactions------------------
const std::string
Core::getGraphicName(void) const
{
    if (this->_Graphic == nullptr) {
        return ("None");
    }
    return (this->_info.getGraphNames().at(this->_info.getGraphIdx()));
}

const std::string
Core::getGameName(void) const
{
    if (this->_Game == nullptr) {
        return ("None");
    }
    return (this->_info.getGameNames().at(this->_info.getGameIdx()));
}


//--------------Utilities--------------------------
void
Core::closeLibs(void)
{
    LibManager<IGames>::closeLib(&this->_Game);
    LibManager<IGraphics>::closeLib(&this->_Graphic);
}

//--------------Overload---------------------------
std::ostream &
operator<<(std::ostream &out, Core core)
{
    out << "Graphic: " << core.getGraphicName() << std::endl << "Game: " << core.getGameName() << std::endl;
    return (out);
}
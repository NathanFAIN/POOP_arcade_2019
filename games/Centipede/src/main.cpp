/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include <dlfcn.h>
#include "Centipede.hpp"
#include <unistd.h>

using IGraphicsCreator = IGraphics *(*)(void);
using IGraphicsDestroyer = void (*)(IGraphics *);

using IGamesCreator = IGames *(*)(void);
using IGamesDestroyer = void (*)(IGames *);

int main(void)
{
    void *graphicHandle;
    IGraphics *graphicClass;
    IGraphicsCreator createIGraphics;
    IGraphicsDestroyer destroyIGraphics;

    void *gameHandle;
    IGames *gameClass;
    IGamesCreator createIGames;
    IGamesDestroyer destroyIGames;

    graphicHandle = dlopen("../../lib/libncurses.so", RTLD_LAZY);
    if (!graphicHandle) {
        std::cerr << "ERROR: Invalid file.\n";
        return (84);
    }
    createIGraphics = reinterpret_cast<IGraphicsCreator>(dlsym(graphicHandle, "createIGraphics"));
    destroyIGraphics = reinterpret_cast<IGraphicsDestroyer>(dlsym(graphicHandle, "destroyIGraphics"));
    if (dlerror() || !createIGraphics || !destroyIGraphics) {
        std::cerr << "ERROR: Function not found.\n";
        dlclose(graphicHandle);
        return (84);
    }

    gameHandle = dlopen("../libcentipede.so", RTLD_LAZY);
    if (!gameHandle) {
        std::cerr << "ERROR: Invalid file.\n";
        return (84);
    }
    createIGames = reinterpret_cast<IGamesCreator>(dlsym(gameHandle, "createIGames"));
    destroyIGames = reinterpret_cast<IGamesDestroyer>(dlsym(gameHandle, "destroyIGames"));
    if (dlerror() || !createIGames || !destroyIGames) {
        std::cerr << "ERROR: Function not found.\n";
        dlclose(gameHandle);
        return (84);
    }
    // const std::vector<InitTab> tabInit({InitTab(' ', 0, 0, "none.png"), InitTab('#', 4, 4, "none.png")});
    // std::vector<std::vector<char>> map;
    // for (int i = 0; i != 10; i++) {
    //     std::vector<char> map_bis;
    //     for (int j = 0; j != 10; j++) {
    //         map_bis.push_back('#');
    //     }
    //     map.push_back(map_bis);
    // }
    graphicClass = createIGraphics();
    gameClass = createIGames();
    Input key = NONE;
    graphicClass->init(gameClass->getInit());
    while (atoi(gameClass->getLife().c_str()) > 0 && key != EXIT) {
        key = graphicClass->getInput();
        graphicClass->setLife(gameClass->getLife());
        graphicClass->setScore(gameClass->getScore());
        graphicClass->displayGame(gameClass->simulate(key));
        usleep(100000);
    }
    // testClass->init(tabInit);
    // do {
    //     testClass->displayGame(map);
    // } while (testClass->getInput() != EXIT);

    destroyIGames(gameClass);
    destroyIGraphics(graphicClass);
    dlclose(graphicHandle);
    dlclose(gameHandle);
    return (0);
}
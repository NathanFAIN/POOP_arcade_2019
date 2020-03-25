/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "Ncurses.hpp"

using IGraphicsCreator = IGraphics *(*)(void);
using IGraphicsDestroyer = void (*)(IGraphics *);

int main(void)
{
    void *handle;
    IGraphics *testClass;
    IGraphicsCreator createIGraphics;
    IGraphicsDestroyer destroyIGraphics;

    handle = dlopen("../libncurses.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "ERROR: Invalid file.\n";
        return (84);
    }
    createIGraphics = reinterpret_cast<IGraphicsCreator>(dlsym(handle, "createIGraphics"));
    destroyIGraphics = reinterpret_cast<IGraphicsDestroyer>(dlsym(handle, "destroyIGraphics"));
    if (dlerror() || !createIGraphics || !destroyIGraphics) {
        std::cerr << "ERROR: Function not found.\n";
        dlclose(handle);
        return (84);
    }

    const std::vector<InitTab> tabInit({InitTab(' ', 0, 0, "none.png"), InitTab('#', 4, 4, "none.png")});
    std::vector<std::vector<char>> map;
    for (int i = 0; i != 10; i++) {
        std::vector<char> map_bis;
        for (int j = 0; j != 10; j++) {
            map_bis.push_back('#');
        }
        map.push_back(map_bis);
    }
    testClass = createIGraphics();
    testClass->init(tabInit);
    testClass->setLife("NONE");
    testClass->setScore("NONE");
    do {
        usleep(100);
        testClass->displayGame(map);
    } while (testClass->getInput() != EXIT);
    destroyIGraphics(testClass);

    dlclose(handle);
    return (0);
}
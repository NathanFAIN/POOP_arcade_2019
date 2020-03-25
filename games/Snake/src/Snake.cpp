/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#include "Snake.hpp"

extern "C" void SnakeConstructor(void)
{
    std::cout << "Snake library launched." << std::endl;
}

extern "C" void SnakeDestructor(void)
{
    std::cout << "Snake library left." << std::endl;
}

extern "C" Snake *createIGames()
{
    return new Snake();
}

extern "C" void destroyIGames(Snake *object)
{
    delete object;
}

Snake::Snake() : _tabInit({InitTab('>', 2, 2, "body.png"),\
InitTab('<', 2, 2, "body.png"),\
InitTab('v', 2, 2, "body.png"),\
InitTab('^', 2, 2, "body.png"),\
InitTab('o', 3, 3, "head.png"),\
InitTab('@', 1, 1, "apple.png"),\
InitTab('#', 7, 7, "wall.png"),\
InitTab(' ', 0, 0, "empty.png")})
{
    std::vector<char> tmp;
    int appleX = 0, appleY = 0;

    _score = 0;
    _life = 3;
    _direction = KEY_RIGHT;
    _head = {11, 12};
    _tail = {11, 10};
    for (int i = 0; i < 23; i++)
        tmp.push_back(' ');
    for (int i = 0; i < 23; i++)
        _map.push_back(tmp);
    for (int i = 0; i < 23; i++) {
        _map[i][0] = '#';
        _map[i][22] = '#';
        _map[0][i] = '#';
        _map[22][i] = '#';
    }
    _map[11][10] = '>';
    _map[11][11] = '>';
    _map[11][12] = 'o';
    do {
        appleX = (rand() % 21) + 1;
        appleY = (rand() % 21) + 1;
    } while (_map[appleY][appleX] != ' ');
    _map[appleY][appleX] = '@';
}

Snake::~Snake()
{
}

std::vector<std::vector<char>> Snake::simulate(Input key)
{
    int newX = 0, newY = 0;

    if (_direction == KEY_UP)
        _map[_head[0]][_head[1]] = '^';
    else if (_direction == KEY_DOWN)
        _map[_head[0]][_head[1]] = 'v';
    else if (_direction == KEY_LEFT)
        _map[_head[0]][_head[1]] = '<';
    else if (_direction == KEY_RIGHT)
        _map[_head[0]][_head[1]] = '>';
    if (key == KEY_DOWN && _direction != KEY_UP)
        _direction = KEY_DOWN;
    else if (key == KEY_LEFT && _direction != KEY_RIGHT)
        _direction = KEY_LEFT;
    else if (key == KEY_RIGHT && _direction != KEY_LEFT)
        _direction = KEY_RIGHT;
    else if (key == KEY_UP && _direction != KEY_DOWN)
        _direction = KEY_UP;
    if (_direction == KEY_UP)
        _head[0]--;
    else if (_direction == KEY_DOWN)
        _head[0]++;
    else if (_direction == KEY_LEFT)
        _head[1]--;
    else if (_direction == KEY_RIGHT)
        _head[1]++;
    if (_map[_head[0]][_head[1]] != ' ' && _map[_head[0]][_head[1]] != '@')
        return restart(false);
    if (_map[_head[0]][_head[1]] != '@') {
        _map[_tail[0]][_tail[1]] = ' ';
        if (_tail[0] + 1 <= 22 && _map[_tail[0] + 1][_tail[1]] == 'v')
            _tail[0]++;
        else if (_tail[0] - 1 >= 0 && _map[_tail[0] - 1][_tail[1]] == '^')
            _tail[0]--;
        else if (_tail[1] + 1 <= 22 && _map[_tail[0]][_tail[1] + 1] == '>')
            _tail[1]++;
        else if (_tail[1] - 1 >= 0 && _map[_tail[0]][_tail[1] - 1] == '<')
            _tail[1]--;
    }
    else {
        _score += 10;
        for (int i = 1; i < 22; i++)
            for (int j = 1; j < 22; j++) {
                if (_map[i][j] == ' ')
                    break;
                else if (i == 21 && j == 21)
                    return restart(true);
            }
        do {
            newX = (rand() % 21) + 1;
            newY = (rand() % 21) + 1;
        } while (_map[newY][newX] != ' ');
        _map[newY][newX] = '@';
    }
    _map[_head[0]][_head[1]] = 'o';
    return _map;
}

std::string Snake::getScore()
{
    return std::to_string(_score);
}

std::string Snake::getLife()
{
    return std::to_string(_life);
}

std::vector<InitTab> Snake::getInit()
{
    return _tabInit;
}

std::vector<std::vector<char>> Snake::restart(bool isWin)
{
    int appleX = 0, appleY = 0;

    if (!isWin)
        _life--;
    _direction = KEY_RIGHT;
    _head = {11, 12};
    _tail = {11, 10};
    for (int i = 1; i < 22; i++)
        for (int j = 1; j < 22; j++)
            _map[i][j] = ' ';
    _map[11][10] = '>';
    _map[11][11] = '>';
    _map[11][12] = 'o';
    do {
        appleX = (rand() % 21) + 1;
        appleY = (rand() % 21) + 1;
    } while (_map[appleY][appleX] != ' ');
    _map[appleY][appleX] = '@';
    return _map;
}
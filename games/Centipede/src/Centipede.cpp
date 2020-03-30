/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Centipede
*/

#include "Centipede.hpp"

extern "C" void CentipedeConstructor(void)
{
    std::cout << "Centipede library launched." << std::endl;
}

extern "C" void CentipedeDestructor(void)
{
    std::cout << "Centipede library left." << std::endl;
}

extern "C" Centipede *createInterface()
{
    return new Centipede();
}

extern "C" void destroyInterface(Centipede *object)
{
    delete object;
}

Centipede::Centipede() : _tabInit({InitTab(' ', 0, 0, "void.png"),\
InitTab('!', 1, 1, "mushroom5.png"),\
InitTab('\"', 5, 5, "mushroom4.png"),\
InitTab('#', 4, 4, "mushroom3.png"),\
InitTab('$', 6, 6, "mushroom2.png"),\
InitTab('%', 2, 2, "mushroom1.png"),\
InitTab('P', 3, 3, "player.png"),\
InitTab('|', 1, 0, "lazer.png"),\
InitTab('O', 7, 7, "centipede.png")})
{
    std::vector<char> tmp;

    _life = 5;
    _score = 0;
    _count = 0;
    _toAppear = 10;
    for (int i = 0; i < 40; i++)
        tmp.push_back(' ');
    for (int i = 0; i < 40; i++)
        _map.push_back(tmp);
    for (int i = 0; i < 30 ; i++)
        _map[rand() % 32][rand() % 40] = '%';
    _lazer[0] = -1;
    _player = {38, 20};
    _map[38][20] = 'P';
    _centipedeRight = true;
}

Centipede::~Centipede()
{
}

std::vector<std::vector<char>> Centipede::simulate(Input key)
{
    // player move
    if (key == KEY_UP && _player[0] > 32 && _map[_player[0] - 1][_player[1]] == ' ') {
        _map[_player[0]][_player[1]] = ' ';
        _player[0]--;
        _map[_player[0]][_player[1]] = 'P';
    }
    else if (key == KEY_DOWN && _player[0] < 39 && _map[_player[0] + 1][_player[1]] == ' ') {
        _map[_player[0]][_player[1]] = ' ';
        _player[0]++;
        _map[_player[0]][_player[1]] = 'P';
    }
    else if (key == KEY_LEFT && _player[1] > 0 && _map[_player[0]][_player[1] - 1] == ' ') {
        _map[_player[0]][_player[1]] = ' ';
        _player[1]--;
        _map[_player[0]][_player[1]] = 'P';
    }
    else if (key == KEY_RIGHT && _player[1] < 39 && _map[_player[0]][_player[1] + 1] == ' ') {
        _map[_player[0]][_player[1]] = ' ';
        _player[1]++;
        _map[_player[0]][_player[1]] = 'P';
    }
    // new centipede
    if (!_centipedes.size() && !_toAppear) {
        _centipedeRight = !_centipedeRight;
        if (_count >= 20)
            return restart();
        _toAppear = 10;
        _count++;
    }
    // centipedes move
    for (std::vector<std::array<int, 3UL>>::iterator i = _centipedes.begin(); i != _centipedes.end(); i++) {
        if ((*i)[2] == 0 && (*i)[1] > 0 && (_map[(*i)[0]][(*i)[1] - 1] == ' ' || _map[(*i)[0]][(*i)[1] - 1] == '|')) {
            _map[(*i)[0]][(*i)[1]] = ' ';
            (*i)[1]--;
            _map[(*i)[0]][(*i)[1]] = 'O';
        }
        else if ((*i)[2] == 0 && (*i)[1] > 0 && _map[(*i)[0]][(*i)[1] - 1] == 'P')
            return lose();
        else if ((*i)[2] == 0 && (*i)[0] < 39) {
            _map[(*i)[0]][(*i)[1]] = ' ';
            (*i)[0]++;
            (*i)[2] = 1;
            _map[(*i)[0]][(*i)[1]] = 'O';
        }
        else if ((*i)[2] == 1 && (*i)[1] < 39 && (_map[(*i)[0]][(*i)[1] + 1] == ' ' || _map[(*i)[0]][(*i)[1] + 1] == '|')) {
            _map[(*i)[0]][(*i)[1]] = ' ';
            (*i)[1]++;
            _map[(*i)[0]][(*i)[1]] = 'O';
        }
        else if ((*i)[2] == 1 && (*i)[1] < 39 && _map[(*i)[0]][(*i)[1] + 1] == 'P')
            return lose();
        else if ((*i)[2] == 1 && (*i)[0] < 39) {
            _map[(*i)[0]][(*i)[1]] = ' ';
            (*i)[0]++;
            (*i)[2] = 0;
            _map[(*i)[0]][(*i)[1]] = 'O';
        }
        else {
            _score -= 100;
            if (_score < 0)
                _score = 0;
            _map[(*i)[0]][(*i)[1]] = ' ';
            i--;
            _centipedes.erase(i + 1);
        }
    }
    // spawn centipedes
    if (_toAppear) {
        _toAppear--;
        _centipedes.push_back({0, 19, _centipedeRight});
    }
    // lazer
    if (_lazer[0] < 0)
        _lazer = _player;
    if (_map[_lazer[0]][_lazer[1]] == '|')
        _map[_lazer[0]][_lazer[1]] = ' ';
    for (int i = 0; i < 3; i++) {
        _lazer[0]--;
        if (_lazer[0] < 0)
            _lazer = _player;
        else if (_map[_lazer[0]][_lazer[1]] >= '!' && _map[_lazer[0]][_lazer[1]] <= '%') {
            _map[_lazer[0]][_lazer[1]]--;
            if (_map[_lazer[0]][_lazer[1]] == ' ')
                _score += 25;
            _lazer[0] = -1;
        }
        else if (_map[_lazer[0]][_lazer[1]] == 'O') {
            _map[_lazer[0]][_lazer[1]] = '%';
            _score += 100;
            for (std::vector<std::array<int, 3UL>>::iterator it = _centipedes.begin(); it < _centipedes.end(); it++) {
                if ((*it)[0] == _lazer[0] && (*it)[1] == _lazer[1]) {
                    _centipedes.erase(it);
                    break;
                }
            }
            _lazer[0] = -1;
        }
    }
    if (_lazer[0] >= 0 && _map[_lazer[0]][_lazer[1]] == ' ')
        _map[_lazer[0]][_lazer[1]] = '|';
    return _map;
}

std::string Centipede::getScore()
{
    return std::to_string(_score);
}

std::string Centipede::getLife()
{
    return std::to_string(_life);
}

std::vector<InitTab> Centipede::getInit()
{
    return _tabInit;
}

std::vector<std::vector<char>> Centipede::restart()
{
    _count = 0;
    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 40; j++)
            _map[i][j] = ' ';
    for (int i = 0; i < 30 ; i++)
        _map[rand() % 32][rand() % 40] = '%';
    _map[38][20] = 'P';
    _lazer[0] = -1;
    _player = {38, 20};
    _centipedeRight = true;
    return _map;
}

std::vector<std::vector<char>> Centipede::lose()
{
    _life--;
    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 40; j++)
            if (_map[i][j] >= '!' && _map[i][j] < '%') {
                _score += ('%' - _map[i][j]) * 5;
                _map[i][j] = '%';
            }
    _toAppear = 10;
    while (_centipedes.size()) {
        _map[_centipedes[0][0]][_centipedes[0][1]] = ' ';
        _centipedes.erase(_centipedes.begin());
    }
    _map[_player[0]][_player[1]] = ' ';
    if (_lazer[0] >= 0)
        _map[_lazer[0]][_lazer[1]] = ' ';
    _map[38][20] = 'P';
    _lazer[0] = -1;
    _player = {38, 20};
    return _map;
}
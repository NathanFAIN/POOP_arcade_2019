/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Info
*/

#include "../include/Info.hpp"

Info::Info()
{
}

Info::~Info()
{
}

struct less_than_score
{
    inline bool operator() (const Score &score1, const Score &score2)
    {
        return (std::stoi(score1.getScore()) < std::stoi(score2.getScore()));
    }
};

void Info::addScore(const Score &score)
{
    this->_scoring.push_back(score);

    std::sort(this->_scoring.begin(), this->_scoring.end(), less_than_score());
}

const std::vector<Score> &Info::getScoring() const
{
    return this->_scoring;
}

void Info::setScoring(const std::string &file)
{
    //Parsing File
}

void Info::setGraphIdx(const int &idx)
{
    this->_graphIdx = idx;
}

void Info::setGameIdx(const int &idx)
{
    this->_gameIdx = idx;
}

void Info::setSide(const bool &side)
{
    this->_side = side;
}

int Info::getGraphIdx() const
{
    return this->_graphIdx;
}

int Info::getGameIdx() const
{
    return this->_gameIdx;
}

bool Info::getSide() const
{
    return this->_side;
}

const std::vector<std::string> &Info::getGraphNames() const
{
    return this->_graphNames;
}

const std::vector<std::string> &Info::getGameNames() const
{
    return this->_gameNames;
}

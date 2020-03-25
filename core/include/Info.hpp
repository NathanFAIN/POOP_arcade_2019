/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Info
*/

#ifndef INFO_HPP_
#define INFO_HPP_

#include <string>
#include <vector>
#include <algorithm>
#include "Score.hpp"

class Info {
    public:
        Info();
        ~Info();
        const std::vector<std::string> &getGraphNames() const;
        const std::vector<std::string> &getGameNames() const;
        int getGraphIdx() const;
        int getGameIdx() const;
        bool getSide() const;
        const std::vector<Score> &getScoring() const;
        void setGameIdx(const int &idx);
        void setGraphIdx(const int &idx);
        void setSide(const bool &side);
        void setScoring(const std::string &file);
        void addScore(const Score &score);
    
    protected:
    private:
        std::vector<std::string> _graphNames;
        std::vector<std::string> _gameNames;
        int _gameIdx;
        int _graphIdx;
        bool _side;
        std::vector<Score> _scoring;

};

#endif /* !INFO_HPP_ */

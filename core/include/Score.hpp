/*
** EPITECH PROJECT, 2020
** Score.hpp
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include <string>

class Score {
    public:
        Score(std::string name, std::string score = 0);
        ~Score();
        const std::string &getName() const;
        const std::string &getScore() const;
    protected:
    private:
        std::string _name;
        std::string _score;
};

#endif /* !SCORE_HPP_ */

/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** InitTab
*/

#ifndef INITTAB_HPP_
#define INITTAB_HPP_

#include <string>
#include <vector>

class InitTab {
    public:
        InitTab(char c, int iC, int oC, const std::string &str) {_c=c; _inColor=iC; _outColor=oC; _path=str;};
        ~InitTab() = default;
        char getCharacter() const {return this->_c;};
        int getInColor() const {return this->_inColor;};
        int getOutColor() const {return this->_outColor;};
        const std::string &getPath() const {return this->_path;};

    private:
        char _c;
        int _inColor;
        int _outColor;
        std::string _path;
};

#endif /* !INITTAB_HPP_ */

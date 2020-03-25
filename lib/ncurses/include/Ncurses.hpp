/*
** EPITECH PROJECT, 2018
** Ncurses.hpp
** File description:
** my personal Ncurses include file
*/

#ifndef NCURSES_H_
#define NCURSES_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include <string>
#include <dlfcn.h>
#include <iostream>

#ifdef __NCURSES_H

#define KEY_DOWN_N 258
#define KEY_UP_N 259
#define KEY_LEFT_N 260
#define KEY_RIGHT_N 261

#undef KEY_UP
#undef KEY_DOWN
#undef KEY_LEFT
#undef KEY_RIGHT
#endif

#include "IGraphics.hpp"
#include "InitTab.hpp"

extern "C" void NcursesConstructor(void) __attribute__((constructor));
extern "C" void NcursesDestructor(void) __attribute__((destructor));

#define NCURSES_SIZE_X 10
#define NCURSES_SIZE_Y 10
#define KEY_ESC_N 27

class Ncurses : public IGraphics {
	public:
		Ncurses();
		~Ncurses();
        void displayGame(const std::vector<std::vector<char>> &);
        void init(const std::vector<InitTab> &);
		void setScore(const std::string &);
        void setLife(const std::string &);
        Input getInput(void) const;
	protected:
	private:
		void createWindow(const size_t &x, const size_t &y);
		struct NcursesInput {
			Input input;
			int key;
		};
		WINDOW *_window;
		WINDOW *_windowInfo;
		std::string _score;
		std::string _life;
		size_t _xSize;
		size_t _ySize;
};

#endif

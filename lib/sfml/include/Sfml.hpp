/*
** EPITECH PROJECT, 2018
** Sfml.hpp
** File description:
** my personal Sfml include file
*/

#ifndef SFML_H_
#define SFML_H_

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
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include <string>
#include <dlfcn.h>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "IGraphics.hpp"
#include "InitTab.hpp"

#define SFML_DEFAULT_SIZE_X 1280
#define SFML_DEFAULT_SIZE_Y 720

extern "C" void SfmlConstructor(void) __attribute__((constructor));
extern "C" void SfmlDestructor(void) __attribute__((destructor));

class Sfml : public IGraphics {
	public:
		Sfml();
		~Sfml();
        void displayGame(const std::vector<std::vector<char>> &);
        void init(const std::vector<InitTab> &);
		void setScore(const std::string &);
        void setLife(const std::string &);
        Input getInput(void) const;
	protected:
	private:
		void createWindow(const size_t &xSize, const size_t &ySize);
		void rescale(void);
		struct SfmlInput {
			Input input;
			sf::Keyboard::Key key;
		};
		std::map<char, sf::Texture> _texture;
		std::map<char, sf::Sprite> _sprite;
		sf::RenderWindow *_window;
		std::string _score;
		std::string _life;
		sf::Text _scoreText;
		sf::Text _lifeText;
		size_t _xSize;
		size_t _ySize;
		double _blockScale;
		sf::Font _font;
};

#endif

/*
** EPITECH PROJECT, 2020
** lib_ncurses
** File description:
** Ncurses
*/

#include "Sfml.hpp"

extern "C" void SfmlConstructor(void)
{
    std::cout << "Sfml library launched." << std::endl;
}

extern "C" void SfmlDestructor(void)
{
    std::cout << "Sfml library left." << std::endl;
}

extern "C" IGraphics *createIGraphics()
{
    return new Sfml;
}

extern "C" void destroyIGraphics(IGraphics *object)
{
    delete object;
}

Sfml::Sfml()
{
    this->_life = "";
    this->_score = "";
    this->_window = nullptr;
}

Sfml::~Sfml()
{
    if (this->_window)
        delete this->_window;
}

void Sfml::displayGame(const std::vector<std::vector<char>> &map)
{
    sf::Vector2f pos = {0, 0};
    sf::Event event;

    while (this->_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->_window->close();
            return;
        }
    }
    this->_window->clear(sf::Color::Black);
    for (std::vector<char> mapRow : map) {
        pos.x = 0;
        for (char c : mapRow) {
            this->_sprite[c].setPosition(pos);
            this->_window->draw(this->_sprite[c]);
            pos.x += this->_texture[c].getSize().x * this->_sprite[c].getScale().x;
        }
        pos.y += this->_texture[mapRow[0]].getSize().y * this->_sprite[mapRow[0]].getScale().y;
    }
    this->_window->display();
}

void Sfml::createWindow(const size_t &xSize, const size_t &ySize)
{
    if (this->_window)
        delete this->_window;
    this->_window = new sf::RenderWindow(sf::VideoMode(xSize, ySize), "Arcade");
}

void Sfml::init(const std::vector<InitTab> &tab)
{
    sf::Texture texture;
    sf::Sprite sprite;

    for (auto i = tab.begin(); i != tab.end(); i++) {
        this->_texture[i->getCharacter()].loadFromFile(i->getPath());
        this->_sprite[i->getCharacter()].setTexture(this->_texture[i->getCharacter()]);
        this->_sprite[i->getCharacter()].setScale(30.f / this->_texture[i->getCharacter()].getSize().x, 30.f / this->_texture[i->getCharacter()].getSize().y);
    }
    createWindow(SFML_SIZE_X, SFML_SIZE_Y);
}

void Sfml::setScore(const std::string &score)
{
    this->_score = score;
}

void Sfml::setLife(const std::string &life)
{
    this->_life = life;
}

Input Sfml::getInput(void) const
{
    static Sfml::SfmlInput ncursesInput[] = {{KEY_UP, sf::Keyboard::Up}, {KEY_DOWN, sf::Keyboard::Down}, \
                                            {KEY_LEFT, sf::Keyboard::Left}, {KEY_RIGHT, sf::Keyboard::Right}, \
                                            {EXIT, sf::Keyboard::Escape}, {PREV_GAME, sf::Keyboard::Num1}, \
                                            {NEXT_GAME, sf::Keyboard::Num2}, {PREV_GRAPH, sf::Keyboard::Num3}, \
                                            {NEXT_GRAPH, sf::Keyboard::Num4}};

    if (!this->_window->isOpen())
        return EXIT;
    for (size_t index = 0; index != sizeof(ncursesInput) / sizeof(*ncursesInput); index++)
        if (sf::Keyboard::isKeyPressed(ncursesInput[index].key))
            return ncursesInput[index].input;
    return NONE;
}
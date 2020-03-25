/*
** EPITECH PROJECT, 2020
** lib_ncurses
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

extern "C" void NcursesConstructor(void)
{
    std::cout << "Ncurses library launched." << std::endl;
}

extern "C" void NcursesDestructor(void)
{
    std::cout << "Ncurses library left." << std::endl;
}

extern "C" IGraphics *createIGraphics()
{
    return new Ncurses;
}

extern "C" void destroyIGraphics(IGraphics *object)
{
    delete object;
}

Ncurses::Ncurses()
{
    this->_life = "";
    this->_score = "";
    this->_window = nullptr;
    this->_windowInfo = nullptr;
    this->_xSize = 0;
    this->_ySize = 0;
}

Ncurses::~Ncurses()
{
    clear();
    delwin(this->_window);
    endwin();
}

void Ncurses::displayGame(const std::vector<std::vector<char>> &map)
{
    size_t xMax = getmaxx(stdscr);
    size_t yMax = getmaxy(stdscr);
    static size_t x = xMax;
    static size_t y = yMax;

    if (yMax <= this->_ySize + 4 || xMax <= this->_xSize) {
        if (this->_window) {
            delwin(this->_window);
            this->_window = nullptr;
        }
        clear();
        move(yMax / 2, xMax / 2 - 8);
        printw("TOO SMALL WINDOW\n");
        refresh();
        x = xMax;
        y = yMax;
        return;
    } else if (map.size() + 1 != this->_ySize || map[0].size() + 1 != this->_xSize) {
        this->createWindow(map.size() + 1, map[0].size() + 1);
    }
    if (!this->_window)
        this->createWindow(map.size() + 1, map[0].size() + 1);
    wmove(this->_window, 0, 0);
    mvwin(this->_window, yMax / 2 - this->_ySize / 2 + 1, xMax / 2 - this->_xSize + 1);
    for (std::vector<char> mapRow : map) {
        for (char c : mapRow) {
            wattron(this->_window, COLOR_PAIR(c));
            wprintw(this->_window, "  ");
            wattroff(this->_window, COLOR_PAIR(c));
        }
        wprintw(this->_window, "\n");
    }
    mvwin(this->_windowInfo, 0, 0);
    mvwprintw(this->_windowInfo, 1, 1, "Score: %s", this->_score.c_str());
    mvwprintw(this->_windowInfo, 2, 1, "Life : %s", this->_life.c_str());
    wrefresh(this->_window);
    wrefresh(this->_windowInfo);
    refresh();
    if (yMax != y || xMax !=  x)
        clear();
    x = xMax;
    y = yMax;
}

void Ncurses::createWindow(const size_t &x, const size_t &y)
{
    noecho();
    set_escdelay(0);
    curs_set(FALSE);
    this->_xSize = x;
    this->_ySize = y;
    if (this->_window)
        delwin(this->_window);
    if (this->_windowInfo)
        delwin(this->_windowInfo);
    this->_window = newwin(this->_ySize, this->_xSize * 2, 0, 0);
    this->_windowInfo = newwin(4, 14, 0, 0);
    wmove(this->_windowInfo, 0, 0);
    box(this->_windowInfo, ACS_VLINE, ACS_HLINE);
    wmove(this->_window, 0, 0);
    nodelay(this->_window, TRUE);
    keypad(this->_window, TRUE);
    notimeout(this->_window, FALSE);
}

void Ncurses::init(const std::vector<InitTab> &tab)
{
    initscr();
    start_color();
    for (auto i = tab.begin(); i != tab.end(); i++)
        init_pair(i->getCharacter(), i->getInColor(), i->getOutColor());
    this->createWindow(NCURSES_SIZE_X, NCURSES_SIZE_Y);
}

void Ncurses::setScore(const std::string &score)
{
    this->_score = score;
}

void Ncurses::setLife(const std::string &life)
{
    this->_life = life;
}

Input Ncurses::getInput(void) const
{
    int key = wgetch(this->_window);
    static Ncurses::NcursesInput ncursesInput[] =   {{KEY_UP, KEY_UP_N}, {KEY_DOWN, KEY_DOWN_N}, \
                                                    {KEY_LEFT, KEY_LEFT_N}, {KEY_RIGHT, KEY_RIGHT_N}, \
                                                    {EXIT, KEY_ESC_N}, {PREV_GAME, '&'}, {NEXT_GAME, 195}, \
                                                    {PREV_GRAPH, '"'}, {NEXT_GRAPH, '\''}};

    for (size_t index = 0; index != sizeof(ncursesInput) / sizeof(*ncursesInput); index++)
        if (ncursesInput[index].key == key)
            return ncursesInput[index].input;
    return NONE;
}
#ifndef BOARD_H
#define BOARD_H
#include "console.h"
/*
 * Cette classe représente l'othellier
 * Le plateau de jeu
 * il est composé de 64 cases 8*8
*/

class Board
{
    public:
        Board();
        ~Board();
        void m_set(unsigned int li, unsigned int col, char a);
        void m_play();
        void m_reset();
        void m_display();
        void m_put(char mov,int m_x,int m_y);
        void m_cursor(char mov);
        void m_clean();
        bool isPlacementOK(int m_x,int m_y);
    private:
        char tab[8][8];
        unsigned int m_x;
        unsigned int m_y;
        unsigned int pre_x;
        unsigned int pre_y;
        char pre_c;
        Console* p_console;
};

#endif // BOARD_H

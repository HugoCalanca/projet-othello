#ifndef BOARD_H
#define BOARD_H
#include "console.h"
#include "Player.h"
#include "Coup.h"
#include <vector>
#include <set>
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
        void set_pion();
        //surcharge de fonction
        void set_pion(unsigned int col, unsigned int lig);
        void flip_pion();
        void m_play();
        void m_play(bool ia);
        void m_reset();
        void m_display();
        void m_put();
        void m_cursor(char mov);
<<<<<<< HEAD
        //remplie la liste de coups jouable
        void set_possibilites();
        //accesseurs des coordonnées du curseur
        unsigned int get_x();
        unsigned int get_y();
        void set_x(unsigned int x);
        void set_y(unsigned int y);


        void Begin(int choice);
        void Bouclejeu();
        void Bouclejeu2();
        bool isSquareOK();
        bool isCoupjouable(int col, int lig);
        void resetList();
        void Winner();
        //caractère représentant les pions des joueurs 1&2
        char j1;
        char j2;
        //liste des coups jouable
=======
        void m_flip(unsigned int m_x, unsigned int m_y, char allie, char adverse);
        void Begin(int choice);
        void Bouclejeu();
        void Bouclejeu2();
        bool isSquareOK(int m_x, int m_y);
        bool isCoupjouable(int col, int lig);
        void resetList();
        void Winner();
        Player p1;
        Player p2;
        IA ia;
>>>>>>> origin/master
        vector<Coup> m_listCoup;
        char tab[8][8];
    private:
        unsigned int m_x;
        unsigned int m_y;
        Board* pre_n;
        vector<Board*> suc_n;
        Console* p_console;
        bool m_over;
        unsigned int m_tour;
};

#endif // BOARD_H

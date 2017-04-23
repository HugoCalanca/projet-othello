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
        //fonction qui joue le coups sans l'afficher pour l'ia
        void m_put(bool ia);
        void m_cursor(char mov);
        //remplie la liste de coups jouable
        void set_possibilites();
        //accesseurs des coordonnées du curseur
        unsigned int get_x();
        unsigned int get_y();
        void set_x(unsigned int x);
        void set_y(unsigned int y);

        vector<Board> get_suc_n();

        void Begin(int choice);
        void Bouclejeu();
        void Bouclejeu2();
        bool isSquareOK();
        bool isCoupjouable(int col, int lig);
        void resetList();
        bool isBoardfull();
        void Winner();
        //caractère représentant les pions des joueurs 1&2
        char j1;
        char j2;
        //liste des coups jouable
        vector<Coup> m_listCoup;
        char tab[8][8];
        void Save();
        void Load();
        void regle();
    private:
        unsigned int m_x;
        unsigned int m_y;
        Board* pre_n;
        vector<Board> suc_n;
        Console* p_console;
        bool m_over;
        unsigned int m_tour;
};

#endif // BOARD_H

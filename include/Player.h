#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <set>
#include "Coup.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <utility>

using namespace std;

class Player
{
    public:
        Player();
        Player(string m_name,char m_symbol);
        ~Player();
        string getName();
        char getSymbol();
        void setname(string s);
        void setsymbol(char a);
        void setnpion(unsigned int i);
        unsigned int getnpion(char tab[8][8]);
        void get_possibilites(char tab[8][8], char adverse, vector<Coup>& listCoup);
        void set_pion(int col, int lig, char tab[8][8]);
        void flip_pion(unsigned int m_x, unsigned int m_y, char adverse, char tab[8][8]);

    protected:
        string m_name;
        char m_symbol;
        unsigned int m_nbpion;
        bool m_win;

    private:
};

#endif // PLAYER_H

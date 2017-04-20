#ifndef IA_H
#define IA_H
#include "Player.h"

class IA
{
    public:
        IA();
        ~IA();
        void simulation(char tab[8][8], Player& adverse, vector<Coup>& listCoup, int deep);
        void reset(unsigned int x, unsigned int y, char tab[8][8]);
        int Min(char tab_simu[8][8], vector<Coup>& listCoup, int deep);
        int Max(char tab_simu[8][8], vector<Coup>& listCoup, int deep);
        int eval(char tab_simu[8][8]);
        void Random(unsigned int& m_x, unsigned int& m_y,vector<Coup> m_listCoup);
        void Heuristique();
    protected:
};

#endif // IA_H

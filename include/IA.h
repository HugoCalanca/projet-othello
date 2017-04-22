#ifndef IA_H
#define IA_H
#include "Board.h"
#include <Board.h>
#include <utility>
#include <vector>
class IA
{
    public:
        IA();
        ~IA();
        void reset(unsigned int x, unsigned int y, char tab[8][8]);
<<<<<<< HEAD
        int Min();
        int Max();
        int eval(Board n_f);
        pair<unsigned int, unsigned int> Random(vector<Coup> m_listCoup);
        pair<unsigned int, unsigned int> create_children(Board plateau);
=======
        int Min(char tab_simu[8][8], vector<Coup>& listCoup, int deep);
        int Max(char tab_simu[8][8], vector<Coup>& listCoup, int deep);
        int eval(char tab_simu[8][8]);
        void Random(unsigned int& m_x, unsigned int& m_y,vector<Coup> m_listCoup);
        void Heuristique();
>>>>>>> origin/master
    protected:
};

#endif // IA_H

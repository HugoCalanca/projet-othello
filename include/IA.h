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
        int Min(Board& n, int deep);
        int Max(Board& n, int deep);
        int eval(Board& n_f);
        pair<unsigned int, unsigned int> Random(vector<Coup> m_listCoup);
        pair<unsigned int, unsigned int> minimax(Board& plateau, int deep);
        //minimax avec alpha beta
        pair<unsigned int, unsigned int> minimax(Board& plateau, int a, int b, int deep);
        void create_child(Board& n, int deep);
        void create_tree(Board& n, int deep);
        int AB(Board& n, int a, int b, int deep);
=======
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
>>>>>>> origin/master
    protected:
};

#endif // IA_H

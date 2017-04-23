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
    protected:
};

#endif // IA_H

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
        int Min();
        int Max();
        int eval(Board n_f);
        pair<unsigned int, unsigned int> Random(vector<Coup> m_listCoup);
        pair<unsigned int, unsigned int> create_children(Board plateau);
    protected:
};

#endif // IA_H

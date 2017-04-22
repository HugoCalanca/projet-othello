#include "IA.h"
#include "Coup.h"
#include <vector>
#include <queue>
#include "time.h"
#include "Node.h"
#include "random"
#include "Board.h"

IA::IA()
{
    //ctor
}

IA::~IA()
{
    //dtor
}



pair<unsigned int, unsigned int> IA::Random(vector<Coup> m_listCoup)
{
    int num;
    pair<unsigned int, unsigned int> p;


    srand(time(NULL));

    num=rand()%m_listCoup.size();

    p.first = m_listCoup[num].m_first;
    p.second = m_listCoup[num].m_second;

    return p;
}



pair<unsigned int, unsigned int> IA::create_children(Board plateau)
{
    //on créé une copie du plateau actuel pour créer le noeud racine
    Board n_rac(plateau);
    //on trouve tous les coups possibles pour cette configuration
    n_rac.set_possibilites();
    //Pour tous les coups possible dans cette configuration
    for(int i = 0; i < n_rac.m_listCoup.size(); i++)
    {
        n_rac.set_x(n_rac.m_listCoup[i].m_first);
        n_rac.set_y(n_rac.m_listCoup[i].m_second);
        n_rac.m_put();
        n_rac.resetList();
    }
}


void IA::reset(unsigned int x, unsigned int y, char tab[8][8])
{
    tab[x][y] = 223;
}


int IA::Min()
{

}


int IA::Max()
{

}

int IA::eval(Board n_f)
{

int val_j1 = 0;
int val_j2 = 0;
int val_fin = 0;
int tab[8][8] = {120, -20, 20,  5,  5, 20, -20, 120,
                     -20, -40, -5, -5, -5, -5, -40, -20,
                     20,  -5, 15,  3,  3, 15,  -5,  20,
                     5,  -5,  3,  3,  3,  3,  -5,   5,
                     5,  -5,  3,  3,  3,  3,  -5,   5,
                     20,  -5, 15,  3,  3, 15,  -5,  20,
                     -20, -40, -5, -5, -5, -5, -40, -20,
                     120, -20, 20,  5,  5, 20, -20, 120
                    };

for(int i = 0; i < 8; i++)
{
    for(int j =0; j < 8; j++)
    {
        if(n_f.tab[i][j] == n_f.j1)
        {
            val_j1 = val_j1 + tab[i][j];
        }
        else if(n_f.tab[i][j] == n_f.j2)
        {
            val_j2 = val_j2 + tab[i][j];
        }
    }
}
    val_fin = val_j1 - val_j2;
    return val_fin;
}

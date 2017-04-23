#include "IA.h"
#include "Coup.h"
#include <vector>
#include <queue>
#include "time.h"
#include "Node.h"
#include "random"
#include "Board.h"
#include <fstream>

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



pair<unsigned int, unsigned int> IA::minimax(Board& plateau, int deep)
{
    int max_val = -1000;
    int tmp;
    pair<unsigned int, unsigned int> p;
    //on créé une copie du plateau actuel pour créer le noeud racine
    Board n_rac(plateau);
    //on trouve tous les coups possibles pour cette configuration
    n_rac.set_possibilites();
    //Pour tous les coups possible dans cette configuration
    for(int i = 0; i < n_rac.m_listCoup.size(); i++)
    {
        n_rac.set_x(n_rac.m_listCoup[i].m_first);
        n_rac.set_y(n_rac.m_listCoup[i].m_second);
        n_rac.m_put(true);
        //on envoie a Min() le noeud fils
        tmp = Max(n_rac, deep-1);

        if(tmp > max_val)
        {
            max_val = tmp;
            p.first = n_rac.m_listCoup[i].m_first;
            p.second = n_rac.m_listCoup[i].m_second;

        }

 /*       //on créé un noeud fils
        Board n_fils = n_rac;
        //on reprend le noeud racine
        n_rac = plateau;
        //et on lui assigne son nouveau fils
        n_rac.get_suc_n().push_back(n_fils);*/
    }

    return p;

}



pair<unsigned int, unsigned int> IA::minimax(Board& plateau, int a, int b, int deep)
{
    int max_val = -1000;
    int tmp;
    pair<unsigned int, unsigned int> p;
    //on créé une copie du plateau actuel pour créer le noeud racine
    Board n_rac(plateau);
    //on trouve tous les coups possibles pour cette configuration
    n_rac.set_possibilites();
    //Pour tous les coups possible dans cette configuration
    for(int i = 0; i < n_rac.m_listCoup.size(); i++)
    {
        n_rac.set_x(n_rac.m_listCoup[i].m_first);
        n_rac.set_y(n_rac.m_listCoup[i].m_second);
        n_rac.m_put(true);
        //on envoie a Min() le noeud fils
        tmp = AB(n_rac, a, b, deep);

        if(tmp > max_val)
        {
            max_val = tmp;
            p.first = n_rac.m_listCoup[i].m_first;
            p.second = n_rac.m_listCoup[i].m_second;

        }

 /*       //on créé un noeud fils
        Board n_fils = n_rac;
        //on reprend le noeud racine
        n_rac = plateau;
        //et on lui assigne son nouveau fils
        n_rac.get_suc_n().push_back(n_fils);*/
    }

    return p;

}

void IA::create_child(Board& n, int deep)
{
    if(deep != 0)
    {
        //on créé une copie du plateau actuel pour créer le noeud racine
        Board n_rac(n);
        //on trouve tous les coups possibles pour cette configuration
        n_rac.set_possibilites();
        //Pour tous les coups possible dans cette configuration
        for(int i = 0; i < n_rac.m_listCoup.size(); i++)
        {
            n_rac.set_x(n_rac.m_listCoup[i].m_first);
            n_rac.set_y(n_rac.m_listCoup[i].m_second);
            n_rac.m_put(true);

            //on créé un noeud fils
            Board n_fils = n_rac;
            //on reprend le noeud racine
            n_rac = n;
            //et on lui assigne son nouveau fils
            n_rac.get_suc_n().push_back(n_fils);
        }
    }
}

void IA::create_tree(Board& n, int deep)
{
    for(auto& elem : n.get_suc_n())
    {
        this->create_child(elem, deep);
        deep--;
    }
}

int IA::AB(Board& n, int a, int b, int deep)
{
    if(deep == 0 || n.m_listCoup.empty())
    {
        return eval(n);
    }
    else
    {
        this->create_tree(n, deep);
        int best = -1000;
        for(int i = 0; i < n.get_suc_n().size(); i++)
        {
            int val = - AB(n.get_suc_n()[i], -b, -a, deep-1);
            if(val > best)
            {
                best = val;
                if(best > a)
                {
                    a = best;

                    if(a >= b)
                    {
                        return best;
                    }
                }
            }
        }
        return best;
    }
}

void IA::reset(unsigned int x, unsigned int y, char tab[8][8])
{
    tab[x][y] = 223;
}


int IA::Max(Board& n, int deep)
{
    if(deep == 0 || n.m_listCoup.empty())
    {
        return eval(n);
    }

    int max_val = -1000;
    int tmp;

    for(int i = 0; i < n.m_listCoup.size(); i++)
    {
        n.set_x(n.m_listCoup[i].m_first);
        n.set_y(n.m_listCoup[i].m_second);
        n.m_put(true);
        //on envoie a Min() le noeud fils
        tmp = Max(n, deep-1);

        if(tmp > max_val)
        {
            max_val = tmp;
        }
    }

    return max_val;
}


int IA::Min(Board& n, int deep)
{
    if(deep == 0 || n.m_listCoup.empty())
    {
        return eval(n);
    }

    int min_val = 1000;
    int tmp;

    for(int i = 0; i < n.m_listCoup.size(); i++)
    {
        n.set_x(n.m_listCoup[i].m_first);
        n.set_y(n.m_listCoup[i].m_second);
        n.m_put(true);
        //on envoie a Max() le noeud fils
        tmp = Max(n, deep-1);

        if(tmp > min_val)
        {
            min_val = tmp;
        }
    }

    return min_val;
}

int IA::eval(Board& n_f)
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

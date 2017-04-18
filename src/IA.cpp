#include "IA.h"
#include "Coup.h"
#include <vector>

IA::IA()
{
    //ctor
}

IA::~IA()
{
    //dtor
}


void IA::reset(unsigned int x, unsigned int y, char tab[8][8])
{
    tab[x][y] = 223;
}

void IA::simulation(char tab[8][8], Player& adverse, vector<Coup>& listCoup, int deep)
{
    char tab_simu[8][8];

    //on créé un tableau pour simuler les coups
    for(unsigned int i = 0; i < 7; i++)
    {
        for(unsigned int j = 0; j <7; j++)
        {
            tab_simu[i][j] = tab[i][j];
        }
    }
    //this->get_possibilites(tab, adverse.getSymbol(), listCoup);
    //pour chaque coups possible pour l'IA
    for(unsigned int i = 0; i < listCoup.size(); i++)
    {

    }

}


int IA::Min(char tab_simu[8][8], vector<Coup>& listCoup, int deep)
{
    if(deep == 0)
    {
        return eval(tab_simu);
    }
    int minimum = 10000;
    int tmp;
    for(unsigned int i = 0; i < listCoup.size(); i++)
    {
        //this->set_pion(listCoup[i].m_first, listCoup[i].m_second, tab_simu);
        tmp = Max(tab_simu, listCoup, deep-1);

        if(tmp < minimum)
        {
            minimum = tmp;
        }
        this->reset(listCoup[i].m_first, listCoup[i].m_second, tab_simu);
    }

    return minimum;
}


int IA::Max(char tab_simu[8][8], vector<Coup>& listCoup, int deep)
{
    if(deep == 0)
    {
        return eval(tab_simu);
    }
    int maximum = 10000;
    int tmp;
    for(unsigned int i = 0; i < listCoup.size(); i++)
    {
        //this->set_pion(listCoup[i].m_first, listCoup[i].m_second, tab_simu);
        tmp = Max(tab_simu, listCoup, deep-1);

        if(tmp < maximum)
        {
            maximum = tmp;
        }
        this->reset(listCoup[i].m_first, listCoup[i].m_second, tab_simu);
    }

    return maximum;
}

int IA::eval(char tab_simu[8][8])
{
    int nbtot_pion = 0;

    for(unsigned int i = 0; i < 7; i++)
    {
        for(unsigned int j = 0; j < 7; j++)
        {
            if(tab_simu[i][j] != 223)
            {
                nbtot_pion++;
            }
        }
    }
    if(1/*this->getnpion(tab_simu) > nbtot_pion - this->getnpion(tab_simu)*/)
    {
        //return 1000 - this->getnpion(tab_simu);
    }
    else
    {
        //return -1000 + this->getnpion(tab_simu);
    }

}

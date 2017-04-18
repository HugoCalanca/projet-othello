#include "Player.h"
#include <set>
#include "Coup.h"



Player::Player()
{
    //ctor
}

Player::Player(string m_name,char m_symbol)
        :m_name(m_name), m_symbol(m_symbol), m_nbpion(2), m_win(false)
{
    //ctor
}

Player::~Player()
{
    //dtor
}

string Player::getName()
{
    return this->m_name;
}

char Player::getSymbol()
{
    return this->m_symbol;
}

void Player::setname(string s)
{
    this->m_name = s;
}

void Player::setsymbol(char a)
{
    this->m_symbol = a;
}

void Player::setnpion(unsigned int i)
{
    this->m_nbpion = i;
}

void Player::get_possibilites(char tab[8][8], char adverse, vector<Coup>& listCoup)
{
    unsigned int col = 0;
    unsigned int lig = 0;
    for(unsigned int i= 0; i <8; i++)
    {
        for(unsigned int j=0; j <8; j++)
        {
            if(tab[i][j]== this->m_symbol)
            {
                if(tab[i+1][j] == adverse) // si ya un ennemi à droite
                {
                    col = i+1;
                    lig = j;
                    while( tab[col][lig] == adverse)
                    {
                        col++;
                    }
                    if(tab[col][lig]== this->m_symbol || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        listCoup.push_back(c);
                    }
                }
                if(tab[i-1][j]==adverse) // si ya un ennemi à gauche
                {
                    col = i-1;
                    lig = j;
                    while( tab[col][lig] == adverse)
                    {
                        col--;
                    }
                    if(tab[col][lig]== this->m_symbol || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        listCoup.push_back(c);
                    }
                }
                if(tab[i][j-1]==adverse) // si ya un ennemi en haut
                {
                    col = i;
                    lig = j-1;
                    while( tab[col][lig] == adverse)
                    {
                        lig--;
                    }
                    if(tab[col][lig]== this->m_symbol || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        listCoup.push_back(c);
                    }
                }
                if(tab[i][j+1]==adverse) // si ya un ennemi en bas
                {
                    col = i;
                    lig = j+1;
                    while(tab[col][lig] == adverse)
                    {
                        lig++;
                    }
                    if(tab[col][lig]== this->m_symbol || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        listCoup.push_back(c);
                    }
                }
                if(tab[i+1][j+1]==adverse) // si ya un ennemi en bas à droite
                {
                    col = i+1;
                    lig = j+1;
                    while( tab[col][lig] == adverse)
                    {
                        col++;
                        lig++;
                    }
                    if(tab[col][lig]== this->m_symbol || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        listCoup.push_back(c);
                    }
                }
                if(tab[i+1][j-1]==adverse) // si ya un ennemi en haut à droite
                {
                    col = i+1;
                    lig = j-1;
                    while( tab[col][lig] == adverse)
                    {
                        col++;
                        lig--;
                    }
                    if(tab[col][lig]== this->m_symbol || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        listCoup.push_back(c);
                    }
                }
                if(tab[i-1][j-1]==adverse) // si ya un ennemi en haut à gauche
                {
                    col = i-1;
                    lig = j-1;
                    while( tab[col][lig] == adverse)
                    {
                        col--;
                        lig--;
                    }
                    if(tab[col][lig]== this->m_symbol || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        listCoup.push_back(c);
                    }
                }
                if(tab[i-1][j+1]==adverse) // si ya un ennemi en bas à gauche
                {
                    col = i-1;
                    lig = j+1;
                    while(tab[col][lig] == adverse)
                    {
                        col--;
                        lig++;
                    }
                    if(tab[col][lig]== this->m_symbol || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        listCoup.push_back(c);
                    }
                }
            }
        }
    }
}

unsigned int Player::getnpion(char tab[8][8])
{
    for(unsigned int i = 0; i < 7; i++)
    {
        for(unsigned int j = 0; j < 7; j++)
        {
            if(tab[i][j] == this->getSymbol())
                this->m_nbpion++;
        }
    }
    return this->m_nbpion;
}

void Player::set_pion(int col, int lig, char tab[8][8])
{
    tab[col][lig] = this->getSymbol();
}



void Player::flip_pion(unsigned int m_x, unsigned int m_y, char adverse, char tab[8][8])
{
    if(tab[m_x+1][m_y] == adverse)
    {
        unsigned int i = m_x+1;
        unsigned int j = m_y;
        while(tab[i][j] == adverse && tab[i][j] != this->m_symbol)
        {
            i++;
        }
        if(tab[i][j] == this->m_symbol)
        {
            while( i != m_x)
            {
                i--;
                this->set_pion(i, j, tab);
            }
        }
    }
    if(tab[m_x-1][m_y] == adverse)
    {
        unsigned int i = m_x-1;
        unsigned int j = m_y;
        while(tab[i][j] == adverse && tab[i][j] != this->m_symbol)
        {
            i--;
        }
        if(tab[i][j] == this->m_symbol)
        {
            while( i != m_x)
            {
                i++;
                this->set_pion(i, j, tab);
            }
        }
    }
    if(tab[m_x][m_y+1] == adverse)
    {
        unsigned int i = m_x;
        unsigned int j = m_y+1;
        while(tab[i][j] == adverse && tab[i][j] != this->m_symbol)
        {
            j++;
        }
        if(tab[i][j] == this->m_symbol)
        {
            while( j != m_y)
            {
                j--;
                this->set_pion(i, j, tab);
            }
        }
    }
    if(tab[m_x][m_y-1] == adverse)
    {
        unsigned int i = m_x;
        unsigned int j = m_y-1;
        while(tab[i][j] == adverse && tab[i][j] != this->m_symbol)
        {
            j--;
        }
        if(tab[i][j] == this->m_symbol)
        {
            while( j != m_y)
            {
                j++;
                this->set_pion(i, j, tab);
            }
        }
    }
    if(tab[m_x+1][m_y+1] == adverse)
    {
        unsigned int i = m_x+1;
        unsigned int j = m_y+1;
        while(tab[i][j] == adverse && tab[i][j] != this->m_symbol)
        {
            i++;
            j++;
        }
        if(tab[i][j] == this->m_symbol)
        {
            while( i != m_x && j != m_y)
            {
                i--;
                j--;
                this->set_pion(i, j, tab);
            }
        }
    }
    if(tab[m_x+1][m_y-1] == adverse)
    {
        unsigned int i = m_x+1;
        unsigned int j = m_y-1;
        while(tab[i][j] == adverse && tab[i][j] != this->m_symbol)
        {
            i++;
            j--;
        }
        if(tab[i][j] == this->m_symbol)
        {
            while( i != m_x && j != m_y)
            {
                i--;
                j++;
                this->set_pion(i, j, tab);
            }
        }
    }
    if(tab[m_x-1][m_y+1] == adverse)
    {
        unsigned int i = m_x-1;
        unsigned int j = m_y+1;
        while(tab[i][j] == adverse && tab[i][j] != this->m_symbol)
        {
            i--;
            j++;
        }
        if(tab[i][j] == this->m_symbol)
        {
            while( i != m_x && j != m_y)
            {
                i++;
                j--;
                this->set_pion(i, j, tab);
            }
        }
    }
    if(tab[m_x-1][m_y-1] == adverse)
    {
        unsigned int i = m_x-1;
        unsigned int j = m_y-1;
        while(tab[i][j] == adverse && tab[i][j] != this->m_symbol)
        {
            i--;
            j--;
        }
        if(tab[i][j] == this->m_symbol)
        {
            while( i != m_x && j != m_y)
            {
                i++;
                j++;
                this->set_pion(i, j, tab);
            }
        }
    }
}

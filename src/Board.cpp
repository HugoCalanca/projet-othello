#include "Board.h"
#include "console.h"
#include "Player.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <utility>

using namespace std;

Board::Board()
{
    for(char i = 0; i < 8; i++)
    {
        for(char j = 0; j < 8; j++)
        {
            tab[i][j] = 223;
        }
    }

    tab[3][3] = 177;
    tab[4][4] = 177;
    tab[3][4] = 178;
    tab[4][3] = 178;
    this->p_console = Console::getInstance();
    this->p_console->setColor(COLOR_DEFAULT);
    this->m_x = 0;
    this->m_y = 0;
    this->pre_x = 0;
    this->pre_y = 0;
    this->pre_c = 223;
    this->m_over = false;
    this->m_tour = 1;
}

Board::~Board()
{
    //dtor
}

void Board::resetList()
{
    this->m_listCoup.erase(m_listCoup.begin(), m_listCoup.end());
}

void Board::Begin()
{
    string name1 = "Joueur1";
    string name2 = "Joueur2";
    char symbol_1 = 177 ;
    char symbol_2 = 178 ;
    this->p1.setname(name1);
    this->p1.setsymbol(symbol_1);
    this->p2.setname(name2);
    this->p2.setsymbol(symbol_2);
    p_console->setColor(COLOR_GREEN);
    cout<<name1 <<" : " <<symbol_1<<endl;
    p_console->setColor(COLOR_YELLOW);
    cout<<name2 <<" : " <<symbol_2 <<endl;
    p_console->setColor(COLOR_DEFAULT);
    system("PAUSE");
    system("cls");
    this->Bouclejeu();
}

bool Board::isCoupjouable(int col, int lig)
{
    for(const auto& elem : m_listCoup)
    {
        if(elem.m_first == col && elem.m_second == lig)
        {
            return true;
        }
    }
}

bool Board::isSquareOK(int m_x, int m_y)
{
    if(tab[m_x][m_y]== 177 || tab[m_x][m_y]== 178)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void Board::m_display()
{
    p_console->setColor(COLOR_DEFAULT);

    p_console->gotoLigCol(0*3 + 4, 3);
    p_console->setColor(COLOR_RED);
    cout << "A";
    p_console->gotoLigCol(1*3 + 4, 3);
    cout << "B";
    p_console->gotoLigCol(2*3 + 4, 3);
    cout << "C";
    p_console->gotoLigCol(3*3 + 4, 3);
    cout << "D";
    p_console->gotoLigCol(4*3 + 4, 3);
    cout << "E";
    p_console->gotoLigCol(5*3 + 4, 3);
    cout << "F";
    p_console->gotoLigCol(6*3 + 4, 3);
    cout << "G";
    p_console->gotoLigCol(7*3 + 4, 3);
    cout << "H";
    for(int i=0; i<8; i++)
    {
        p_console->gotoLigCol(2,i*6 + 8);
        cout << i+1;

    }
    p_console->setColor(COLOR_DEFAULT);

    for(char i = 0; i < 8; i++)
    {
        for(char j = 0; j < 8; j++)
        {
            if(i == m_x && j == m_y)
            {
                p_console->setColor(COLOR_RED);
            }
            else if(tab[i][j] == p1.getSymbol())
            {
                p_console->setColor(COLOR_GREEN);
            }
            else if(tab[i][j] == p2.getSymbol())
            {
                p_console->setColor(COLOR_YELLOW);
            }
            else if (isCoupjouable(i, j))
            {
                 p_console->setColor(COLOR_BLUE);
            }
            else
            {
             p_console->setColor(COLOR_DEFAULT);
            }
            p_console->gotoLigCol(i*3 + 4, j*6 + 8);
            cout<<tab[i][j]<< " ";
        }
        cout<<endl<<endl;
    }

    p_console->gotoLigCol(5,60);
    cout<< m_x << " " << m_y;
    p_console->gotoLigCol(7,60);
}

void Board::m_reset()
{
    for(char i = 0; i < 8; i++)
    {
        for(char j = 0; j < 8; j++)
        {
            tab[i][j] = 223;
        }
    }
}

void Board::m_play()
{

}

void Board::Bouclejeu()
{
    while(1)
    {
        if(this->m_tour % 2 == 0)
        {
            this->p2.get_possibilites(tab, this->p1.getSymbol(), m_listCoup);
        }
        else
        {
            this->p1.get_possibilites(tab, this->p2.getSymbol(), m_listCoup);
        }
        m_over= false;
        this->m_display();
        while(!m_over)
        {
            if(this->p_console->isKeyboardPressed())
            {
                char mov = this->p_console->getInputKey();
                this->m_cursor(mov);
                this->m_display();
            }
        }
        this->resetList();
    }
}

void Board::m_put(char mov, int m_x, int m_y)
{
    if(isSquareOK(m_x,m_y))
    {
        if(isCoupjouable(m_x, m_y))
        {
            if(this->m_tour % 2 == 0)
            {
                this->p2.set_pion(m_x, m_y, this->tab);
                this->p2.flip_pion(m_x, m_y, this->p1.getSymbol(), this->tab);
            }
            else
            {
                this->p1.set_pion(m_x, m_y, this->tab);
                this->p1.flip_pion(m_x, m_y, this->p2.getSymbol(), this->tab);
            }
            p_console->setColor(COLOR_YELLOW);
            p_console->gotoLigCol(m_x*3 + 4, m_y*6 + 8);
            cout<<this->tab[m_x][m_y];
            this->m_tour++;
            m_over= true;
        }
    }

}

void Board::m_cursor(char mov)
{
    switch(mov)
    {
    case 'z':

        m_x--;
        break;

    case 's':


        m_x++;
        break;

    case 'd':

        m_y++;
        break;

    case 'q':

        m_y--;
        break;

    case 32:
        this->m_put(mov,m_x,m_y);
        break;

    default:
        m_x = m_x;
        m_y = m_y;
        pre_x = pre_x;
        pre_y = pre_y;
        break;
    }
    if( m_x > 7)
    {
        m_x = 7;
    }
    if(m_x < 0)
    {
        m_x = 0;
    }
    if( m_y > 7)
    {
        m_y = 7;
    }
    if(m_y < 0)
    {
        m_y = 0;
    }
}

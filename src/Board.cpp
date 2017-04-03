#include "Board.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>

const wchar_t KEY_UP = 24;
const wchar_t KEY_DOWN = 25;
const wchar_t KEY_LEFT = 27;
const wchar_t KEY_RIGHT = 26;



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

    this->p_console = Console::getInstance();
    this->p_console->setColor(COLOR_DEFAULT);
    this->m_x = 0;
    this->m_y = 0;
    this->pre_x = 0;
    this->pre_y = 0;
    this->pre_c = 223;
}

Board::~Board()
{
    //dtor
}

void Board::m_display()
{

    Console* pConsole = NULL;
    pConsole = Console::getInstance();
    pConsole->setColor(COLOR_DEFAULT);

    pConsole->gotoLigCol(0*3 + 4, 3);
    pConsole->setColor(COLOR_RED);
    cout << "A";
    pConsole->gotoLigCol(1*3 + 4, 3);
    cout << "B";
    pConsole->gotoLigCol(2*3 + 4, 3);
    cout << "C";
    pConsole->gotoLigCol(3*3 + 4, 3);
    cout << "D";
    pConsole->gotoLigCol(4*3 + 4, 3);
    cout << "E";
    pConsole->gotoLigCol(5*3 + 4, 3);
    cout << "F";
    pConsole->gotoLigCol(6*3 + 4, 3);
    cout << "G";
    pConsole->gotoLigCol(7*3 + 4, 3);
    cout << "H";
    for(int i=0; i<8; i++)
    {
        pConsole->gotoLigCol(2,i*6 + 8);
        cout << i+1;
    }
    pConsole->setColor(COLOR_DEFAULT);

    for(char i = 0; i < 8; i++)
    {
        for(char j = 0; j < 8; j++)
        {
            p_console->gotoLigCol(i*3 + 4, j*6 + 8);
            cout<<tab[i][j]<< " ";
        }
        cout<<endl<<endl;
    }
}


void Board::m_set(unsigned int li, unsigned int col, char a)
{
    tab[li][col] = a;
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
        this->m_display();
        while(1)
        {
            if(this->p_console->isKeyboardPressed())
            {
                char mov = this->p_console->getInputKey();
                //this->m_put(mov);
                this->m_cursor(mov);
            }

        }
}

void Board::m_put(char mov)
{
    this->m_set(m_x, m_y, 120); //caractere representant le pion
    p_console->gotoLigCol(m_x*3 + 4, m_y*6 + 8);
    cout<<this->tab[m_x][m_y];
}

void Board::m_cursor(char mov)
{
                switch(mov)
                {
                case 'z':

                    pre_x = m_x;
                    m_x = m_x-1;
                    pre_y = m_y;
                    m_y = m_y;

                    break;

                case 's':
                    pre_x = m_x;
                    m_x = m_x+1;
                    pre_y = m_y;
                    m_y = m_y;
                    break;

                case 'd':
                    pre_y = m_y;
                    m_y = m_y+1;
                    pre_x = m_x;
                    m_x = m_x;
                    break;

                case 'q':
                    pre_y = m_y;
                    m_y = m_y-1;
                    pre_x = m_x;
                    m_x = m_x;
                    break;

                case 32:
                    this->m_put(mov);
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
                this->m_clean();
                this->m_set(m_x, m_y, 170);
                this->p_console->setColor(COLOR_RED);
                p_console->gotoLigCol(m_x*3 + 4, m_y*6 + 8);
                cout<< this->tab[m_x][m_y];
}


void Board::m_clean()
{
    this->pre_c = tab[m_x][m_y];
    this->p_console->setColor(COLOR_DEFAULT);
    this->m_set(pre_x, pre_y, pre_c);
    p_console->gotoLigCol(pre_x*3 + 4, pre_y*6 + 8);
    cout<< this->tab[pre_x][pre_y];
}

#include "Board.h"
#include "console.h"
#include "Player.h"
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

    tab[3][3] = 'x';
    tab[4][4] = 'x';
    tab[3][4] = 'o';
    tab[4][3] = 'o';
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






bool Board::isPlacementOK(int m_x,int m_y,Player a)
{
    char adverse;
    if(a.getSymbol() == 'R')
    {
        adverse= 'B';
    }else{adverse = 'R';}

    if(tab[m_x-1][m_y-1] == 'x' || tab[m_x-1][m_y-1] == 'o')
    {
        cout << tab[m_x-1][m_y-1] << "diagonale ahut gauche" << endl;
        return true;//cdiagonale haut gauche
    }
    if(tab[m_x][m_y-1] == 'x' || tab[m_x][m_y-1] == 'o' )
    {
        cout << tab[m_x][m_y-1] << "haut" << endl;
        return true;//haut
    }
    if(tab[m_x+1][m_y-1] == 'x' || tab[m_x+1][m_y-1] == 'o')
    {
        cout << tab[m_x+1][m_y-1] << "diagonale haut droite" << endl;
        return true;//diagonale haut droite
    }
    if(tab[m_x-1][m_y] == 'x' || tab[m_x-1][m_y] == 'o')
    {
        cout << tab[m_x-1][m_y] << "gauche" << endl;
        return true;//gauche
    }
    if(tab[m_x+1][m_y] == 'x' || tab[m_x+1][m_y] == 'o')
    {
        cout << tab[m_x+1][m_y] << "droite" << endl;
        return true;//droite
    }
    if(tab[m_x-1][m_y+1] == 'x' || tab[m_x-1][m_y+1] == 'o')
    {
        cout << tab[m_x-1][m_y+1] << "diagonale bas gauche" << endl;
        return true;//bdiagonale bas gauche
    }
    if(tab[m_x][m_y+1] == 'x' || tab[m_x][m_y+1] == 'o')
    {
        cout << tab[m_x][m_y+1] << "bas" << endl;
        return true;//bas
    }
    if(tab[m_x+1][m_y+1] == 'x' || tab[m_x+1][m_y+1] == 'o')
    {
        cout << tab[m_x+1][m_y+1] << "diagonale bas droite" << endl;
        return true;//diagonale bas droite
    }else{return false;}
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
            if(i == m_y && j == m_x) pConsole->setColor(COLOR_RED);
            else pConsole->setColor(COLOR_DEFAULT);

            p_console->gotoLigCol(i*3 + 4, j*6 + 8);
            cout<<tab[i][j]<< " ";
        }
        cout<<endl<<endl;
    }

    p_console->gotoLigCol(5,60);
    cout<< m_x << " " << m_y;
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
    string name1;
    string name2;
    char symbol_1;
    char symbol_2;
    cout<< "        entrez le nom du premier joueur"<< endl;
    cin>>name1;

    do
                {
                    cout <<"        couleur du pion (R ou B)" << endl;
                    cin >> symbol_1;
                }

            while(symbol_1 != 'R' && symbol_1 != 'B' && symbol_1!='r' && symbol_1!='b');



    cout<< "        entrez le nom du deuxieme joueur"<< endl;
    cin>>name2;


            if (symbol_1== 'R' || symbol_1=='r')
                {
                    symbol_2 = 'B';
                }


           else
            {
                symbol_2 = 'R';
            }
    Player a(name1,symbol_1);
    Player b(name2,symbol_2);
    cout<<name1 <<" : " <<symbol_1<<endl;
    cout<<name2 <<" : " <<symbol_2 <<endl;
    system("PAUSE");
    system("cls");

        this->m_display();
        while(1)
        {
            if(this->p_console->isKeyboardPressed())
            {
                char mov = this->p_console->getInputKey();
                //this->m_put(mov);
                this->m_cursor(mov,a);
                this->m_display();
            }

        }
}

void Board::m_put(char mov, int m_x, int m_y,Player a)
{
    if(isPlacementOK(m_x,m_y,a))
    {
    this->m_set(m_y, m_x, 120); //caractere representant le pion
    p_console->gotoLigCol(m_x*3 + 4, m_y*6 + 8);
    cout<<this->tab[m_x][m_y];
    }

}

void Board::m_cursor(char mov,Player a)
{
                switch(mov)
                {
                case 'z':
                    /*char a;
                    a= tab[m_x][m_y];
                    pre_x = m_x;
                    m_x = m_x-1;
                    pre_y = m_y;
                    m_y = m_y;
                    tab[pre_x][pre_y]= a;*/
                    m_y--;
                    break;

                case 's':
                    /*
                    char b;
                    b= tab[m_x][m_y];
                    pre_x = m_x;
                    m_x = m_x+1;
                    pre_y = m_y;
                    m_y = m_y;
                    tab[pre_x][pre_y]= b;*/

                    m_y++;
                    break;

                case 'd':
                    /*
                    char c;
                    c= tab[m_x][m_y];
                    pre_y = m_y;
                    m_y = m_y+1;
                    pre_x = m_x;
                    m_x = m_x;
                    tab[pre_x][pre_y]= c;*/
                    m_x++;
                    break;

                case 'q':
                    /*
                    char d;
                    d= tab[m_x][m_y];
                    pre_y = m_y;
                    m_y = m_y-1;
                    pre_x = m_x;
                    m_x = m_x;
                    tab[pre_x][pre_y]= d;*/
                    m_x--;
                    break;

                case 32:
                    this->m_put(mov,m_x,m_y,a);
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
                /*
                this->m_clean();
                this->m_set(m_x, m_y, 95);
                this->p_console->setColor(COLOR_RED);
                p_console->gotoLigCol(m_x*3 + 4, m_y*6 + 8);
                cout<< this->tab[m_x][m_y];
                */
}


void Board::m_clean()
{
    this->pre_c = tab[m_x][m_y];
    this->p_console->setColor(COLOR_DEFAULT);
    this->m_set(pre_x, pre_y, pre_c);
    p_console->gotoLigCol(pre_x*3 + 4, pre_y*6 + 8);
    cout<< this->tab[pre_x][pre_y];
}

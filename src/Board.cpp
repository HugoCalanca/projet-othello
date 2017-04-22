#include "Board.h"
#include "console.h"
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

unsigned int Board::get_x()
{
    return this->m_x;
}

unsigned int Board::get_y()
{
    return this->m_y;
}

void Board::set_x(unsigned int x)
{
    this->m_x = x;
}


void Board::set_y(unsigned int y)
{
    this->m_y = y;
}


void Board::set_possibilites()
{
    char adverse, allie;
    if(m_tour % 2 !=0)
    {
        allie = this->j1;
        adverse = this->j2;
    }
    else
    {
        adverse = this->j1;
        allie = this->j2;
    }
    unsigned int col = 0;
    unsigned int lig = 0;
    for(unsigned int i= 0; i <8; i++)
    {
        for(unsigned int j=0; j <8; j++)
        {
            if(tab[i][j]== allie)
            {
                if(tab[i+1][j] == adverse) // si ya un ennemi à droite
                {
                    col = i+1;
                    lig = j;
                    while( tab[col][lig] == adverse)
                    {
                        col++;
                    }
                    if(tab[col][lig]== allie || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        this->m_listCoup.push_back(c);
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
                    if(tab[col][lig]== allie || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        this->m_listCoup.push_back(c);
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
                    if(tab[col][lig]== allie || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        this->m_listCoup.push_back(c);
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
                    if(tab[col][lig]== allie || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        this->m_listCoup.push_back(c);
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
                    if(tab[col][lig]== allie || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        this->m_listCoup.push_back(c);
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
                    if(tab[col][lig]== allie || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        this->m_listCoup.push_back(c);
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
                    if(tab[col][lig]== allie || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        this->m_listCoup.push_back(c);
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
                    if(tab[col][lig]== allie || col < 0 || col > 7 || lig <0 || lig > 7)
                    {

                    }
                    else
                    {
                        Coup c(col, lig, 1);
                        this->m_listCoup.push_back(c);
                    }
                }
            }
        }
    }
}


void Board::Begin(int choice)
{

    if(choice == 1)
    {
        string name1 = "Joueur1";
        string name2 = "Joueur2";
        this->j1 = 177 ;
        this->j2 = 178 ;
        p_console->setColor(COLOR_GREEN);
        cout<<name1 <<" : " <<j1<<endl;
        p_console->setColor(COLOR_YELLOW);
        cout<<name2 <<" : " <<j2 <<endl;
        p_console->setColor(COLOR_DEFAULT);
        system("PAUSE");
        system("cls");
        //this->Bouclejeu2();
    }
    else if(choice ==2)
    {
        string name1 = "Joueur1";
        string name2 = "IA";
        this->j1 = 177 ;
        this->j2 = 178 ;
        p_console->setColor(COLOR_GREEN);
        cout<<name1 <<" : " <<j1<<endl;
        p_console->setColor(COLOR_YELLOW);
        cout<<name2 <<" : " <<j2 <<endl;
        p_console->setColor(COLOR_DEFAULT);
        system("PAUSE");
        system("cls");
        //this->Bouclejeu();
    }
    else if(choice == 3)
    {
        ifstream fichier("Regle.txt", ios::in);
        string line;
        while(getline(fichier,line))
        {
            cout << line << endl;
        }
    }

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

bool Board::isSquareOK()
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
            else if(tab[i][j] == this->j1)
            {
                p_console->setColor(COLOR_GREEN);
            }
            else if(tab[i][j] == this->j2)
            {
                p_console->setColor(COLOR_YELLOW);
            }
            else if (isCoupjouable(i, j))
            {
                p_console->setColor(COLOR_BLUE);
            }
            else
            {
                p_console->setColor(COLOR_WHITE);
            }
            p_console->gotoLigCol(i*3 + 4, j*6 + 8);
            cout<<tab[i][j]<< " ";
        }
        cout<<endl<<endl;
    }

    p_console->gotoLigCol(5,60);
    if(this->m_tour % 2 != 0)
    {
        //c'est au J1 de jouer
        p_console->setColor(COLOR_GREEN);
        cout<< "A J1"<< this->j1<<"de jouer " << endl;
    }
    else
    {
        //c'est au J2 de jouer
        p_console->setColor(COLOR_YELLOW);
        cout<< "A J2"<< this->j2<<"de jouer " << endl;

    }

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

//tour de jeu pour un joueur humain
void Board::m_play()
{
    //on cherhce toutes les possibilité
    this->set_possibilites();
    m_over = false;
    //tant qu'on a pas fini son tour
    while(!m_over)
    {
        if(this->p_console->isKeyboardPressed())
        {
            //on fait joué le curseur
            char mov = this->p_console->getInputKey();
            this->m_cursor(mov);
            this->m_display();
        }
    }
    //on reset la list pour la suite
    this->resetList();
}

//tour de jeu de l'intelligence artificielle
void Board::m_play(bool ia)
{
    //on cherche toutes les possibilitées pour l'ia (pas indispensable)
    this->set_possibilites();
    if (m_listCoup.size()==0)
    {
        Winner();
    }
    m_over = false;
    this->m_put();
    this->m_display();
    //on reset la list
    this->resetList();
}


/*void Board::Bouclejeu()
{
    while(1)
    {
        if(this->m_tour % 2 == 0)
        {
            this->set_possibilites();
            if (m_listCoup.size()==0)
            {
                Winner();
            }
            //this->ia.Random(m_x, m_y, m_listCoup);
            this->m_put();
            this->m_display();
        }
        else
        {
            this->set_possibilites();
            while(!m_over)
            {
                if(this->p_console->isKeyboardPressed())
                {
                    char mov = this->p_console->getInputKey();
                    this->m_cursor(mov);
                    this->m_display();
                }
            }
        }
        m_over= false;
        this->m_display();

        this->resetList();
    }
}*/


void Board::set_pion()
{
    if(this->m_tour % 2 != 0)
    {
        //c'est au joueur 1 de jouer
        this->tab[m_x][m_y] = this->j1;
    }
    else
    {
        //c'est au joueur 2 de jouer
        this->tab[m_x][m_y] = this->j2;
    }
}

void Board::set_pion(unsigned int col, unsigned int lig)
{
    if(this->m_tour % 2 != 0)
    {
        //c'est au joueur 1 de jouer
        this->tab[col][lig] = this->j1;
    }
    else
    {
        //c'est au joueur 2 de jouer
        this->tab[col][lig] = this->j2;
    }
}


void Board::flip_pion()
{
    char adverse, allie;
    if(m_tour % 2 !=0)
    {
        //c'est à j1 de jouer
        allie = this->j1;
        adverse = this->j2;
    }
    else
    {
        //c'est à j2 de jouer
        adverse = this->j1;
        allie = this->j2;
    }
    if(tab[m_x+1][m_y] == adverse)
    {
        //s'il y a un adversaire
        unsigned int i = m_x+1;
        unsigned int j = m_y;
        while(tab[i][j] == adverse && tab[i][j] != allie)
        {
            i++;
        }
        if(tab[i][j] == allie)
        {
            while( i != m_x)
            {
                i--;
                this->set_pion(i, j);
            }
        }
    }
    if(tab[m_x-1][m_y] == adverse)
    {
        unsigned int i = m_x-1;
        unsigned int j = m_y;
        while(tab[i][j] == adverse && tab[i][j] != allie)
        {
            i--;
        }
        if(tab[i][j] == allie)
        {
            while( i != m_x)
            {
                i++;
                this->set_pion(i, j);
            }
        }
    }
    if(tab[m_x][m_y+1] == adverse)
    {
        unsigned int i = m_x;
        unsigned int j = m_y+1;
        while(tab[i][j] == adverse && tab[i][j] != allie)
        {
            j++;
        }
        if(tab[i][j] == allie)
        {
            while( j != m_y)
            {
                j--;
                this->set_pion(i, j);
            }
        }
    }
    if(tab[m_x][m_y-1] == adverse)
    {
        unsigned int i = m_x;
        unsigned int j = m_y-1;
        while(tab[i][j] == adverse && tab[i][j] != allie)
        {
            j--;
        }
        if(tab[i][j] == allie)
        {
            while( j != m_y)
            {
                j++;
                this->set_pion(i, j);
            }
        }
    }
    if(tab[m_x+1][m_y+1] == adverse)
    {
        unsigned int i = m_x+1;
        unsigned int j = m_y+1;
        while(tab[i][j] == adverse && tab[i][j] != allie)
        {
            i++;
            j++;
        }
        if(tab[i][j] == allie)
        {
            while( i != m_x && j != m_y)
            {
                i--;
                j--;
                this->set_pion(i, j);
            }
        }
    }
    if(tab[m_x+1][m_y-1] == adverse)
    {
        unsigned int i = m_x+1;
        unsigned int j = m_y-1;
        while(tab[i][j] == adverse && tab[i][j] != allie)
        {
            i++;
            j--;
        }
        if(tab[i][j] == allie)
        {
            while( i != m_x && j != m_y)
            {
                i--;
                j++;
                this->set_pion(i, j);
            }
        }
    }
    if(tab[m_x-1][m_y+1] == adverse)
    {
        unsigned int i = m_x-1;
        unsigned int j = m_y+1;
        while(tab[i][j] == adverse && tab[i][j] != allie)
        {
            i--;
            j++;
        }
        if(tab[i][j] == allie)
        {
            while( i != m_x && j != m_y)
            {
                i++;
                j--;
                this->set_pion(i, j);
            }
        }
    }
    if(tab[m_x-1][m_y-1] == adverse)
    {
        unsigned int i = m_x-1;
        unsigned int j = m_y-1;
        while(tab[i][j] == adverse && tab[i][j] != allie)
        {
            i--;
            j--;
        }
        if(tab[i][j] == allie)
        {
            while( i != m_x && j != m_y)
            {
                i++;
                j++;
                this->set_pion(i, j);
            }
        }
    }
}


void Board::m_put()
{
    if(isSquareOK())
    {
        if(isCoupjouable(m_x, m_y))
        {
            this->set_pion();
            this->flip_pion();
            p_console->setColor(COLOR_YELLOW);
            p_console->gotoLigCol(m_x*3 + 4, m_y*6 + 8);
            cout<<this->tab[m_x][m_y];
            this->m_tour++;
            m_over= true;
        }


    }
    /*else
        {
        Winner();
        }

    int v=64;
    for (int i=0; i<7;i++)
    { for(int j=0;j<7;j++)
        {
            if (tab[i][j]!=223)
            {
                v--;
                cout<<v;
            }
        }
    }
    if (v==0)
    {
        Winner();
    }
    */




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

        cout<<endl<<endl<<endl<<endl<<endl<<m_y;
        break;

    case 'q':

        if (m_y>=0)
        {
            m_y--;
        }
        else
        {
            m_y=0;
        }
        cout<<endl<<endl<<endl<<endl<<m_y;
        break;

    case 32:
        this->m_put();
        break;

    default:
        m_x = m_x;
        m_y = m_y;
        break;
    }
    if( m_x > 7)
    {
        m_x = 7;
    }
    if (m_x < 0)
    {
        m_x = 0;
    }
    if( m_y > 7)
    {
        m_y = 7;
    }
    /*if(m_y < 0)
    {
       m_y = 0;
    }*/
}

void Board::Winner()
{
    int j1;
    int j2;
    int vide;
    for (int i=0; i<7; i++)
    {
        for (int j=0; j<7; j++)
        {
            if (tab[i][j]==177)
            {
                j1++;
            }

            if (tab[i][j]==178)
            {
                j2++;
            }

            if (tab[i][j]==223)
            {
                vide++;
            }
        }
    }

    if (j1>j2)
    {
        j1=j1+vide;
        cout<<" J1 gagne! (nombre de pions : " <<j1 <<")"<<endl;
    }
    else
    {
        j2=j2+vide;
        cout<<" J2 gagne! (nombre de pions : " <<j2 <<")"<<endl;
    }
}


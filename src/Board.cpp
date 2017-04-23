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
{/**
 * \brief       liste de coup est réinitialisée après chaque tour
 * \details    \a m_listCoup est effacée
 *
 */
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


void Board::regle()
{
    /**
 * \brief       lecture du fichier Regle
 *
 */
    ifstream fichier("Regle.txt", ios::in);
    string line;
    while(getline(fichier,line))
    {
        cout << line << endl;
    }

}

void Board::Save()
{
    /**
 * \brief       sauvegarder plateau
 *
 */
    ofstream fichier("Save.txt", ios::out);
    char carac;
    char vide= 'ß';
    char j1='±';
    char j2='²';
    if(fichier)
    {
        for(int i =0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if(j==7)
                {
                    carac=tab[i][j];

                    fichier << tab[i][j];
                    fichier << endl;
                }
                else if(j!= 7)
                {
                    fichier << tab[i][j];
                }

            }
        }


        fichier.close();
    }
}

void Board::Load()
{
    cout << "Debut du load" << endl;
    int i=0;
    int j=0;
    ifstream fichier("Save.txt", ios::in);
    if(fichier)
    {
        char carac;
        while(fichier)
        {
            fichier.get(carac);
            if(j >8)
            {
                i++;
                j=0;
                fichier >> tab[i][j];


            }
            if(j<8)
            {
                fichier >> tab[i][j];
                j++;
            }
            fichier.close();
        }
    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(j == 7)
            {

                cout << tab[i][j];
                cout << " ";
                cout << endl;
            }
            else
            {
                cout << tab[i][j];
                cout << " ";
            }
        }
    }
    cout << "fin du load" << endl;
    system("PAUSE");
    system("cls");
}



vector<Board> Board::get_suc_n()
{
    return this->suc_n;
}


void Board::set_possibilites()
{
    /**
 * \brief       Calcule possibilites de coups
 *
 *
 */
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
        cout<<"Nom J1 :" <<endl;
        string name1;
        cin>>name1;
        cout<<"Nom J2 :" <<endl;
        string name2;
        cin>>name2;
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
        cout<<"Nom J1 :" <<endl;
        string name1;
        cin>>name1;
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
    else if (choice == 3)
    {
        cout<<"Nom J1 :" <<endl;
        string name1;
        cin>>name1;
        string name2 = "IA2";
        this->j1 = 177 ;
        this->j2 = 178 ;
        p_console->setColor(COLOR_GREEN);
        cout<<name1 <<" : " <<j1<<endl;
        p_console->setColor(COLOR_YELLOW);
        cout<<name2 <<" : " <<j2 <<endl;
        p_console->setColor(COLOR_DEFAULT);
        system("PAUSE");
        system("cls");
    }
    else if(choice == 4)
    {
        cout<<"Nom J1 :" <<endl;
        string name1;
        cin>>name1;
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
    /**
 * \brief       lecture du fichier Regle
 * \return
 */
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
        cout<< "A J1 "<< this->j1<<" de jouer " << endl;
        Winner();
    }
    else
    {
        //c'est au J2 de jouer
        p_console->setColor(COLOR_YELLOW);
        cout<< "A J2 "<< this->j2<<" de jouer " << endl;
        Winner();

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


void Board::m_play()
{
    /**
 * \brief tour de jeu pour un joueur humain
 *
 *
 */
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
            this->Save();
            this->m_display();
        }
    }
    //on reset la list pour la suite
    this->resetList();
}


void Board::m_play(bool ia)
{
    /**
 * \brief     tour de jeu de l'intelligence artificielle
 *
 */
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


void Board::m_put(bool ia)
{
    if(isSquareOK())
    {
        if(isCoupjouable(m_x, m_y))
        {
            this->set_pion();
            this->flip_pion();
            this->m_tour++;
            m_over= true;
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
        //cout<<endl<<m_x;
        break;

    case 's':


        m_x++;
        //cout<<endl<<endl<<m_x;
        break;

    case 'd':

        m_y++;

        //cout<<endl<<endl<<endl<<endl<<endl<<m_y;
        break;

    case 'q':

            m_y--;

        //cout<<endl<<endl<<endl<<endl<<m_y;
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
    if(m_y < 0)
    {
        m_y = 0;
    }

    //cout<<endl<<endl<<endl<<m_x;
    //cout<<endl<<endl<<m_y;
}

void Board::Winner()
{
    int pionj1=0;
    int pionj2=0;
    int vide=0;
    //char vide= 'ß';
    //char j1='±';
    //char j2='²';
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (tab[i][j]==177 || tab[i][j]== '±')
            {
                pionj1++;
            }

            if (tab[i][j]==178 || tab[i][j]== '²')
            {
                pionj2++;
            }

            if (tab[i][j]==223 || tab[i][j]== 'ß')
            {
                vide++;
            }
        }
    }
    if(m_listCoup.size()==0)
    {
        if (pionj1>pionj2)
        {
            pionj1=pionj1+vide;
            system("cls");
            ifstream fichier("Victoire1.txt", ios::in);
            string line;
            while(getline(fichier,line))
            {
                cout << line << endl;
            }
            cout << "Score final: " << endl;
            cout<<" J1  : " <<pionj1 <<endl;
            cout<<" J2  : " <<pionj2 <<endl;


        }
        else
        {
            pionj2=pionj2+vide;
            system("cls");
            ifstream fichier("Victoire2.txt", ios::in);
            string line;
            while(getline(fichier,line))
            {
                cout << line << endl;
            }
            cout << "Score final: " << endl;
            cout<<" J1  : " <<pionj1 <<endl;
            cout<<" J2  : " <<pionj2 <<endl;


        }
    }
    else
    {
        p_console->gotoLigCol(7,60);
        cout << "Le joueur 1 a " << pionj1 << " pions." << endl;
        p_console->gotoLigCol(8,60);
        cout << "Le joueur 2 a " << pionj2 << " pions." << endl;
    }

}

bool Board::isBoardfull()
{
    for (int i=0;i<7; i++)
    {
        for (int j; j<7; j++)
        {
            if (this->tab[i][j]==277 || this->tab[i][j]==278)
            {
                return true;
            }
        }
    }


}

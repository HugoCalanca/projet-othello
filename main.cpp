#include <iostream>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include "console.h"
#include <algorithm>
#include <windows.h>
#include "IA.h"
#include "Board.h"
#include <fstream>

using namespace std;


void Boucle_jeu()
{

}


int main()
{
    Board plateau;
    bool ended = false;
    IA ia;
    system("cls");
    ifstream fichier("Menu.txt", ios::in);
    string line;
    while(getline(fichier,line))
    {
        cout << line << endl;
    }
    //system("pause");
    //system("cls");

    int choice=0;

<<<<<<< HEAD

    while(choice < 1 || choice > 4)
=======
<<<<<<< HEAD

    while(choice < 1 || choice > 3)
>>>>>>> origin/master
    {
        cin >> choice;
    }

    system("cls");

    plateau.Begin(choice);
    switch(choice)
    {
    case 1 :
        //on veut jouer contre un personne physique :
        while(!ended)
        {
            plateau.m_play();
        }
        break;
    case 2 :
        //on veut jouer contre l'ordinateur :
        while(!ended)
        {
            //le joueur 1 joue
            plateau.m_play();
            //c'est à l'ia de jouer
<<<<<<< HEAD
            /** \brief on calcule les coups possibles
            puis pion est placé**/
            plateau.set_possibilites();
            plateau.set_x(ia.Random(plateau.m_listCoup).first);
            plateau.set_y(ia.Random(plateau.m_listCoup).second);
            plateau.Save();
            plateau.m_play(true);
        }
        break;

    case 3:
        //on veut jouer contre l'ordinateur :
        while(!ended)
        {
            //le joueur 1 joue
            plateau.m_play();
            //c'est à l'ia de jouer
            plateau.set_possibilites();
            plateau.set_x(ia.minimax(plateau, 3).first);
            plateau.set_y(ia.minimax(plateau, 3).second);
            plateau.Save();
            plateau.m_play(true);
        }
        break;

    case 4:

        plateau.Load();
        while(!ended)
        {
            plateau.m_play();
        }

        break;
    case 5:
        plateau.regle();
        return 0;
        break;


    default:
        break;
    }

=======
            plateau.set_possibilites();
            plateau.set_x(ia.Random(plateau.m_listCoup).first);
            plateau.set_y(ia.Random(plateau.m_listCoup).second);
            plateau.m_play(true);
        }
        break;

    default:
        break;
    }

=======

    while(choice < 1 || choice > 3)
    {
        cin >> choice;
    }

system("cls");

    plateau.Begin(choice);
>>>>>>> origin/master
>>>>>>> origin/master
}

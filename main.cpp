#include <iostream>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include "console.h"
#include <algorithm>
#include <windows.h>
#include "Board.h"
#include <Player.h>
#include <fstream>

using namespace std;

int main()
{
    Board plateau;
    /*string name1;
    string name2;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<< "        Bienvenue dans le jeu d'othello, entrez le nom du premier jouer"<< endl;
    cin>>name1;
    cout<<endl;
    cout<<endl;
    cout<< "        Maintenant, entrez le nom du second jouer"<< endl;
    cin>>name2;
    system("cls");
    Player a(name1,'E');
    Player b(name2,'R');*/

    system("cls");
    ifstream fichier("Menu.txt", ios::in);
    string line;
    while(getline(fichier,line))
    {
        cout << line << endl;
    }
    system("pause");
    system("cls");

    plateau.m_play();
}

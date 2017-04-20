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


    while(choice < 1 || choice > 3)
    {
        cin >> choice;
    }

system("cls");

    plateau.Begin(choice);
}

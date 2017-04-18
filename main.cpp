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
    system("pause");
    system("cls");



    plateau.Begin();
}

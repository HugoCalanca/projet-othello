#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

using namespace std;

class Player
{
    public:
        Player();
        Player(string m_name,char m_symbol);
        ~Player();
        string getName();
        char getSymbol();
        //void setPieceref(Piece cop);
        //Piece getPieceref();

    protected:
        string m_name;
        char m_symbol;

    private:
};

#endif // PLAYER_H

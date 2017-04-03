#include "Player.h"

Player::Player()
{
    //ctor
}

Player::Player(string m_name,char m_symbol)
        :m_name(m_name),m_symbol(m_symbol)
{
    //ctor
}

Player::~Player()
{
    //dtor
}

string Player::getName()
{
    return this->m_name;
}

char Player::getSymbol()
{
    return this->m_symbol;
}

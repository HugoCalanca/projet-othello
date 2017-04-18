#include "Coup.h"

Coup::Coup()
{
    //ctor
}

Coup::Coup(unsigned int i, unsigned int j, int p)
    : m_first(i), m_second(j), m_poids(p)
{

}

Coup::~Coup()
{
    //dtor
}

bool operator <(Coup const &first, Coup const &second)
{
    if(first.m_poids < second.m_poids)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#ifndef COUP_H
#define COUP_H

/**
 * \file          Coup.h
 * \brief       classe qui contient les informations d'une case (lig, col, poids)
 *
 */

class Coup
{
    public:
        Coup();
        Coup(unsigned int i, unsigned int j, int p);
        ~Coup();
        //premi�re composante des coordonn�es
        unsigned int m_first;
        //deuxi�me composante des coordonn�es
        unsigned int m_second;
        //poids du coup
        int m_poids;
    protected:

};
bool operator <(Coup const &first, Coup const &second);
#endif // COUP_H

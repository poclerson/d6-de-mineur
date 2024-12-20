//
//  position.h
//

#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Position {
private:
    int m_ligne;
    int m_colonne;

public:
    Position(int ligne = -1, int colonne = -1);
    
    int ligne() const;
    int colonne() const;
};

std::istream& operator>>(std::istream& is, Position& pos);
std::ostream& operator<<(std::ostream& os, const Position& pos);

void lireValiderEntier(std::istream& es_entree, int& s_entier);

#endif /* Position_h */

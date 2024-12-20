//
//  position.cpp
//

#include <iostream>
#include <cassert>
#include "position.h"

using namespace std;

// description : fonction utilitaire qui permet de lire et valider si c'est bien un entier qui est lu
// param[ES] : flux d'entree sur lequel on lit l'entier
// param[S] : entier lu
// pre : le flux est existant et ouvert (diff. de NULL)
// post : lit une valeur dans le flux jusqu'à ce qu'elle soit un entier

void lireValiderEntier(istream& es_entree, int &s_entier)
{
    assert(es_entree);
    
    while (!(es_entree >> s_entier))
    {
        // Afficher un message d'erreur et redemander le numero de ligne
        cout << "Erreur! Vous devez entrer une nombre entier! " << endl << "Entrez la ligne : ";
        // Vider le tampon de lecture
        es_entree.clear();
        // Ignorer tous les caracteres deja entres
        es_entree.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // Debug output
    cout << "Debug - es_entree: " << es_entree.rdbuf() << ", s_entier: " << s_entier << endl;
    
    assert(es_entree);
}

Position::Position(int ligne, int colonne)
    : m_ligne(ligne), m_colonne(colonne)
{
}

int Position::ligne() const
{
    return m_ligne;
}

int Position::colonne() const
{
    return m_colonne;
}

std::istream& operator>>(std::istream& is, Position& pos)
{
    int ligne, colonne;
    lireValiderEntier(is, ligne);
    lireValiderEntier(is, colonne);
    pos = Position(ligne, colonne);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Position& pos)
{
    os << "(" << pos.ligne() << "," << pos.colonne() << ")";
    return os;
}

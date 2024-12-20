// fichier : carte_.cpp
// auteur.es : METTEZ VOS NOMS ICI
// date : 2020
// modifications :
// description : Ce fichier contient la definition des methodes A IMPLEMENTER de la classe Carte d'un jeu de demineur

#include "carte.h"
#include "utilitaires.h"

#include <iomanip>
#include <cassert>
#include <stdio.h>

// Description: Methode qui calcule le nombre de mines adjacentes a une case
// param[E] Position de la case
// retour : nombre de mines adjacentes a la case
// post : on compte le nombre de mines adjacentes a la case (entre 0 et 8)

Compteur Carte::getNbMinesAdjacentes(Position e_pos)
{
    Compteur nbMines = 0;
    
    // Check all 8 adjacent positions
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            // Skip the center position (the position itself)
            if (i == 0 && j == 0) continue;
            
            Position adjacentPos(e_pos.ligne() + i, e_pos.colonne() + j);
            
            // Check if the adjacent position is within the board
            if (estDansCarte(adjacentPos)) {
                // If the adjacent position contains a mine, increment the counter
                if (getCase(adjacentPos).estUneMine()) {
                    ++nbMines;
                }
            }
        }
    }
    
    return nbMines;
}

// Description: Methode qui essaie d'ouvrir une case
// param[E] Position de la case
// retour : booleen - vrai si ce n'est pas une mine, faux sinon
// post : si la case a deja ete ouverte, ce n'est pas une mine -> retourne vrai, si la case n'est pas une mine, les cases voisines doivent etre ouvertes jusqu'a une prochaine mine

bool Carte::essaieCase(Position e_pos)
{
    if (!estDansCarte(e_pos) || caseEstOuverte(e_pos)) {
        return true;
    }

    ouvreCase(e_pos);

    if (getCase(e_pos).estUneMine()) {
        return false;
    }

    if (getCase(e_pos).nbMinesAdj() == 0) {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                Position adjacentPos(e_pos.ligne() + i, e_pos.colonne() + j);
                if (estDansCarte(adjacentPos) && !caseEstOuverte(adjacentPos)) {
                    essaieCase(adjacentPos);
                }
            }
        }
    }

    return true;
}

// Description: Methode qui calcule le nombre de mines adjacentes pour les cases libres de la carte
// post : pour chacune des cases qui ne contient pas une mine, on compte le nombre de mines adjacentes

void Carte::compteMinesAdjParCase()
{ 
    // a completer
    // a completer
    // a completer
    // a completer
    // a completer
}

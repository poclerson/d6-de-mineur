//
// fichier : main.cpp
// auteur.e : Vincent Ducharme
// date : 2016
// modifications :
// 03/2018 Marie-Flavie Auclair-Fortier : refactoring du code
// 11/2019 Marie-Flavie Auclair-Fortier : refactoring du code
// description : Ce fichier contient un jeu de Demineur
//

#include "carte.h"
#include "utilitaires.h"
#include "position.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Description: Programme principal pour le jeu Demineur

int main()
{
    void jouer(ifstream &);
    
    // Declaration des variables locales
    string nomFichierCarte, nomFichierTest;
    
    // Lire le nom du fichier contenant la carte de jeu
    cout << "Entrez le nom du fichier contenant la carte : ";
    cin >> nomFichierCarte;
    cout << endl;

    // Lire le nom du fichier de test
    cout << "Entrez le nom du fichier de test (ou 'non' pour utiliser l'entrée standard) : ";
    cin >> nomFichierTest;
    cout << endl;

    // Ouvrir le fichier de la carte
    ifstream fichierCarte(nomFichierCarte);
    if (!fichierCarte.is_open()) {
        cout << "Erreur: Impossible d'ouvrir le fichier de la carte." << endl;
        return 1;
    }

    // Rediriger cin vers le fichier de test si spécifié
    ifstream fichierTest;
    if (nomFichierTest != "non") {
        fichierTest.open(nomFichierTest);
        if (fichierTest.is_open()) {
            cin.rdbuf(fichierTest.rdbuf());
            cout << "Utilisation du fichier de test pour les entrées." << endl;
        } else {
            cout << "Erreur: Fichier de test non trouvé. Utilisation de l'entrée standard." << endl;
        }
    } else {
        cout << "Utilisation de l'entrée standard." << endl;
    }

    // Vider le tampon d'entrée
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    // Jouer le jeu
    jouer(fichierCarte);

    return 0;
}

void jouer(std::ifstream &es_fichierCarte)
{
    // signature de fonction locale
    bool jouerUnTour(Carte&);

    // Creer la carte a partir du fichier
    Carte carte {es_fichierCarte};
    
    // Afficher la carte
    cout << carte;
    
    // Tant qu'on ne veut pas quitter
    while (jouerUnTour(carte))
    {};
}

// Description: Un tour du jeu
// param[E/S] : Carte
// retour : booleen
// post : retourne faux si la partie et terminee
// post : retourne vrai si la partie continue

bool jouerUnTour(Carte &es_carte)
{
    Position position;
    
    // Lecture de la position a essayer
    cin>>position;
    
    // Si la ligne entree est -1, le jeu est termine
    if (position.ligne() == -1)
        return false;
    
    if (!es_carte.estDansCarte(position))
    {
        cerr<<"La position "<<position<<" n'est pas une case dans la carte, veuillez recommencer"<<endl;
        return true;
    }
    
    // Effacer tout l'ecran
    Console::clearScreen();
    
    // Essaie la case demandee si on trouve une mine
    if (!es_carte.essaieCase(position))
    {
        // Affiche un message d'erreur et indique de quitter le jeu
        cout << "Vous avez touche une mine a la position " << position << "!!!" << endl;
        cout << "Partie terminee." << endl;
        cout<<endl<< es_carte;
        return false;
    }
    // Sinon, verifier si on vient de terminer la partie
    else if (es_carte.partieEstTerminee())
    {
        // Affiche un message de felicitation et indique de quitter le jeu
        cout << "Vous avez gagne!" << endl;
        cout<<endl<< es_carte;
        return false;
    }
    else
    {
        // Affiche un message de confirmation pour la case ouverte
        cout << "Case " << position << " ouverte avec succes." << endl;
        if (es_carte.getCase(position).nbMinesAdj() > 0) {
            cout << "Il y a " << (int)es_carte.getCase(position).nbMinesAdj() << " mine(s) adjacente(s)." << endl;
        } else {
            cout << "Aucune mine adjacente. Les cases adjacentes ont ete ouvertes automatiquement." << endl;
        }
    }
    
    // Affiche la carte
    cout<<endl<< es_carte;
    
    return true;
}

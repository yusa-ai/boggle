/**
 * @file utils.cpp
 * @brief Fonctions utilitaires pour la réalisation des exercices du projet
 */

#pragma warning(disable:4996)
#include "utils.h"
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

void get_mots(ListeMots& liste) {
    while (true) {
        Mot mot;
        cin >> mot;
        if (!strcmp(mot, "*"))
            break;
        inserer(liste, longueur(liste), mot);
    }
}

int evaluer(const Mot mot) {
    int l = strlen(mot);
    if (l <= 2)
        return 0;
    else if (l == 3 || l == 4)
        return 1;
    else if (l == 5)
        return 2;
    else if (l == 6)
        return 3;
    else if (l == 7)
        return 5;
    else
        return 11;
}

void afficher(const ListeMots& liste) {
    for (int i = 0; i < longueur(liste); ++i)
        cout << lire(liste, i) << endl;
    cout << "*" << endl;
}

void canonique(ListeMots& liste) {
    // Méthode : comparaison deux à deux
    int i = 0, j = 1;
    while (j < longueur(liste)) {
        int k = strcmp(lire(liste, i), lire(liste, j));
        // si même mot
        if (k == 0) {
            supprimer(liste, j); // suppression du doublon
            continue; // on refait un tour sur les mêmes positions dans la liste
        }
        // si mot1 > mot2 alphabétiquement
        else if (k > 0) {
            Mot tmp;
            strcpy(tmp, lire(liste, i));
            supprimer(liste, i);
            inserer(liste, j, tmp);
            canonique(liste);
        }
        ++i, ++j;
    }
}

bool chercher(const ListeMots& liste, const Mot mot) {
    int i; // dummy
    return chercher(liste, mot, i);
}

bool chercher(const ListeMots& liste, const Mot mot, int& index) {
    for (int j = 0; j < longueur(liste); ++j)
        if (!strcmp(mot, lire(liste, j))) {
            index = j;
            return true;
        }
    index = -1;
    return false;
}

void sub(ListeMots& liste1, const ListeMots& liste2) {
    assert(liste1.nbMots >= liste2.nbMots);

    for (int i = 0; i < longueur(liste2); ++i) {
        int j;
        Mot courant;
        strcpy(courant, lire(liste2, i));
        if (chercher(liste1, courant, j))
            supprimer(liste1, j);
    }
}
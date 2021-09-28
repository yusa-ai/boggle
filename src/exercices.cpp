/**
 * @file exercices.cpp
 * @brief Fonctions pour les six exercices du projet
 */

#pragma warning(disable:4996)
#include "exercices.h"
#include "utils.h"
#include "PlateauMots.h"
#include <iostream>
#include <cstring>
using namespace std;

void ex1() {
    ListeMots liste;
    get_mots(liste);
    int pts = 0;
    for (int j = 0; j < longueur(liste); ++j)
        pts += evaluer(lire(liste, j));
    cout << pts;
    detruire(liste);
}

void ex2() {
    ListeMots liste;
    get_mots(liste);
    canonique(liste);
    afficher(liste);
    detruire(liste);
}

void ex3() {
    ListeMots liste1;
    get_mots(liste1);
    ListeMots liste2;
    get_mots(liste2);

    // suppression des doublons
    canonique(liste1);
    canonique(liste2);

    ListeMots uniques;

    for (int i = 0; i < longueur(liste2); ++i)
        if (!chercher(liste1, lire(liste2, i)))
            inserer(uniques, longueur(uniques), lire(liste2, i));

    afficher(uniques);

    detruire(liste1);
    detruire(liste2);
    detruire(uniques);
}

void ex4() {
    ListeMots liste1;
    get_mots(liste1);
    ListeMots liste2;
    get_mots(liste2);

    // suppression des doublons
    canonique(liste1);
    canonique(liste2);

    ListeMots communs;

    for (int i = 0; i < longueur(liste2); ++i)
        if (chercher(liste1, lire(liste2, i)))
            inserer(communs, longueur(communs), lire(liste2, i));

    afficher(communs);

    detruire(liste1);
    detruire(liste2);
    detruire(communs);
}

void ex5() {
    ListeListesMots listes;
    get_listes(listes);

    /* on "canonise" l'ensemble des listes pour en supprimer les doublons
    internes, qui ne comptent pas dans la recherche */
    for (int i = 0; i < listes.nb; ++i)
        canonique(listes.listes[i]);

    // on les unifie en une seule grande liste
    ListeMots liste1 = fusionner(listes);

    ListeMots liste2 = copier(liste1);
    canonique(liste2); // suppression des doublons inter-listes dans la copie

    /* la liste des mots présents dans au moins 2 listes est la soustraction
    entre la liste1 (unifiée) et la liste2 (une occurence de chaque mot) */
    sub(liste1, liste2);

    canonique(liste1);
    afficher(liste1);

    detruire(listes);
    detruire(liste1);
    detruire(liste2);
}

void ex6() {

    PlateauMots p;
    int l = 0, x = 0;
    while (l < p.nbCases) {
        int y = 0;
        Mot mot;
        cin >> mot;
        while (y < 4) { // on stocke les lettres par 4
            p.cases[l].coord.x = x;
            p.cases[l].coord.y = y;
            p.cases[l].lettre = mot[y];
            ++y, ++l;
        }
        ++x;
    }

    ListeMots liste;
    get_mots(liste);
    canonique(liste);

    for (int i = 0; i < longueur(liste); ++i) {
        Mot mot;
        strcpy(mot, lire(liste, i));
        if (recherche(p, mot))
            cout << mot << endl;
    }
    cout << "*" << endl;
    delete[] p.cases;
    detruire(liste);
}

/**
 * @file ListeListesMots.cpp
 * @brief Liste de listes de mots
 */

#pragma warning(disable:4996)
#include "ListeListesMots.h"
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

void get_listes(ListeListesMots& listes) {
    while (true) {
        char courant[MOT_MAX + 1];
        char precedent[MOT_MAX + 1];
        cin >> courant;
        if (!strcmp(courant, "*")) {
            if (!strcmp(precedent, courant)) // si le mot précédent est aussi un "*",
                break; // fin de la liste de listes
            strcpy(precedent, courant);
            ++listes.nb;
            continue;
        }
        etendre(listes); // vérifie si la liste (de listes) doit être étendue
        inserer(listes.listes[listes.nb], longueur(listes.listes[listes.nb]), courant);
        strcpy(precedent, courant);
    }
}

void etendre(ListeListesMots& listes) {
    if (listes.nb == listes.capacite) {
        int newTaille = listes.capacite * 2;
        auto* newListe = new ListeMots[newTaille];
        for (int i = 0; i < listes.capacite; ++i)
            newListe[i] = listes.listes[i];
        delete[] listes.listes;
        listes.listes = newListe;
        listes.capacite = newTaille;
    }
}

void detruire(ListeListesMots& listes) {
    for (int i = 0; i < listes.nb; ++i)
        detruire(listes.listes[i]);
    delete[] listes.listes;
    listes.listes = nullptr;
}

ListeMots fusionner(ListeListesMots& listes) {
    ListeMots f;
    for (int i = 0; i < listes.nb; ++i)
        for (int j = 0; j < listes.listes[i].nbMots; ++j)
            inserer(f, longueur(f), listes.listes[i].mots[j]);
    return f;
}
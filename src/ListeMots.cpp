/**
 * @file ListeMots.cpp
 * @brief Composant de liste de mots de capacité extensible
 */

#pragma warning(disable:4996)
#include "ListeMots.h"
#include <cassert>
#include <cstring>

void detruire(ListeMots& l) {
    delete[] l.mots;
    l.mots = nullptr;
}

unsigned int longueur(const ListeMots& l) {
    return l.nbMots;
}

Mot& lire(const ListeMots& l, unsigned int pos) {
    assert(pos < l.nbMots);
    return l.mots[pos];
}

void ecrire(ListeMots& l, unsigned int pos, const Mot& it) {
    if (pos >= l.capacite) {
        unsigned int newTaille = (pos + 1) * l.pas;
        Mot* newT = new Mot[newTaille];
        for (unsigned int i = 0; i < l.capacite; ++i)
            strcpy(newT[i], l.mots[i]);
        delete[] l.mots;
        l.mots = newT;
        l.capacite = newTaille;
    }
    strcpy(l.mots[pos], it);
}

void inserer(ListeMots& l, unsigned int pos, const Mot& it) {
    assert(pos <= l.nbMots);
    for (unsigned int i = l.nbMots; i > pos; --i)
        ecrire(l, i, lire(l, i - 1));
    ecrire(l, pos, it);
    ++l.nbMots;
}

void supprimer(ListeMots& l, unsigned int pos) {
    assert((l.nbMots != 0) && (pos < l.nbMots));
    for (unsigned int i = pos; i < l.nbMots - 1; ++i)
        ecrire(l, i, lire(l, i + 1));
    --l.nbMots;
}

ListeMots copier(const ListeMots& l) {
    ListeMots c;
    for (int i = 0; i < l.nbMots; ++i)
        inserer(c, longueur(c), l.mots[i]);
    return c;
}
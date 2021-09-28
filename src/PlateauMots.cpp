/**
 * @file PlateauMots.cpp
 * @brief Plateau de mots
 */

#include "PlateauMots.h"
#include <cassert>
#include <cstring>

Case& at(const PlateauMots& p, const Coord& c) {
    assert(c.x >= 0 && c.x < p.x_max&& c.y >= 0 && c.y < p.y_max);
    int i = 0;
    for (; i < p.nbCases; ++i)
        if (p.cases[i].coord.x == c.x && p.cases[i].coord.y == c.y)
            break;
    return p.cases[i];
}

bool recherche(const PlateauMots& p, const Mot mot) {
    for (int i = 0; i < p.nbCases; ++i)
        p.cases[i].estVisitee = false;

    for (int i = 0; i < p.nbCases; ++i) {
        Coord c = { p.cases[i].coord.x, p.cases[i].coord.y };
        if (sous_recherche(p, mot, 0, c))
            return true;
    }
    return false;
}

bool sous_recherche(const PlateauMots& p, const Mot mot, const int pos, Coord& c) {
    if (pos >= strlen(mot))
        return true;
    if (!(c.x >= 0 && c.x < p.x_max && c.y >= 0 && c.y < p.y_max))
        return false;
    Case& ca = at(p, c); // les coordonnées correspondent à une case du plateau, on la récupère
    if (ca.lettre != mot[pos])
        return false;
    if (ca.estVisitee)
        return false;
    ca.estVisitee = true;

    Coord* c_adjacentes = adjacentes(c);

    for (int i = 0; i < 8; ++i)
        if (sous_recherche(p, mot, pos + 1, c_adjacentes[i])) {
            delete[] c_adjacentes;
            return true;
        }
    ca.estVisitee = false;
    delete[] c_adjacentes;
    return false;
}

Coord* adjacentes(const Coord c) {
    auto* c_adjacentes = new Coord[8];

    // HAUT GAUCHE
    c_adjacentes[0].x = c.x - 1;
    c_adjacentes[0].y = c.y - 1;
    // HAUT
    c_adjacentes[1].x = c.x - 1;
    c_adjacentes[1].y = c.y;
    // HAUT DROITE
    c_adjacentes[2].x = c.x - 1;
    c_adjacentes[2].y = c.y + 1;
    // GAUCHE
    c_adjacentes[3].x = c.x;
    c_adjacentes[3].y = c.y - 1;
    // DROITE
    c_adjacentes[4].x = c.x;
    c_adjacentes[4].y = c.y + 1;
    // BAS GAUCHE
    c_adjacentes[5].x = c.x + 1;
    c_adjacentes[5].y = c.y - 1;
    // BAS
    c_adjacentes[6].x = c.x + 1;
    c_adjacentes[6].y = c.y;
    // BAS DROITE
    c_adjacentes[7].x = c.x + 1;
    c_adjacentes[7].y = c.y + 1;

    return c_adjacentes;
}
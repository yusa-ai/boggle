/**
 * @file PlateauMots.h
 * @brief Plateau de mots
 */

#ifndef SDA_PROJET_PLATEAUMOTS_H
#define SDA_PROJET_PLATEAUMOTS_H

#include "Mot.h"

struct Coord {
    int x;
    int y;
};

struct Case {
    Coord coord;
    char lettre;
    bool estVisitee;
};

struct PlateauMots {
    int x_max = 4;
    int y_max = 4;
    int nbCases = x_max * y_max;
    Case* cases = new Case[nbCases];
};

/**
 * Renvoie la case du plateau de mots correspondant à une position donnée. Les
 * coordonnées doivent être dans les bornes du plateau.
 * @param p : le plateau de mots
 * @param c : la coordonnée de la case
 * @return la case
 */
Case& at(const PlateauMots& p, const Coord& c);

/**
 * Recherche un mot sur un plateau de mots selon les règles du Boogle et indique
 * s'il a été trouvé.
 * @param p : le plateau de mots
 * @param mot : le mot à chercher
 * @return vrai ou faux (selon que le mot ait été trouvé ou non)
 */
bool recherche(const PlateauMots& p, const Mot mot);

/**
 * Algorithme récursif de recherche de la présence d'un mot sur un plateau de
 * mots (Boogle).
 * @see recherche
 * @param p : le plateau de mots
 * @param mot : le mot à chercher
 * @param pos : la position de début du mot dans le mot qu'on essaie de placer
 * @param c : la coordonnée à partir de laquelle on essaie de placer le mot
 * @return vrai ou faux (selon que le mot ait été trouvé ou non)
 */
bool sous_recherche(const PlateauMots& p, const Mot mot, int pos, Coord& c);

/**
 * Renvoie les huit coordonnées adjacentes à une coordonnée donnée.
 * @param c la coordonnée
 * @return le tableau de ses huit coordonnées adjacentes
 */
Coord* adjacentes(Coord c);

#endif //SDA_PROJET_PLATEAUMOTS_H

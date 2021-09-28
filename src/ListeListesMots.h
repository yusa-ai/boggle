/**
 * @file ListeListesMots.h
 * @brief Liste de listes de mots
 */

#ifndef SDA_PROJET_LISTELISTESMOTS_H
#define SDA_PROJET_LISTELISTESMOTS_H

#include "ListeMots.h"

struct ListeListesMots {
    int capacite = 10;
    ListeMots* listes = new ListeMots[capacite];
    int nb = 0;
};

/**
 * Lit les listes de mots en entrée et les stocke.
 * @param listes : la liste de listes de mots
 */
void get_listes(ListeListesMots& listes);

/**
 * Vérifie si une liste de listes de mots a besoin d'être étendue et, le cas
 * échéant, réalise l'opération.
 * @param listes : la liste de listes de mots
 */
void etendre(ListeListesMots& listes);

/**
 * Détruit une liste de liste de mots.
 * @param listes : la liste de listes de mot
 */
void detruire(ListeListesMots& listes);

/**
 * Fusionne les listes contenues dans la liste de listes en une seule liste de
 * mots.
 * @param listes : la liste de listes de mots
 * @return la fusion de toutes les listes sous une seule liste de mots
 */
ListeMots fusionner(ListeListesMots& listes);

#endif //SDA_PROJET_LISTELISTESMOTS_H
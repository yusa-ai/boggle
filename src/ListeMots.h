/**
 * @file ListeMots.h
 * @brief Composant de liste de mots de capacité extensible.
 */

#ifndef SDA_PROJET_LISTEMOTS_H
#define SDA_PROJET_LISTEMOTS_H

#include "Mot.h"

#define LISTE_CAPACITE 10
#define LISTE_PAS 2

struct ListeMots {
    unsigned int capacite = LISTE_CAPACITE;
    unsigned int pas = LISTE_PAS;
    Mot* mots = new Mot[LISTE_CAPACITE];
    unsigned int nbMots = 0;
};

/**
 * @brief Désalloue un conteneur d'items en mémoire dynamique.
 * @see initialiser.
 * @param[in,out] c Le conteneur d'items.
 */
void detruire(ListeMots& l);

/**
 * Renvoie le nombre de mots d'une liste de mots.
 * @param l : la liste de mots
 * @return la longueur de la liste
 */
unsigned int longueur(const ListeMots& l);

/**
 * @brief Lecture d'un item d'un conteneur d'items.
 * @param[in] c Le conteneur d'items.
 * @param[in] i La position de l'item dans le conteneur.
 * @return L'item à la position i.
 * @pre i < c.capacite
 */
Mot& lire(const ListeMots& l, unsigned int i);

/**
 * @brief Ecrire un item dans un conteneur d'items.
 * @param[in,out] c Le conteneur d'items.
 * @param[in] i La position où ajouter/modifier l'item.
 * @param[in] it L'item à écrire.
 */
void ecrire(ListeMots& l, unsigned int i, const Mot& it);

/**
 * Insère un mot dans une liste à une position donnée.
 * @param l : la liste de mots
 * @param pos : la position dans la liste
 * @param it : le mot à insérer
 */
void inserer(ListeMots& l, unsigned int pos, const Mot& it);

/**
 * Supprime le mot dans une liste à la position donnée.
 * @param l : la liste de mots
 * @param pos : la position
 */
void supprimer(ListeMots& l, unsigned int pos);

/**
 * Renvoie une copie de la liste passée en paramètre.
 * @param l : la liste de mots à copier
 * @return une copie de cette liste sous forme d'une nouvelle liste de mots
 */
ListeMots copier(const ListeMots& l);

#endif //SDA_PROJET_LISTEMOTS_H

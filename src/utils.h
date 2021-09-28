/**
 * @file utils.h
 * @brief Fonctions utilitaires pour la réalisation des exercices du projet
 */

#ifndef SDA_PROJET_UTILS_H
#define SDA_PROJET_UTILS_H

#include "ListeListesMots.h"

/**
 * Lit et stocke les mots en entrée dans une liste de mots.
 * @param liste : la liste de mots
 */
void get_mots(ListeMots& liste);

/**
 * Lit un mot et renvoie son nombre de points correspondant.
 * @param mot : le mot à évaluer
 * @return le nombre de points correspondant
 */
int evaluer(const Mot mot);

/**
 * Affiche une liste de mots.
 * @param liste : la liste de mots
 */
void afficher(const ListeMots& liste);

/**
 * Trie alphabétiquement et supprime les doublons d'une liste de mots.
 * @param liste : la liste de mots
 */
void canonique(ListeMots& liste);

/**
 * Cherche un mot dans une liste de mots.
 * @param liste : la liste de mots
 * @param mot : le mot à chercher
 * @return vrai ou faux (selon que le mot ait été trouvé ou non)
 */
bool chercher(const ListeMots& liste, const Mot mot);

/**
 * Cherche un mot dans une liste de mots et renvoie sa position si trouvé.
 * @param liste : la liste de mots
 * @param mot : le mot à chercher
 * @param index : variable dans laquelle stocker la position du mot dans la
 * liste si trouvé (vaut -1 sinon)
 * @return vrai ou faux (selon que le mot ait été trouvé ou non)
 */
bool chercher(const ListeMots& liste, const Mot mot, int& index);

/**
 * Soustraie une liste à une autre liste : les occurences du mot de la seconde
 * liste dans la première seront toutes supprimées.
 * @param liste1 : la liste de mots à modifier
 * @param liste2 : la liste de mots dont on veut supprimer les mots dans la
 * première
 */
void sub(ListeMots& liste1, const ListeMots& liste2);

#endif //SDA_PROJET_UTILS_H

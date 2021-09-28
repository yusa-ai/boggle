/**
 * @file main.cpp
 * @brief Interface d'exécution des six exercices du projet
 */

#include <iostream>
#include "exercices.h"
using namespace std;

int main() {

    int num;
    cin >> num;
    switch (num) {
    case 1:
        ex1();
        break;
    case 2:
        ex2();
        break;
    case 3:
        ex3();
        break;
    case 4:
        ex4();
        break;
    case 5:
        ex5();
        break;
    case 6:
        ex6();
        break;
    default:
        cout << "numero d'exercice inconnu";
    }

    return 0;
}

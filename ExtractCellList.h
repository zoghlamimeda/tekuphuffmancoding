//
// Created by mzoghlami on 06/05/2020.
//

#ifndef HUFFMANCODING_EXTRACTCELLLIST_H
#define HUFFMANCODING_EXTRACTCELLLIST_H

#endif //HUFFMANCODING_EXTRACTCELLLIST_H
typedef struct cell {
    char caracter;
    int frequency;
    int paritee;
    struct cell *pere;
    struct cell *fils_droit;
    struct cell *fils_gauche;
    struct cell *suiv;
} Cell;

Cell *createListe(char *str);
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "ExtractCellList.h"
#include "siwar.h"

//
// Created by mzoghlami & sgaddour on 02/05/2020.
//


void displayCellList(Cell *CellList) {
    printf("\n****************************\n");
    Cell *runner = NULL;
    runner = CellList;
    while (runner != NULL) {
        printf("caracter : %c ; frequency : %d \n", runner->caracter, runner->frequency);
        runner = runner->suiv;
    }
    printf("****************************\n");
}


int main() {


    //CHAINE DE CHARACTERE A UTILISER
    char str[] = "satisfaisant";

    //LISTE CHAINEE A REMPLIR
    Cell *ListeChainee=NULL;

    //FONCTION extractLinkedList(char *str) NECESSAIRE
    //ListeChainee = extractLinkedList(str);
    ListeChainee=createListe(str);
    displayCellList(ListeChainee);


    return 1;
}



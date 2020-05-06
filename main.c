#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//
// Created by mzoghlami & sgaddour on 02/05/2020.
//

typedef struct cell {
    char caracter;
    int frequency;
    int paritee;
    struct cell *pere;
    struct cell *fils_droit;
    struct cell *fils_gauche;
    struct cell *suiv;
} Cell;

/*
 * started merging stuff
 */


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

int contains(Cell *Liste, char caracter){

    if( Liste==NULL)
        return 0;
    else {
        Cell *point=Liste;
        while (point !=NULL){
            if(point->caracter==caracter)
                return 1;
            else
                point=point->suiv;
        }
                return 0;

    }


}
void increaseFrequency(Cell *Liste,char caracter){
Cell *point=Liste;
    while (point!=NULL){
        if(point->caracter==caracter){
            point->frequency++;
            return;
            }
            else
            point=point->suiv;
    }
}
Cell *addNewCaracter(Cell *Liste,char caracter){

Cell *point=(Cell *) malloc(sizeof(Cell));
point->caracter=caracter;
point->frequency=1;
point->suiv=NULL;
point->pere=NULL;
point->fils_droit=NULL;
point->fils_gauche=NULL;
point->paritee=-1;
    if (Liste==NULL)
        Liste=point;
    else{
        Cell *pointeur=Liste;
        while(pointeur->suiv!=NULL){
        pointeur=pointeur->suiv;
        }
        pointeur->suiv=point;
        }
        return Liste;
}

Cell *createListe(char *str){

    Cell *Liste=NULL;
int i=0;
while(str[i]!='\0')
{
    char curentCaracter=str[i];
    if(contains(Liste,curentCaracter)==1){
            increaseFrequency(Liste,curentCaracter);
        }else
        {
            Liste=addNewCaracter(Liste,curentCaracter);
        }
    i++;

}
return Liste;
}
int main() {

    int test = 0;
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



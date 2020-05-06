//
// Created by mzoghlami on 06/05/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "ExtractCellList.h"


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

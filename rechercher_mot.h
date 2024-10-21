//
// Created by cambo on 13/11/2022.
//

#ifndef GENERATEUR_DE_PHRASE_RECHERCHER_MOT_H
#define GENERATEUR_DE_PHRASE_RECHERCHER_MOT_H

#include "creation_arbre_adverbe.h"




char* getEmptyTab1(long);


int isSameStr3(char***, long , char*, long);


long countLine(char***, long, char*, long);


void printLine(char***, long);


void showLine(char***, long, char*, long);


void showSmallStr(char*, long);


void rechercherMots(char***, long, long, char *);





#endif //GENERATEUR_DE_PHRASE_RECHERCHER_MOT_H

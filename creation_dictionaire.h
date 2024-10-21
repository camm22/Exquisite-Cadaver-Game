//
// Created by cambo on 10/11/2022.
//

#ifndef GENERATEUR_DE_PHRASE_CREATION_DICTIONAIRE_H
#define GENERATEUR_DE_PHRASE_CREATION_DICTIONAIRE_H


#include <stdlib.h>
#include <stdio.h>
#include <time.h>


long getNbLineDictionary(char* parcours);

char*** createDictionary(char*, long, long, long);

char*** createEmptyDictionary(long, long, long);

void displayDictionary(char***, long, long);






#endif //GENERATEUR_DE_PHRASE_CREATION_DICTIONAIRE_H

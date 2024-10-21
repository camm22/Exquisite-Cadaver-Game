//
// Created by cambo on 13/11/2022.
//

#ifndef GENERATEUR_DE_PHRASE_BASE_ALEATOIRE_H
#define GENERATEUR_DE_PHRASE_BASE_ALEATOIRE_H


#include "rechercher_mot.h"



int getNbElementAdverbe(p_letter_adverbe);
char* adverbeBase(t_adverbe_tree*, long);


int getNbElementNA(p_letter_NA);
char* NABase(t_NA_tree*, long);


int getNbElementVerbe(p_letter_verb);
char* verbeBase(t_verb_tree*, long);



void dispalyBase(char*);




#endif //GENERATEUR_DE_PHRASE_BASE_ALEATOIRE_H

//
// Created by cambo on 10/11/2022.
//

#ifndef GENERATEUR_DE_PHRASE_CREATION_ARBRE_VERBE_H
#define GENERATEUR_DE_PHRASE_CREATION_ARBRE_VERBE_H

#include "creation_tableau_distinct.h"

#define MAX_ALPHABET 29


//Définition des structures :


//Stock la forme fléchée du mot
typedef struct s_mots_verb{
    int size;
    char *tab_mots;

}t_mots_verb, *p_mots_verb;


//Stock les 3 personnes
typedef struct s_personne_verb{
    p_mots_verb P1;
    p_mots_verb P2;
    p_mots_verb P3;

}t_personne_verb, *p_personne_verb;


//Stock le nombre des personnes
typedef struct s_nombre_verb{
    p_personne_verb SG;
    p_personne_verb PL;

}t_nombre_verb, *p_nombre_verb;


//Stock les temps des verbes traités
typedef struct s_temps_verb{
    p_nombre_verb IPre;
    p_nombre_verb IImp;
    p_nombre_verb SPre;

}t_temps_verb, *p_temps_verb;


//Stock une lettre de la forme de base
typedef struct s_letter_verb{
    char value;
    struct s_letter_verb *suite[MAX_ALPHABET];
    int position;

    p_temps_verb fleche;

}t_letter_verb, *p_letter_verb;


//Stock l'arbre des verbes
typedef struct s_verb_tree{
    p_letter_verb root_letter[MAX_ALPHABET];
}t_verb_tree;




//Prototype des fonctions :


p_mots_verb createEmptyWordVerb(void);
p_personne_verb createEmptyPersonneVerb(void);
p_nombre_verb createEmptyNombreVerb(void);
p_temps_verb createEmptyTimeVerb(void);


p_letter_verb createLetter(char*, int);


//Fonction importante
int getPositionAlphabet(char*, char);


t_verb_tree initializeTreeVerb(char*);


//Fonction importante
char* getTab(char***, long, long, long);


p_letter_verb searchLetter(t_verb_tree*, char*, char*);


//Fonction importante
int isSameStr(char*, int, char*);


//Fonction importante
int getSizeWord(char*);


void writeVerbInTree(p_letter_verb, char*, char*);


t_verb_tree createTreeVerb(char***, long, long, char*);



void test(char*);



#endif //GENERATEUR_DE_PHRASE_CREATION_ARBRE_VERBE_H

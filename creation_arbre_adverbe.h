//
// Created by cambo on 13/11/2022.&
//

#ifndef GENERATEUR_DE_PHRASE_CREATION_ARBRE_ADVERBE_H
#define GENERATEUR_DE_PHRASE_CREATION_ARBRE_ADVERBE_H

#include "creation_arbre_nom_adjectif.h"



//Définition des structures :



//Stock la forme fléchée du mot (qui est donc pareille que la forme de base)
typedef struct s_mots_adverbe{
    int size;
    char *tab_mots;

}t_mots_adverbe, *p_mots_adverbe;



//Stock une lettre de la forme de base
typedef struct s_letter_adverbe{
    char value;
    struct s_letter_adverbe *suite[MAX_ALPHABET];
    int position;

    p_mots_adverbe fleche;

}t_letter_adverbe, *p_letter_adverbe;


//Stock l'arbre des adverbes
typedef struct s_adverbe_tree{
    p_letter_adverbe root_letter[MAX_ALPHABET];
}t_adverbe_tree;




//Prototype des fonctions :


p_mots_adverbe createEmptyWordAdverbe(void);


p_letter_adverbe createLetterAdverbe(char*, int);


t_adverbe_tree initializeTreeAdverbe(char*);


p_letter_adverbe searchLetterAdverbe(t_adverbe_tree*, char*, char*);


void writeAdverbeInTree(p_letter_adverbe, char*, char*);


t_adverbe_tree createTreeAdverbe(char***, long, long, char*);




#endif //GENERATEUR_DE_PHRASE_CREATION_ARBRE_ADVERBE_H

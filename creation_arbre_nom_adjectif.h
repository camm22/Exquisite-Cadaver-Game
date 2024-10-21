//
// Created by cambo on 13/11/2022.
//

#ifndef GENERATEUR_DE_PHRASE_CREATION_ARBRE_NOM_ADJECTIF_H
#define GENERATEUR_DE_PHRASE_CREATION_ARBRE_NOM_ADJECTIF_H

#include "creation_arbre_verbe.h"



//Définition des structures :



//Stock la forme fléchée du mot
typedef struct s_mots_NA{
    int size;
    char *tab_mots;

}t_mots_NA, *p_mots_NA;


//Stock le nombre
typedef struct s_nombre_NA{
    p_mots_NA SG;
    p_mots_NA PL;
    p_mots_NA InvPL;

}t_nombre_NA, *p_nombre_NA;


//Stock le genre
typedef struct s_genre_NA{
    p_nombre_NA Mas;
    p_nombre_NA Fem;
    p_nombre_NA InvGen;

}t_genre_NA, *p_genre_NA;



//Stock une lettre de la forme de base
typedef struct s_letter_NA{
    char value;
    struct s_letter_NA *suite[MAX_ALPHABET];
    int position;

    p_genre_NA fleche;

}t_letter_NA, *p_letter_NA;



//Stock l'arbre des noms ou des adjectifs
typedef struct s_NA_tree{
    p_letter_NA root_letter[MAX_ALPHABET];
}t_NA_tree;




//Prototype des fonctions :



p_mots_NA createEmptyWordNA(void);
p_nombre_NA createEmptyNombreNA(void);
p_genre_NA createEmptyGenreNA(void);



p_letter_NA createLetterNA(char*, int);



t_NA_tree initializeTreeNA(char*);



p_letter_NA searchLetterNA(t_NA_tree*, char*, char*);



void writeNAInTree(p_letter_NA, char*, char*);


t_NA_tree createTreeNA(char***, long, long, char*);





void test2(char***, long, long, long);






#endif //GENERATEUR_DE_PHRASE_CREATION_ARBRE_NOM_ADJECTIF_H

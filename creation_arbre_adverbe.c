#include "creation_arbre_adverbe.h"



//fonction qui permet d'initialiser la structure qui compose l'arbre des adverbes pour y ajouter les formes fléchies
p_mots_adverbe createEmptyWordAdverbe(void){
    p_mots_adverbe temp;
    temp = (p_mots_adverbe) malloc(1 * sizeof (t_mots_adverbe));
    temp->size = 0;
    temp->tab_mots = NULL;
    return temp;
}



//Fonction qui crée une lettre (c'est donc une structure) qui sera stocker dans l'arbre
p_letter_adverbe createLetterAdverbe(char *alphabet, int pos){

    p_letter_adverbe new_letter = (p_letter_adverbe) malloc(1 * sizeof (t_letter_adverbe));

    new_letter->value = alphabet[pos];

    new_letter->position = pos;

    for (int i=0; i<MAX_ALPHABET; i++){
        new_letter->suite[i] = NULL;
    }

    new_letter->fleche = NULL;

    return new_letter;
}



//Initialise la première "couche de lettre" de adverbe_tree
t_adverbe_tree initializeTreeAdverbe(char* alphabet){
    t_adverbe_tree mytree_adverbe;
    int pos;
    for (int i=0; i<MAX_ALPHABET; i++){
        pos = getPositionAlphabet(alphabet, alphabet[i]);
        mytree_adverbe.root_letter[pos] = createLetterAdverbe(alphabet, pos);
    }
    return mytree_adverbe;
}



//Fonction qui permet der trouver la dernière lettre de l'une des bases de adverbe_tree afin d'y ajouter plus tard les formes fléchées
p_letter_adverbe searchLetterAdverbe(t_adverbe_tree *mytree_adverbe, char *base, char* alphabet){

    p_letter_adverbe temp = NULL;

    int k_base = 0, pos;

    while (base[k_base] != '.'){
        pos = getPositionAlphabet(alphabet, base[k_base]);

        if (k_base == 0){
            temp = mytree_adverbe->root_letter[pos];
        }

        else{
            temp = temp->suite[pos];
        }

        k_base++;
    }
    return temp;
}

//Fonction qui ajoute les adverbes fléchis à l'arbre correspondant
void writeAdverbeInTree(p_letter_adverbe temp, char *fleche, char *cat){
    temp->fleche->tab_mots = fleche;
    temp->fleche->size = getSizeWord(fleche);
}

//Fonction qui permet de créer l'arbre qui contient les adverbes
t_adverbe_tree createTreeAdverbe(char*** tab, long i_max_tab, long k_max_tab, char *alphabet){

    t_adverbe_tree mytree_adverbe = initializeTreeAdverbe(alphabet);

    p_letter_adverbe temp;

    long i_tab, j_tab = 1, k_tab = 0;
    int pos;

    //On met toutes les formes de base des adverbes dans l'arbre lettre par lettre
    for (i_tab=0; i_tab<i_max_tab; i_tab++){

        while(tab[i_tab][j_tab][k_tab] != '\t'){
            pos = getPositionAlphabet(alphabet, tab[i_tab][j_tab][k_tab]);
            if (k_tab == 0){
                temp = mytree_adverbe.root_letter[pos];
            }
            else {
                if (temp->suite[pos] == NULL){
                    temp->suite[pos] = createLetterAdverbe(alphabet, pos);
                }
                temp = temp->suite[pos];
            }
            k_tab++;
        }
        k_tab = 0;
    }

    temp = NULL;

    char *base;
    char *fleche;
    char *cat;

    for (i_tab=0; i_tab<i_max_tab; i_tab++){

        base = getTab(tab, i_tab, 1, k_max_tab);
        fleche = getTab(tab, i_tab, 0, k_max_tab);
        cat = getTab(tab, i_tab, 2, k_max_tab);

        temp = searchLetterAdverbe(&mytree_adverbe, base, alphabet);
        temp->fleche = createEmptyWordAdverbe();

        writeAdverbeInTree(temp, fleche, cat);
    }

    return mytree_adverbe;
}

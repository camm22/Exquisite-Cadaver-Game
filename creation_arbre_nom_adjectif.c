#include "creation_arbre_nom_adjectif.h"



//fonctions qui permettent d'initialiser toutes les structures qui composent l'arbre des noms ou des adjectifs
p_mots_NA createEmptyWordNA(void){
    p_mots_NA temp;
    temp = (p_mots_NA) malloc(1 * sizeof (t_mots_NA));
    temp->size = 0;
    temp->tab_mots = NULL;
    return temp;
}
p_nombre_NA createEmptyNombreNA(void){
    p_nombre_NA temp;
    temp = (p_nombre_NA) malloc(1 * sizeof (t_nombre_NA));
    temp->PL = createEmptyWordNA();
    temp->SG = createEmptyWordNA();
    temp->InvPL = createEmptyWordNA();
    return temp;
}
p_genre_NA createEmptyGenreNA(void){
    p_genre_NA temp;
    temp = (p_genre_NA ) malloc(1* sizeof (t_genre_NA));
    temp->Mas = createEmptyNombreNA();
    temp->Fem = createEmptyNombreNA();
    temp->InvGen = createEmptyNombreNA();
    return temp;
}


//Fonction qui crée une lettre (c'est donc une structure) qui sera stocker dans l'arbre
p_letter_NA createLetterNA(char *alphabet, int pos){

    p_letter_NA new_letter = (p_letter_NA) malloc(1 * sizeof (t_letter_NA));

    new_letter->value = alphabet[pos];

    new_letter->position = pos;

    for (int i=0; i<MAX_ALPHABET; i++){
        new_letter->suite[i] = NULL;
    }

    new_letter->fleche = NULL;

    return new_letter;
}



//Initialise la première "couche de lettre" de NA_tree
t_NA_tree initializeTreeNA(char* alphabet){
    t_NA_tree mytree_NA;
    int pos;
    for (int i=0; i<MAX_ALPHABET; i++){
        pos = getPositionAlphabet(alphabet, alphabet[i]);
        mytree_NA.root_letter[pos] = createLetterNA(alphabet, pos);
    }
    return mytree_NA;
}



//Fonction qui permet der trouver la dernière lettre de l'une des bases de NA_tree afin d'y ajouter plus tard les formes fléchées
p_letter_NA searchLetterNA(t_NA_tree *mytree_NA, char *base, char* alphabet){

    p_letter_NA temp = NULL;

    int k_base = 0, pos;

    while (base[k_base] != '.'){
        pos = getPositionAlphabet(alphabet, base[k_base]);

        if (k_base == 0){
            temp = mytree_NA->root_letter[pos];
        }

        else{
            temp = temp->suite[pos];
        }

        k_base++;
    }
    return temp;
}


//Fonction qui ajoute les noms ou adjectifs fléchis à l'arbre correspondant
void writeNAInTree(p_letter_NA temp, char *fleche, char *cat){

    p_letter_NA svg = temp;

    p_nombre_NA nombre = createEmptyNombreNA();

    char str1[10];
    int size_str1 = 0;

    char str2[10];
    int size_str2 = 0;

    char Mas[3] = "Mas";
    char Fem[3] = "Fem";
    char InvGen[6] = "InvGen";

    char SG[2] = "SG";
    char PL[2] = "PL";
    char InvPL[5] = "InvPL";

    int d_cat = 4;

    while(1){

        while(cat[d_cat] != '+' && cat[d_cat] != '.'){
            str1[size_str1] = cat[d_cat];
            size_str1++;
            d_cat++;
        }

        if (isSameStr(str1, size_str1, Mas) == 1){
            nombre = temp->fleche->Mas;
        }
        else if (isSameStr(str1, size_str1, Fem) == 1){
            nombre = temp->fleche->Fem;
        }
        else if (isSameStr(str1, size_str1, InvGen) == 1){
            nombre = temp->fleche->InvGen;
        }

        d_cat++;
        while (cat[d_cat] != '.' && cat[d_cat] != ':') {
            str1[size_str2] = cat[d_cat];
            size_str2++;
            d_cat++;
        }

        if (isSameStr(str2, size_str2, SG) == 1){
            nombre->SG->tab_mots = fleche;
            nombre->SG->size = getSizeWord(fleche);
        }
        else if (isSameStr(str2, size_str2, PL) == 1){
            nombre->PL->tab_mots = fleche;
            nombre->PL->size = getSizeWord(fleche);
        }
        else if (isSameStr(str2, size_str2, InvPL) == 1){
            nombre->InvPL->tab_mots = fleche;
            nombre->InvPL->size = getSizeWord(fleche);
        }

        if (cat[d_cat] == ':'){

            temp = svg;
            d_cat++;
            size_str1 = 0;
            size_str2 = 0;
        }
        else if (cat[d_cat] == '.'){

            break;
        }

    }

}

//Fonction qui permet de tester quand il y a des erreurs
void test2(char*** tab, long i, long j, long k){
    while(tab[i][j][k] != '\t'){
        printf("%c",tab[i][j][k]);
        k++;
    }
    printf("\n");
}


//Fonction qui permet de créer l'arbre qui contient les noms ou les adjectifs
t_NA_tree createTreeNA(char*** tab, long i_max_tab, long k_max_tab, char *alphabet){

    t_NA_tree mytree_NA = initializeTreeNA(alphabet);

    p_letter_NA temp;

    long i_tab, j_tab = 1, k_tab = 0;
    int pos;

    //On met toutes les formes de base des noms ou des adjectifs dans l'arbre lettre par lettre
    for (i_tab=0; i_tab<i_max_tab; i_tab++){

        while(tab[i_tab][j_tab][k_tab] != '\t'){
            pos = getPositionAlphabet(alphabet, tab[i_tab][j_tab][k_tab]);
            if (k_tab == 0){
                temp = mytree_NA.root_letter[pos];
            }
            else {
                if (temp->suite[pos] == NULL){
                    temp->suite[pos] = createLetterNA(alphabet, pos);
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

        temp = searchLetterNA(&mytree_NA, base, alphabet);
        temp->fleche = createEmptyGenreNA();

        writeNAInTree(temp, fleche, cat);

    }

    return mytree_NA;
}

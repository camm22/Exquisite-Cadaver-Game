#include "creation_arbre_verbe.h"


//fonctions qui permettent d'initialiser toutes les structures qui composent l'arbre des verbes
p_mots_verb createEmptyWordVerb(void){
    p_mots_verb temp;
    temp = (p_mots_verb) malloc(1 * sizeof (t_mots_verb));
    temp->size = 0;
    temp->tab_mots = NULL;
    return temp;
}
p_personne_verb createEmptyPersonneVerb(void){
    p_personne_verb temp;
    temp = (p_personne_verb) malloc(1 * sizeof (t_personne_verb));
    temp->P1 = createEmptyWordVerb();
    temp->P2 = createEmptyWordVerb();
    temp->P3 = createEmptyWordVerb();
    return temp;
}
p_nombre_verb createEmptyNombreVerb(void){
    p_nombre_verb temp;
    temp = (p_nombre_verb) malloc(1 * sizeof (t_nombre_verb));
    temp->SG = createEmptyPersonneVerb();
    temp->PL = createEmptyPersonneVerb();
    return temp;
}
p_temps_verb createEmptyTimeVerb(void){
    p_temps_verb temp;
    temp = (p_temps_verb) malloc(1 * sizeof (t_temps_verb));
    temp->SPre = createEmptyNombreVerb();
    temp->IPre = createEmptyNombreVerb();
    temp->IImp = createEmptyNombreVerb();
    return temp;
}


//Fonction qui crée une lettre (c'est donc une structure) qui sera stocker dans l'arbre des verbes
p_letter_verb createLetter(char *alphabet, int pos){

    p_letter_verb new_letter = (p_letter_verb) malloc(1 * sizeof (t_letter_verb));

    new_letter->value = alphabet[pos];

    new_letter->position = pos;

    for (int i=0; i<MAX_ALPHABET; i++){
        new_letter->suite[i] = NULL;
    }

    new_letter->fleche = NULL;

    return new_letter;
}


//Initialise la première "couche de lettre" de verb_tree
t_verb_tree initializeTreeVerb(char* alphabet){
    t_verb_tree mytree_verb;
    int pos;
    for (int i=0; i<MAX_ALPHABET; i++){
        pos = getPositionAlphabet(alphabet, alphabet[i]);
        mytree_verb.root_letter[pos] = createLetter(alphabet, pos);
    }
    return mytree_verb;
}



//Fonction qui renvoie le numéro de la lettre dans l'alphabet
int getPositionAlphabet(char* alphabet, char mychar){
    for (int i=0; i<MAX_ALPHABET; i++){
        if (alphabet[i] == mychar){
            return i;
        }
    }
    return -1;
}


//Fonction qui renvoie un tableau dynamique à une dimension qui servira à ajouter les mots fléchés dans l'arbre
char* getTab(char*** dic, long i_dic, long j_dic, long k_max_dic){
    char* tab = NULL;
    tab = (char*) malloc(k_max_dic * sizeof (char));

    long k_dic = 0;

    while (dic[i_dic][j_dic][k_dic] != '\t' && dic[i_dic][j_dic][k_dic] != '\n'){
        tab[k_dic] = dic[i_dic][j_dic][k_dic];
        k_dic ++;
    }
    tab[k_dic] = '.';

    return tab;
}




//Fonction qui permet der trouver la dernière lettre de l'une des bases de verbe afin d'y ajouter plus tard les formes fléchées
p_letter_verb searchLetter(t_verb_tree *mytree_verb, char *base, char* alphabet){

    p_letter_verb temp = NULL;

    int k_base = 0, pos;

    while (base[k_base] != '.'){
        pos = getPositionAlphabet(alphabet, base[k_base]);

        if (k_base == 0){
            temp = mytree_verb->root_letter[pos];
        }

        else{
            temp = temp->suite[pos];
        }

        k_base++;
    }
    return temp;
}


//Fonction qui vérifie si deux str sont égaux
int isSameStr(char* str1, int size_str, char* str2){
    int veri = 1;
    for (int i=0; i<size_str; i++){
        if (str1[i] != str2[i]){
            veri *= 0;
        }
        else{
            veri *= 1;
        }
    }
    return veri;
}

//Fonction qui renvoie la taille d'un str
int getSizeWord(char* word){
    int size = 0;
    while(word[size] != '.'){
        size++;
    }
    return size;
}




//Fonction qui ajoute les verbes fléchis à l'arbre
void writeVerbInTree(p_letter_verb temp, char *fleche, char *cat){

    p_letter_verb svg = temp;

    p_nombre_verb nombre = createEmptyNombreVerb();
    p_personne_verb personne = createEmptyPersonneVerb();

    char str1[10];
    int size_str1 = 0;

    char str2[10];
    int size_str2 = 0;

    char str3[10];
    int size_str3 = 0;

    char IPre[4] = "IPre";
    char IImp[4] = "IImp";
    char SPre[4] = "SPre";

    char SG[2] = "SG";
    char PL[2] = "PL";

    char P1[2] = "P1";
    char P2[2] = "P2";
    char P3[2] = "P3";

    int d_cat = 4;
    int veri = 0;

    while(1){

        while(cat[d_cat] != '+' && cat[d_cat] != '.'){
            str1[size_str1] = cat[d_cat];
            size_str1++;
            d_cat++;
        }


        if (isSameStr(str1, size_str1, IPre) == 1){
            nombre = temp->fleche->IPre;
            veri = 1;
        }
        else if (isSameStr(str1, size_str1, IImp) == 1){
            nombre = temp->fleche->IImp;
            veri = 1;
        }
        else if (isSameStr(str1, size_str1, SPre) == 1){
            nombre = temp->fleche->SPre;
            veri = 1;
        }

        if (veri == 1) {

            d_cat++;
            while (cat[d_cat] != '+') {
                str1[size_str2] = cat[d_cat];
                size_str2++;
                d_cat++;
            }


            if (isSameStr(str2, size_str2, SG) == 1) {
                personne = nombre->SG;
            } else if (isSameStr(str2, size_str2, PL) == 1) {
                personne = nombre->PL;
            }


            d_cat++;
            while (cat[d_cat] != '.' && cat[d_cat] != ':') {
                str1[size_str3] = cat[d_cat];
                size_str3++;
                d_cat++;
            }


            if (isSameStr(str3, size_str3, P1) == 1) {
                personne->P1->tab_mots = fleche;
                personne->P1->size = getSizeWord(fleche);
            } else if (isSameStr(str3, size_str3, P2) == 1) {
                personne->P2->tab_mots = fleche;
                personne->P2->size = getSizeWord(fleche);
            } else if (isSameStr(str3, size_str3, P3) == 1) {
                personne->P3->tab_mots = fleche;
                personne->P3->size = getSizeWord(fleche);
            }

        }
        else {
            while (cat[d_cat] != '.' && cat[d_cat] != ':') {
                d_cat++;
            }
        }

        if (cat[d_cat] == ':'){

            temp = svg;
            d_cat++;
            size_str1 = 0;
            size_str2 = 0;
            size_str3 = 0;
            veri = 0;
        }
        else if (cat[d_cat] == '.'){

            break;
        }

    }

}


//Fonction qui permet de tester quand il y a des erreurs
void test(char* tab){
    long i = 0;
    printf("\n");
    while (tab[i] != '.') {
        printf("%c", tab[i]);
        i++;
    }
    printf("%c\n", tab[i]);
}



//Fonction qui permet de créer l'arbre qui contient les verbes
t_verb_tree createTreeVerb(char*** tab, long i_max_tab, long k_max_tab, char *alphabet){

    t_verb_tree mytree_verb = initializeTreeVerb(alphabet);

    p_letter_verb temp;

   long i_tab, j_tab = 1, k_tab = 0;
   int pos;

    //On met toutes les formes de base des verbes dans l'arbre lettre par lettre
    for (i_tab=0; i_tab<i_max_tab; i_tab++){
        while(tab[i_tab][j_tab][k_tab] != '\t'){
            pos = getPositionAlphabet(alphabet, tab[i_tab][j_tab][k_tab]);
            if (k_tab == 0){
                temp = mytree_verb.root_letter[pos];
            }
            else {
                if (temp->suite[pos] == NULL){
                    temp->suite[pos] = createLetter(alphabet, pos);
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

        temp = searchLetter(&mytree_verb, base, alphabet);

        temp->fleche = createEmptyTimeVerb();

        writeVerbInTree(temp, fleche, cat);

    }

    return mytree_verb;
}

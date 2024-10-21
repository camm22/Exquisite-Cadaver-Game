#include "menu_generateur.h"


//Fonction qui gère la partie sur la génération de mot
void genererPhrase(t_verb_tree* mytree_verbe, t_NA_tree* mytree_nom, t_NA_tree* mytree_adjectif, t_adverbe_tree* mytree_adverbe, char *alphabet, long k_max){

    char*** articles = createEmptyDictionary(6,3,10);

    char*** pronoms = createEmptyDictionary(6,3,10);

    articles[0][0][0] = 'l';
    articles[0][0][1] = 'e';
    articles[0][0][2] = '.';
    articles[0][1][0] = 'M';
    articles[0][1][1] = 'a';
    articles[0][1][2] = 's';
    articles[0][1][3] = '.';
    articles[0][2][0] = 'S';
    articles[0][2][1] = 'G';
    articles[0][2][2] = '.';
    articles[1][0][0] = 'l';
    articles[1][0][1] = 'a';
    articles[1][0][2] = '.';
    articles[1][1][0] = 'F';
    articles[1][1][1] = 'e';
    articles[1][1][2] = 'm';
    articles[1][1][3] = '.';
    articles[1][2][0] = 'S';
    articles[1][2][1] = 'G';
    articles[1][2][2] = '.';
    articles[2][0][0] = 'u';
    articles[2][0][1] = 'n';
    articles[2][0][2] = '.';
    articles[2][1][0] = 'M';
    articles[2][1][1] = 'a';
    articles[2][1][2] = 's';
    articles[2][1][3] = '.';
    articles[2][2][0] = 'S';
    articles[2][2][1] = 'G';
    articles[2][2][2] = '.';
    articles[3][0][0] = 'u';
    articles[3][0][1] = 'n';
    articles[3][0][2] = 'e';
    articles[3][0][3] = '.';
    articles[3][1][0] = 'F';
    articles[3][1][1] = 'e';
    articles[3][1][2] = 'm';
    articles[3][1][3] = '.';
    articles[3][2][0] = 'S';
    articles[3][2][1] = 'G';
    articles[3][2][2] = '.';
    articles[4][0][0] = 'd';
    articles[4][0][1] = 'e';
    articles[4][0][2] = 's';
    articles[4][0][3] = '.';
    articles[4][1][0] = 'I';
    articles[4][1][1] = 'n';
    articles[4][1][2] = 'v';
    articles[4][1][3] = '.';
    articles[4][2][0] = 'P';
    articles[4][2][1] = 'L';
    articles[4][2][2] = '.';
    articles[5][0][0] = 'l';
    articles[5][0][1] = 'e';
    articles[5][0][2] = 's';
    articles[5][0][3] = '.';
    articles[5][1][0] = 'I';
    articles[5][1][1] = 'n';
    articles[5][1][2] = 'v';
    articles[5][1][3] = '.';
    articles[5][2][0] = 'P';
    articles[5][2][1] = 'L';
    articles[5][2][2] = '.';




    char* base_nom1 = NABase(mytree_nom, k_max);
    char* base_nom2 = NABase(mytree_nom, k_max);
    char * base_verbe1 = verbeBase(mytree_verbe, k_max);
    char * base_verbe2 = verbeBase(mytree_verbe, k_max);
    char* base_adjectif = NABase(mytree_adjectif, k_max);
    char* base_adverbe = adverbeBase(mytree_adverbe, k_max);



    printf("\nChoisissez un modele de phrase :\n  1) nom-adjectif-verbe-nom\n  2) nom-'qui'-verbe-verbe-nom-adjectif\n  3) verbe-adverbe-nom\n");

    char Choix;
    do {
        printf("\n{-} Entrer le numero du model choisit :");
        scanf(" %c", &Choix);
        printf("\n");
    } while (Choix != '1' && Choix != '2' && Choix != '3');

    if (Choix == '1'){
        printf("\n----> Forme de base : ");
        dispalyBase(base_nom1); printf(" ");
        dispalyBase(base_adjectif); printf(" ");
        dispalyBase(base_verbe1); printf(" ");
        dispalyBase(base_nom2);




        printf("\n\n----> Forme flechie : ");

        //model1(mytree_verbe, mytree_nom, mytree_adjectif, mytree_adverbe, alphabet, k_max, articles);

    }


    else if (Choix == '2'){



        printf("\n----> Forme de base : ");
        dispalyBase(base_nom1); printf(" qui ");
        dispalyBase(base_verbe1); printf(" ");
        dispalyBase(base_verbe2); printf(" ");
        dispalyBase(base_nom2); printf(" ");
        dispalyBase(base_adjectif);

        printf("\n\n----> Forme flechie : ");

    }


    else if (Choix == '3'){




        printf("\n----> Forme de base : ");
        dispalyBase(base_verbe1); printf(" ");
        dispalyBase(base_adverbe); printf(" ");
        dispalyBase(base_nom1);

        printf("\n\n----> Forme flechie : ");
    }


    printf("\n\n\n-----[menu-principal]-----\n\n");
    printf("Que voulez-vous faire ?\n  1- Generer une phrase\n  2- Rechercher un mot\n  3- Quitter le generateur\n");
}


/*

    pronoms[0][0][0] = 'j';
    pronoms[0][0][1] = 'e';
    pronoms[0][0][2] = '.';
    pronoms[0][1][0] = 'S';
    pronoms[0][1][1] = 'G';
    pronoms[0][1][2] = '.';
    pronoms[0][2][0] = 'P';
    pronoms[0][2][1] = '1';
    pronoms[0][2][2] = '.';
    pronoms[1][0][0] = 't';
    pronoms[1][0][1] = 'u';
    pronoms[1][0][2] = '.';
    pronoms[1][1][0] = 'S';
    pronoms[1][1][1] = 'G';
    pronoms[1][1][2] = '.';
    pronoms[1][2][0] = 'P';
    pronoms[1][2][1] = '2';
    pronoms[1][2][2] = '.';
    pronoms[2][0][0] = 'i';
    pronoms[2][0][1] = 'l';
    pronoms[2][0][2] = '.';
    pronoms[2][1][0] = 'S';
    pronoms[2][1][1] = 'G';
    pronoms[2][1][2] = '.';
    pronoms[2][2][0] = 'P';
    pronoms[2][2][1] = '3';
    pronoms[2][2][2] = '.';
    pronoms[3][0][0] = 'e';
    pronoms[3][0][1] = 'l';
    pronoms[3][0][2] = 'l';
    pronoms[3][0][3] = 'e';
    pronoms[3][0][4] = '.';
    pronoms[3][1][0] = 'S';
    pronoms[3][1][1] = 'G';
    pronoms[3][1][2] = '.';
    pronoms[3][2][0] = 'P';
    pronoms[3][2][1] = '3';
    pronoms[3][2][2] = '.';
    pronoms[4][0][0] = 'n';
    pronoms[4][0][1] = 'o';
    pronoms[4][0][2] = 'u';
    pronoms[4][0][3] = 's';
    pronoms[4][0][4] = '.';
    pronoms[4][1][0] = 'P';
    pronoms[4][1][1] = 'L';
    pronoms[4][1][2] = '.';
    pronoms[4][2][0] = 'P';
    pronoms[4][2][1] = '1';
    pronoms[4][2][2] = '.';
    pronoms[5][0][0] = 'v';
    pronoms[5][0][1] = 'o';
    pronoms[5][0][2] = 'u';
    pronoms[5][0][3] = 's';
    pronoms[5][0][4] = '.';
    pronoms[5][1][0] = 'P';
    pronoms[5][1][1] = 'L';
    pronoms[5][1][2] = '.';
    pronoms[5][2][0] = 'P';
    pronoms[5][2][1] = '2';
    pronoms[5][2][2] = '.';
    pronoms[6][0][0] = 'i';
    pronoms[6][0][1] = 'l';
    pronoms[6][0][2] = 's';
    pronoms[6][0][4] = '.';
    pronoms[6][1][0] = 'P';
    pronoms[6][1][1] = 'L';
    pronoms[6][1][2] = '.';
    pronoms[6][2][0] = 'P';
    pronoms[6][2][1] = '3';
    pronoms[6][2][2] = '.';
    pronoms[7][0][0] = 'e';
    pronoms[7][0][1] = 'l';
    pronoms[7][0][2] = 'l';
    pronoms[7][0][3] = 'e';
    pronoms[7][0][4] = 's';
    pronoms[7][0][5] = '.';
    pronoms[7][1][0] = 'P';
    pronoms[7][1][1] = 'L';
    pronoms[7][1][2] = '.';
    pronoms[7][2][0] = 'P';
    pronoms[7][2][1] = '3';
    pronoms[7][2][2] = '.';

 */
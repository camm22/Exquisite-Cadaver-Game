#include "rechercher_mot.h"


//Renvoie un tableau dynamique à 1 dimension
char* getEmptyTab1(long size){
    char* tab = NULL;
    tab = (char*) malloc(size * sizeof (char));
    return tab;
}


//Vérifie si c'est les mêmes str
int isSameStr3(char*** dic, long i, char* type, long nb_max){
    int veri = 1;
    for (long v=0; v<nb_max; v++){
        if (dic[i][0][v] != type[v]){
            veri *= 0;
        }
        else{
            veri *= 1;
        }
    }
    return veri;
}


//Compte le nombre de lignes où les str sont égaux
long countLine(char*** dic, long i_dic_max, char* tab, long size){
    long count = 0;
    for (long i_dic = 0; i_dic<i_dic_max; i_dic++){
        if (isSameStr3(dic, i_dic, tab, size) == 1){
            count++;
        }
    }
    return count;
}


//Affiche les lignes souhaitées
void printLine(char***dic, long i_dic){
    long k_dic = 0;

    printf("-");

    while (dic[i_dic][0][k_dic] != '\t'){
        printf("%c", dic[i_dic][0][k_dic]);
        k_dic++;
    }

    k_dic = 0;

    printf(" : ");

    while (dic[i_dic][2][k_dic] != '\n'){
        printf("%c", dic[i_dic][2][k_dic]);
        k_dic++;
    }

    printf("\n");
}


//Initialise l'affichage des lignes à afficher
void showLine(char*** dic, long i_dic_max, char* tab, long size){
    for (long i_dic = 0; i_dic<i_dic_max; i_dic++){
        if (isSameStr3(dic, i_dic, tab, size) == 1){
            printLine(dic, i_dic);
        }
    }
}


//Affiche le input de l'utilisateur
void showSmallStr(char* tab, long size){
    printf("\n:");
    for (int i=0; i<size; i++){
        printf("%c", tab[i]);
    }
}


//Fonction pour la recherche de mot
void rechercherMots(char*** dic, long i_dic_max, long k_dic_max, char * alphabet){

    char* input = getEmptyTab1(k_dic_max);

    for (int i = 0; i<14; i++){
        input[i] = '_';
    }

    long pos = 0;

    char Choix;

    printf("\n*Entrer le mot que vous voulez chercher lettre par lettre*\n*Tapper '/' pour quitter*\n");

    while (1){

        do {
            showSmallStr(input, k_dic_max);
            printf("\n|->");
            scanf(" %c", &Choix);
        } while (getPositionAlphabet(alphabet, Choix) == -1);

        if (Choix == '/' || pos == k_dic_max){
            printf("\n---[menu-principal]---\n\n");
            printf("Que voulez-vous faire ?\n  1- Generer une phrase\n  2- Rechercher un mot\n  3- Quitter le generateur\n");
            break;
        }

        input[pos] = Choix;
        input[pos + 1] = '_';
        pos++;

        if (countLine(dic, i_dic_max, input, pos) == 0){
            showSmallStr(input, pos);
            printf("\n-Ce mot n'existe pas\n\n");
            printf("\n-----[menu-principal]-----\n\n");
            printf("Que voulez-vous faire ?\n  1- Generer une phrase\n  2- Rechercher un mot\n  3- Quitter le generateur\n");
            break;
        }

        else if (countLine(dic, i_dic_max, input, pos) <= 15){

            showLine(dic, i_dic_max, input, pos);

        }
    }
}

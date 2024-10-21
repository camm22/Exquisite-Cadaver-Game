#include "creation_tableau_distinct.h"


//Fonction qui vérifie si les deux chaines données en paramètre sont égales
int isSameStrType(char*** dic, long i, char* type, long nb_max){
    int veri = 1;
    for (long v=0; v<nb_max; v++){
        if (dic[i][2][v] != type[v]){
            veri *= 0;
        }
        else{
            veri *= 1;
        }
    }
    return veri;
}


//Fonction qui revoie le nombre de lignes des différents types de tableau
long getNbLineTypeTab(char*** dic,long i_max_dic, char* type, long nb_max){
    long i, count = 0;

    for (i=0; i<i_max_dic; i++){
        if (isSameStrType(dic, i, type, nb_max) == 1){
            count++;
        }
    }
    return count;
}



//Fonction qui renvoie le tableau d'un des 4 types sous la forme d'un tableau dynamique à trois dimensions
char*** createTypeTab(char*** dic, long i_max_dic, char* type, long i_max_tab, long j_max_tab, long k_max_tab, long nb_max){

    char ***tab = createEmptyDictionary(i_max_tab, j_max_tab, k_max_tab);

    long i_dic, j_dic = 0, k_dic = 0;

    long i_tab = 0, j_tab = 0, k_tab = 0;

    for (i_dic=0; i_dic<i_max_dic; i_dic++){

        if(isSameStrType(dic, i_dic,type, nb_max) == 1){


            while(1){

                if (dic[i_dic][j_dic][k_dic] == '\t'){
                    tab[i_tab][j_tab][k_tab] = dic[i_dic][j_dic][k_dic];

                    j_dic++;
                    k_dic = 0;

                    j_tab++;
                    k_tab = 0;
                }

                else if (dic[i_dic][j_dic][k_dic] == '\n'){
                    tab[i_tab][j_tab][k_tab] = dic[i_dic][j_dic][k_dic];

                    j_dic = 0;
                    k_dic = 0;

                    j_tab = 0;
                    k_tab = 0;

                    break;
                }

                else{
                    tab[i_tab][j_tab][k_tab] = dic[i_dic][j_dic][k_dic];

                    k_dic++;
                    k_tab++;
                }
            }

            i_tab++;
        }
    }

    return tab;
}

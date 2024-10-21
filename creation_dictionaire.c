#include "creation_dictionaire.h"


//Fonction qui revoie le nombre de lignes du dictionnaire principal
long getNbLineDictionary(char* parcours){
    FILE *file;
    file = fopen(parcours,"r");

    char c = fgetc(file);
    long count = 1;
    while (c !=EOF){
        c = fgetc(file);
        if (c == '\n'){count++;}
    }

    fclose(file);
    return count;
}


//Fonction qui crée un tableau de char vide de dimension 3
char*** createEmptyDictionary(long i_max, long j_max, long k_max){
    long idx, col;

    char*** dic = NULL;

    dic = (char***) malloc(i_max * sizeof (char**));

    for (idx=0; idx<i_max; idx++){
        dic[idx] = (char**) malloc(j_max * sizeof (char*));
    }

    for (idx=0; idx<i_max; idx++){
        for (col=0; col<j_max; col++){
            dic[idx][col] = (char*) malloc(k_max * sizeof (char));
        }
    }

    return dic;
}




//Fonction qui renvoie le dictionnaire principal sous forme d'un tableau dynamique à trois dimensions
char*** createDictionary(char* parcours, long i_max, long j_max, long k_max){

    FILE *fichier;
    fichier = fopen(parcours,"r");

    char ***dic = createEmptyDictionary(i_max, j_max, k_max);

    char c = fgetc(fichier);

    long i=0, j=0, k=0;

    while (c != EOF){

        if (c == '\t'){
            dic[i][j][k] = c;
            k = 0;
            j++;
            c = fgetc(fichier);
        }
        else if(c == '\n'){
            dic[i][j][k] = c;
            j = 0;
            k = 0;
            i++;
            c = fgetc(fichier);

        }
        else{
            dic[i][j][k] = c;
            k++;
            c = fgetc(fichier);
        }
    }
    //important car il n'y en a pas tout à la fin, sur la dernière ligne
    dic[i][j][k] = '\n';

    fclose(fichier);
    return dic;
}



//Afficher un tableau dynamique à trois dimensions
void displayDictionary(char*** dic, long i_max, long j_max){
    long i, j, k = 0;

    for (i=0; i<i_max; i++){

        for (j=0; j<j_max; j++){

            while (1){

                if (dic[i][j][k] == '\t' || dic[i][j][k] == '\n'){
                    printf("%c", dic[i][j][k]);
                    k = 0;
                    break;
                }

                printf("%c", dic[i][j][k]);
                k++;
            }
        }
    }
}

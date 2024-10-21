#include "base_aleatoire.h"

//Compte le nombre de lettres pas égales à NULL
int getNbElementAdverbe(p_letter_adverbe temp){
    int count = 0;
    int i = 0;
    while(i<MAX_ALPHABET){
        if (temp->suite[i] != NULL){
            count++;
        }
        i++;
    }
    return count;
}

//Renvoie une base aléatoire d'un adverbe
char* adverbeBase(t_adverbe_tree *mytree_adverbe, long k_max){
    int element, random;

    char* base = getEmptyTab1(k_max);
    int k = 0;

    random = rand() % (MAX_ALPHABET - 4);

    p_letter_adverbe temp = mytree_adverbe->root_letter[random];

    base[k] = temp->value;
    k++;

    int compteur_verification, count;

    while (1){

        compteur_verification = 0;
        count = 0;

        if (temp->fleche != NULL){
            random = rand() % 4 + 1;
            if (random == 2){
                break;
            }
        }

        element = getNbElementAdverbe(temp);

        if (element == 0){
            break;
        }

        random = rand() % element + 1;

        while (1){
            if (temp->suite[count] != NULL){
                compteur_verification++;
                if (compteur_verification == random){
                    break;
                }
            }
            count++;
        }

        temp = temp->suite[count];
        base[k] = temp->value;
        k++;
    }

    base[k] = '.';

    return base;
}

//Compte le nombre de lettres pas égales à NULL
int getNbElementNA(p_letter_NA temp){
    int count = 0;
    int i = 0;
    while(i<MAX_ALPHABET){
        if (temp->suite[i] != NULL){
            count++;
        }
        i++;
    }
    return count;
}

//Renvoie une base aléatoire d'un nom ou d'un adjectif
char* NABase(t_NA_tree *mytree_NA, long k_max){
    int element, random;

    char* base = getEmptyTab1(k_max);
    int k = 0;

    random = rand() % (MAX_ALPHABET - 4);

    p_letter_NA temp = mytree_NA->root_letter[random];

    base[k] = temp->value;
    k++;

    int compteur_verification, count;

    while (1){

        compteur_verification = 0;
        count = 0;

        if (temp->fleche != NULL){
            random = rand() % 5 + 1;
            if (random == 2){
                break;
            }
        }

        element = getNbElementNA(temp);

        if (element == 0){
            break;
        }

        random = rand() % element + 1;

        while (1){
            if (temp->suite[count] != NULL){
                compteur_verification++;
                if (compteur_verification == random){
                    break;
                }
            }
            count++;
        }

        temp = temp->suite[count];
        base[k] = temp->value;
        k++;
    }

    base[k] = '.';

    return base;
}



//Compte le nombre de lettres pas égales à NULL
int getNbElementVerbe(p_letter_verb temp){
    int count = 0;
    int i = 0;
    while(i<MAX_ALPHABET){
        if (temp->suite[i] != NULL){
            count++;
        }
        i++;
    }
    return count;
}

//Renvoie une base aléatoire d'un verbe
char* verbeBase(t_verb_tree *mytree_verbe, long k_max){
    int element, random;

    char* base = getEmptyTab1(k_max);
    int k = 0;

    random = rand() % (MAX_ALPHABET - 4);

    p_letter_verb temp = mytree_verbe->root_letter[random];

    base[k] = temp->value;
    k++;

    int compteur_verification, count;

    while (1){

        compteur_verification = 0;
        count = 0;

        if (temp->fleche != NULL){
            random = rand() % 2 + 1;
            if (random == 2){
                break;
            }
        }

        element = getNbElementVerbe(temp);

        if (element == 0){
            break;
        }

        random = rand() % element + 1;

        while (1){
            if (temp->suite[count] != NULL){
                compteur_verification++;
                if (compteur_verification == random){
                    break;
                }
            }
            count++;
        }

        temp = temp->suite[count];
        base[k] = temp->value;
        k++;
    }

    base[k] = '.';

    return base;
}




//Fonction pour afficher une base
void dispalyBase(char* base){
    int i = 0;
    while (base[i] != '.'){
        printf("%c", base[i]);
        i++;
    }
}

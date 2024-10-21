#include "flechie_aleatoire.h"


int isSameCate(char*** article, int i, int j, char* art){
    int veri = 1;

    int k = 0;

    while(article[i][j][k] != '.'){
        if (article[i][j][k] != art[k]){
            veri *= 0;
        }
        else{
            veri *= 1;
        }
        k++;
    }
    return veri;
}


void displayArticle(char*** article, int i){
    int j = 0, k = 0;
    while(article[i][j][k] != '.'){
        printf("%c", article[i][j][k]);
        k++;
    }
}


//Modèle 1 : nom-adjectif-verbe-nom
void model1(t_verb_tree* mytree_verbe, t_NA_tree* mytree_nom, t_NA_tree* mytree_adjectif, t_adverbe_tree* mytree_adverbe, char *alphabet, long k_max, char*** articles){
    char Mas[3] = "Mas";
    char Fem[3] = "Fem";
    char Inv[3] = "Inv";
    char SG[2] = "SG";
    char PL[2] = "PL";
    char P1[2] = "P1";
    char P2[2] = "P2";
    char P3[2] = "P3";



    char* base_nom1 = NABase(mytree_nom, k_max);
    char* base_nom2 = NABase(mytree_nom, k_max);
    char * base_verbe1 = verbeBase(mytree_verbe, k_max);
    char * base_verbe2 = verbeBase(mytree_verbe, k_max);
    char* base_adjectif = NABase(mytree_adjectif, k_max);


    p_letter_NA temp_nom2 = searchLetterNA(mytree_nom, base_nom2, alphabet);
    p_letter_NA temp_nom1 = searchLetterNA(mytree_nom, base_nom1, alphabet);
    p_letter_verb temp_verb = searchLetter(mytree_verbe, base_verbe1, alphabet);
    p_letter_NA temp_adjectif = searchLetterNA(mytree_adjectif, base_adjectif, alphabet);


    int i_articles= rand() % 6 ;

    i_articles = 0;

    int temps_de_verbe = rand() % 2 ;



    p_nombre_verb temps_du_verb;

    if (temps_de_verbe == 1){
        temps_du_verb = temp_verb->fleche->IImp;
    }
    else{
        temps_du_verb = temp_verb->fleche->IPre;
    }


    displayArticle(articles, i_articles); printf(" ");

    if (isSameCate(articles, i_articles, 1, Mas) == 1 && isSameCate(articles, i_articles, 2, SG) == 1){

        while(temp_nom1->fleche->Mas->SG->tab_mots == NULL){
            base_nom1 = NABase(mytree_nom, k_max);
            temp_nom1 = searchLetterNA(mytree_nom, base_nom1, alphabet);
        }

        dispalyBase(temp_nom1->fleche->Mas->SG->tab_mots); printf(" ");



        while (temp_adjectif->fleche->Mas->SG->tab_mots == NULL){
            base_adjectif = NABase(mytree_adjectif, k_max);
            temp_adjectif = searchLetterNA(mytree_adjectif, base_adjectif, alphabet);
        }

        dispalyBase(temp_adjectif->fleche->Mas->SG->tab_mots); printf(" ");

        dispalyBase(temps_du_verb->SG->P3->tab_mots); printf(" ");

    }


    else if (isSameCate(articles, i_articles, 1, Mas) == 1 && isSameCate(articles, i_articles, 2, PL) == 1){

        while(temp_nom1->fleche->Mas->PL->tab_mots == NULL){
            base_nom1 = NABase(mytree_nom, k_max);
            temp_nom1 = searchLetterNA(mytree_nom, base_nom1, alphabet);
        }

        dispalyBase(temp_nom1->fleche->Mas->PL->tab_mots); printf(" ");



        while (temp_adjectif->fleche->Mas->PL->tab_mots == NULL){
            base_adjectif = NABase(mytree_adjectif, k_max);
            temp_adjectif = searchLetterNA(mytree_adjectif, base_adjectif, alphabet);
        }

        dispalyBase(temp_adjectif->fleche->Mas->PL->tab_mots); printf(" ");

        dispalyBase(temps_du_verb->PL->P3->tab_mots); printf(" ");

    }




    else if(isSameCate(articles, i_articles, 1, Fem) == 1 && isSameCate(articles, i_articles, 2, SG) == 1){


        while(temp_nom1->fleche->Fem->SG->tab_mots == NULL){
            base_nom1 = NABase(mytree_nom, k_max);
            temp_nom1 = searchLetterNA(mytree_nom, base_nom1, alphabet);
        }

        dispalyBase(temp_nom1->fleche->Fem->SG->tab_mots); printf(" ");



        while (temp_adjectif->fleche->Fem->SG->tab_mots == NULL){
            base_adjectif = NABase(mytree_adjectif, k_max);
            temp_adjectif = searchLetterNA(mytree_adjectif, base_adjectif, alphabet);
        }

        dispalyBase(temp_adjectif->fleche->Fem->SG->tab_mots); printf(" ");

        dispalyBase(temps_du_verb->SG->P3->tab_mots); printf(" ");

    }

    else if (isSameCate(articles, i_articles, 1, Fem) == 1 && isSameCate(articles, i_articles, 2, PL) == 1){

        while(temp_nom1->fleche->Fem->PL->tab_mots == NULL){
            base_nom1 = NABase(mytree_nom, k_max);
            temp_nom1 = searchLetterNA(mytree_nom, base_nom1, alphabet);
        }

        dispalyBase(temp_nom1->fleche->Fem->PL->tab_mots); printf(" ");



        while (temp_adjectif->fleche->Fem->PL->tab_mots == NULL){
            base_adjectif = NABase(mytree_adjectif, k_max);
            temp_adjectif = searchLetterNA(mytree_adjectif, base_adjectif, alphabet);
        }

        dispalyBase(temp_adjectif->fleche->Fem->PL->tab_mots); printf(" ");

        dispalyBase(temps_du_verb->PL->P3->tab_mots); printf(" ");

    }





    i_articles= rand() % 6 ;

    displayArticle(articles, i_articles); printf(" ");

    if (isSameCate(articles, i_articles, 1, Mas) == 1 && isSameCate(articles, i_articles, 2, SG) == 1){

        while(temp_nom2->fleche->Mas->SG->tab_mots == NULL){
            base_nom2 = NABase(mytree_nom, k_max);
            temp_nom2 = searchLetterNA(mytree_nom, base_nom2, alphabet);
        }

        dispalyBase(temp_nom2->fleche->Mas->SG->tab_mots);

    }


    else if (isSameCate(articles, i_articles, 1, Mas) == 1 && isSameCate(articles, i_articles, 2, PL) == 1){

        while(temp_nom1->fleche->Mas->PL->tab_mots == NULL){
            base_nom2 = NABase(mytree_nom, k_max);
            temp_nom2 = searchLetterNA(mytree_nom, base_nom2, alphabet);
        }

        dispalyBase(temp_nom2->fleche->Mas->PL->tab_mots);


    }



    else if(isSameCate(articles, i_articles, 1, Fem) == 1 && isSameCate(articles, i_articles, 2, SG) == 1){


        while(temp_nom1->fleche->Fem->SG->tab_mots == NULL){
            base_nom2 = NABase(mytree_nom, k_max);
            temp_nom2 = searchLetterNA(mytree_nom, base_nom2, alphabet);
        }

        dispalyBase(temp_nom2->fleche->Fem->SG->tab_mots);


    }

    else if (isSameCate(articles, i_articles, 1, Fem) == 1 && isSameCate(articles, i_articles, 2, PL) == 1){

        while(temp_nom1->fleche->Fem->PL->tab_mots == NULL){
            base_nom2 = NABase(mytree_nom, k_max);
            temp_nom2 = searchLetterNA(mytree_nom, base_nom2, alphabet);
        }

        dispalyBase(temp_nom2->fleche->Fem->PL->tab_mots);

    }

}

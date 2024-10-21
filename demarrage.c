#include "menu_generateur.h"


void start(void){
    srand(time(NULL));

    printf("\n---------------[Chargement-du-generateur]---------------\n");
    printf("[...]\n");


    //Chemin pour trouver le fichier dictionnaire qu'on souhaite utiliser
    char chemin_dico_mini[] = "C:\\Users\\cambo\\OneDrive\\Bureau\\Efrei\\L2\\COURS\\Semestre 1\\Algorithmique\\Projet_Cadavre-exquis\\Generateur_de_phrase\\dico\\mini-dictionnaire.txt";
    char chemin_dico[] = "C:\\Users\\cambo\\OneDrive\\Bureau\\Algorithmique\\Semestre 1\\Projet_Cadavre-exquis\\Generateur_de_phrase\\dico\\dictionnaire.txt";
    char chemin_dico_accent[] = "C:\\Users\\cambo\\OneDrive\\Bureau\\Efrei\\L2\\COURS\\Semestre 1\\Algorithmique\\Projet_Cadavre-exquis\\Generateur_de_phrase\\dico\\dictionnaire_non_accentue.txt";

    //tailles maximums du dictionnaire
    long i_max_dico = getNbLineDictionary(chemin_dico_accent), j_max_dico = 3, k_max_dico = 100;

    //Création du dictionnaire
    char*** dictionary = createDictionary(chemin_dico_accent, i_max_dico, j_max_dico, k_max_dico);

    printf("[...]\n");

    //Création de la forme abrégée des 4 types
    char nom[3] = "Nom";
    char verb[3] = "Ver";
    char adjectif[3] = "Adj";
    char adverbe[3] = "Adv";

    long nb_max = 3;



    //Tailles maximus des 4 tableaux de chaque type
    long i_max_nom = getNbLineTypeTab(dictionary, i_max_dico, nom, nb_max), j_max_nom = 3, k_max_nom = 100;
    long i_max_verb = getNbLineTypeTab(dictionary, i_max_dico, verb, nb_max), j_max_verb = 3, k_max_verb = 100;
    long i_max_adjectif = getNbLineTypeTab(dictionary, i_max_dico, adjectif, nb_max), j_max_adjectif = 3, k_max_adjectif = 100;
    long i_max_adverbe = getNbLineTypeTab(dictionary, i_max_dico, adverbe, nb_max), j_max_adverbe = 3, k_max_adverbe = 100;



    //Création des 4 tableaux de chaque type
    char*** mytab_nom = createTypeTab(dictionary, i_max_dico, nom, i_max_nom, j_max_nom, k_max_nom, nb_max);
    char*** mytab_verb = createTypeTab(dictionary, i_max_dico, verb, i_max_verb, j_max_verb, k_max_verb, nb_max);
    char*** mytab_adjectif = createTypeTab(dictionary, i_max_dico, adjectif, i_max_adjectif, j_max_adjectif, k_max_adjectif, nb_max);
    char*** mytab_adverbe = createTypeTab(dictionary, i_max_dico, adverbe, i_max_adverbe, j_max_adverbe, k_max_adverbe, nb_max);

    printf("[...]\n");



    //Création d'une liste qui contient l'alphabet qui permettra de stocker les formes de bases des quatre types de mots différents
    char alphabet[29] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w','x','y','z', '-', '\'', '/'};



    //Création des 4 grands arbres qui stockent les formes fléchies
    t_verb_tree mytree_verbe = createTreeVerb(mytab_verb, i_max_verb, k_max_verb, alphabet);
    t_NA_tree mytree_nom = createTreeNA(mytab_nom, i_max_nom, k_max_nom, alphabet);
    t_NA_tree mytree_adjectif = createTreeNA(mytab_adjectif, i_max_adjectif, k_max_adjectif, alphabet);
    t_adverbe_tree mytree_adverbe = createTreeAdverbe(mytab_adverbe, i_max_adverbe, k_max_adverbe, alphabet);



    printf("[...]\n\n");

    printf("Que voulez-vous faire ?\n  1- Generer une phrase\n  2- Rechercher un mot\n  3- Quitter le generateur\n");

    while (1){

        char Choix;
        do {
            printf("\n{-} Entrer votre choix :");
            scanf(" %c", &Choix);
        } while (Choix != '1' && Choix != '2' && Choix != '3');

        if (Choix == '1'){
            genererPhrase(&mytree_verbe, &mytree_nom, &mytree_adjectif, &mytree_adverbe, alphabet, k_max_dico);
        }
        else if (Choix == '2'){
            rechercherMots(dictionary, i_max_dico, k_max_dico, alphabet);
        }
        else if (Choix == '3'){
            printf("\n\n---------------[hors-tension]---------------\n");
            break;
        }
    }
}

cmake_minimum_required(VERSION 3.21)
project(Generateur_de_phrase C)

set(CMAKE_C_STANDARD 99)

add_executable(Generateur_de_phrase main.c demarrage.c demarrage.h creation_dictionaire.c creation_dictionaire.h creation_arbre_verbe.c creation_arbre_verbe.h creation_tableau_distinct.c creation_tableau_distinct.h creation_arbre_nom_adjectif.c creation_arbre_nom_adjectif.h creation_arbre_adverbe.c creation_arbre_adverbe.h base_aleatoire.c base_aleatoire.h rechercher_mot.c rechercher_mot.h menu_generateur.c menu_generateur.h flechie_aleatoire.c flechie_aleatoire.h)

#include "interface_presidentielle.h"
#include "stdlib.h"
#include "stdio.h"

void affiche_menu(void) {
    // Afficher une ligne de séparation
    printf("\t========================================================\n");

    // Afficher le menu
    printf("\t\tBienvenu dans la gestion d'une election.\nVoici le menu:\n");
    printf("1.  Entrer des electeurs,\n");
    printf("2.  Ajouter des electeurs,\n");
    printf("3.  Supprimer un electeur,\n");
    printf("4.  Supprimer le dernier electeur,\n");
    printf("5.  Rechercher un electeur,\n");
    printf("6.  Afficher la liste des electeurs,\n");
    printf("7.  Calculer le nombre des electeurs,\n");
    printf("8.  Decouper la liste en trois sous-listes selon les choix: droite, gauche et blanc :\n");
    printf("\tSelectionnez le numero 8 avant :\n");
    printf("\ta  Trier les sous-listes\n");
    printf("\tb  Afficher les sous-listes,\n");
    printf("\tc  Fusionner les deux sous-listes : gauche et droite\n");
    printf("9.  Calculer les pourcentages de gauche et de droite pour le 2eme tour,\n");
    printf("10.  Liberer les listes\n");
    printf("11.  Quitter\n");

    // Afficher une ligne de séparation
    printf("\t........................................................\n");

    // Afficher la question de saisie
    printf("Veuillez saisir votre choix :\n");
}

void affiche_menu_secondaire(void) {
    printf("Entrez le numero correspondant a votre choix :\n");
    printf("1. Trier les sous-listes\n");
    printf("2. Afficher les sous-listes,\n");
    printf("3. Fusionner les deux sous-listes : gauche et droite\n");
    printf("4. Quitter\n");
    printf("Veuillez saisir votre choix :\n");
}

void affiche_message_quitter (void) {
    printf("Vous avez choisi de quitter.\n");
}

void affiche_message_erreur (void) {
    printf("Vous avez choisi une option invalide\nVeuillez recommencer\n");
}

long saisie_electeur_cin(void) {
    long cin;
    printf("Veuillez saisir le cin de l'electeur :\n");
    scanf("%ld", &cin);
    return cin;
}
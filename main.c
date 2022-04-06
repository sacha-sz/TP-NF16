#include <stdio.h>
#include "election_presidentielle.h"

#define Taille_MAX_NOM 100
long saisie_electeur_cin (void);
void affiche_menu (void);
void affiche_menu_secondaire(void);

int main() {
    T_Electeur liste_elec;
    liste_elec = NULL;
    T_Electeur *liste = &liste_elec;

    T_Electeur liste_elec_gauche;
    liste_elec_gauche = NULL;
    T_Electeur *liste_gauche = &liste_elec_gauche;

    T_Electeur liste_elec_droite;
    liste_elec_droite = NULL;
    T_Electeur *liste_droite = &liste_elec_droite;

    T_Electeur liste_elec_blanc;
    liste_elec_blanc = NULL;
    T_Electeur *liste_blanc = &liste_elec_blanc;

    ajoutelecteur(liste, "charles", 1, 2);
    ajoutelecteur(liste, "pierre", 3, 1);
    ajoutelecteur(liste, "tom", 2, 3);
    ajoutelecteur(liste, "ad", 4, 2);
    ajoutelecteur(liste, "sacha", 5, 4);
    ajoutelecteur(liste, "theo", 6, 5);
    ajoutelecteur(liste, "antoine", 7, 2);


    int rep = -1;
    int rep_menu_8 = -1;
    int calcul_pourcentage_possible = 0;

    do {
        affiche_menu();
        scanf("%d", &rep);
        printf("\n");
        if (rep > 11 || rep < 1) rep = -1;

        switch (rep) {
            case 1 :
            case 2:
                if (rep==1) printf("Vous avez choisi d'entrer les electeurs.\n");
                else printf("Vous avez choisi d'ajouter les electeurs.\n");

                char nom[Taille_MAX_NOM];
                printf("Veuillez saisir le nom de l'electeur :\n");
                scanf("%s", &nom);
                printf("Le nom saisi est : %s\n", nom);

                long cin = saisie_electeur_cin();

                int vote = 0;
                printf("Veuillez saisir le choix de l'electeur :\n");
                scanf("%d", &vote);

                ajoutelecteur(liste, nom, cin, vote);
                break;

            case 3 :
                printf("Vous avez choisi de supprimer un electeur.\n");
                long cin_electeur_supprimer = saisie_electeur_cin();
                supprime_electeur(liste, cin_electeur_supprimer);
                break;

            case 4 :
                printf("Vous avez choisi de supprimer le dernier electeur.\n");
                supprime_dernier_elec(liste);
                break;

            case 5 :
                printf("Vous avez choisi de rechercher un electeur.\n");
                long cin_electeur_rechercher = saisie_electeur_cin();
                trouve_electeur(liste, cin_electeur_rechercher);
                break;

            case 6 :
                printf("Vous avez d'afficher la liste des electeurs.\n");
                afficheliste(*liste);
                break;

            case 7 :
                printf("Vous avez choisi de calculer le nombre des electeurs.\n");
                int nb_electeurs = 0;
                nb_electeurs = compte_electeur(liste);
                printf("Le nombre d'electeur est de : %d\n", nb_electeurs);
                break;

            case 8:
                printf("Vous avez choisi de decouper la liste en trois sous-listes selon les choix: droite, gauche et blanc.\n");
                decoupeliste(*liste, liste_gauche, liste_droite, liste_blanc);
                printf("Vous pouvez effectuer une action supplementaire.\n");
                do {
                    affiche_menu_secondaire();
                    scanf("%d", &rep_menu_8);
                    switch (rep_menu_8) {
                        case 1:
                            printf("Vous avez choisi de trier les sous listes.\n");
                            triliste(liste_gauche);
                            triliste(liste_droite);
                            triliste(liste_blanc);
                            break;

                        case 2:
                            printf("Vous avez choisi d'afficher les sous listes.\n");
                            printf("\nListe gauche :\n");
                            afficheliste(*liste_gauche);
                            printf("\nListe droite :\n");
                            afficheliste(*liste_droite);
                            printf("\nListe blanc :\n");
                            afficheliste(*liste_blanc);
                            break;
                        case 3:
                            printf("Vous avez choisi de fusionner les sous listes.\n");
                            fusionlistes(liste_gauche, *liste_droite);
                            calcul_pourcentage_possible = 1;
                            break;
                        case 4:
                            printf("Vous avez choisi de quitter.\n");
                            break;
                        default:
                            printf("Vous avez choisi une option invalide.\n");
                            break;
                    }
                } while (rep_menu_8 != 4);
                break;

            case 9 :
                printf("Vous avez choisi de calculer les pourcentages de gauche et de droite pour le 2eme tour.\n");
                if (calcul_pourcentage_possible == 1) {
                    int nb_electeurs_gauche = 0;
                    int nb_electeurs_droite = 0;

                    int nb_electeur = compte_electeur(liste_gauche);

                    nb_electeurs_gauche = compteGD(*liste_gauche);
                    nb_electeurs_droite = nb_electeur - nb_electeurs_gauche;

                    float pourcentage_gauche = ((float) nb_electeurs_gauche / (float) nb_electeur) * 100;
                    printf("Le pourcentage d'electeurs de gauche est de : %.3f %\n", pourcentage_gauche);

                    float pourcentage_droite = ((float) nb_electeurs_droite / (float) nb_electeur) * 100;
                    printf("Le pourcentage d'electeurs de droite est de : %.3f %\n", pourcentage_droite);
                }
                else {
                    printf("Vous ne pouvez pas calculer les pourcentages car les listes n'ont pas ete fusionnes.\n");
                    printf("Veuillez selectionner 8 puis 3 puis revenir effectuer les calculs.\n");
                }
                break;

            case 10 :
                printf("Vous avez choisi de liberer les listes.\n");
                libereliste(*liste);
                libereliste(*liste_gauche);
                libereliste(*liste_droite);
                libereliste(*liste_blanc);
                break;

            case 11 :
                printf("Vous avez choisi de quitter.\n");
                break;

            default:
                printf("Vous avez choisi une option invalide.\n");
                break;
        }
    } while (rep != 11);

    printf("===========================\tFIN\t===========================\n");

    return 0;
}

long saisie_electeur_cin(void) {
    long cin;
    printf("Veuillez saisir le cin de l'electeur :\n");
    scanf("%ld", &cin);
    return cin;
}

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
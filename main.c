#include <stdio.h>
#include "election_presidentielle.h"
#include "interface_presidentielle.h"

#define Taille_MAX_NOM 100
#define NUM_REP_MIN 1
#define NUM_REP_MAX 12

int main() {
    // Initialisation de la liste principale des electeurs
    T_Electeur liste_elec;
    liste_elec = NULL;
    T_Electeur *liste = &liste_elec;

    // Initialisation de la liste des electeurs votants à gauche
    T_Electeur liste_elec_gauche;
    liste_elec_gauche = NULL;
    T_Electeur *liste_gauche = &liste_elec_gauche;

    // Initialisation de la liste des electeurs votants à droite
    T_Electeur liste_elec_droite;
    liste_elec_droite = NULL;
    T_Electeur *liste_droite = &liste_elec_droite;

    // Initialisation de la liste des electeurs votants blancs
    T_Electeur liste_elec_blanc;
    liste_elec_blanc = NULL;
    T_Electeur *liste_blanc = &liste_elec_blanc;

    // Initialisation des variables de réponse
    int rep = -1;
    int rep_menu_8 = -1;

    // Initialisation de la variable de vérification de la possibilité de calculer les pourcentages
    int calcul_pourcentage_possible = 0;


    // Initialisation du menu principal à l'aide d'une boucle do while afin de rentrer au moins une fois dans le menu
    do {
        // Affichage du menu principal à l'aide du fichier interface_presidentielle.h
        affiche_menu();

        // Récupération de la réponse de l'utilisateur
        scanf("%d", &rep);

        // Affichage d'une ligne vide
        printf("\n");

        // Vérification de la réponse de l'utilisateur si elle est mauvaise la remettre à -1
        if (rep > NUM_REP_MAX || rep < NUM_REP_MIN) rep = -1;

        /*
         * On passe à l'affichage de chaque fonction en fonction de la réponse de l'utilisateur
         * Et de l'affichage du message d'erreur en cas de mauvaise réponse (default)
         * A l'aide de switch permettant de gérer les différents cas
         */
        switch (rep) {
            case 1 :
                // On ne fait rien (pas de break) afin de passer dans le cas 2
            case 2:
                // Affichage d'un message dynamique en fonction de la réponse de l'utilisateur
                if (rep==1) printf("Vous avez choisi d'entrer les electeurs.\n");
                else printf("Vous avez choisi d'ajouter les electeurs.\n");

                // Création d'un nouvel électeur

                // On initialise le nom de l'électeur
                char nom[Taille_MAX_NOM];
                printf("Veuillez saisir le nom de l'electeur :\n");
                scanf("%s", &nom);
                while (getchar() != '\n');
                printf("Le nom saisi est : %s\n", nom);

                // On initialise le cin de l'électeur en appelant la fonction saisie_electeur_cin
                long cin = saisie_electeur_cin();

                // On initialise le vote de l'électeur
                int vote = 0;
                printf("Veuillez saisir le choix de l'electeur :\n");
                scanf("%d", &vote);

                // On ajoute l'électeur à la liste principale
                ajoutelecteur(liste, nom, cin, vote);
                break;

            case 3 :
                // Affichage d'un message informatif pour l'utilisateur
                printf("Vous avez choisi de supprimer un electeur.\n");

                // On initialise le cin de l'électeur en appelant la fonction saisie_electeur_cin
                long cin_electeur_supprimer = saisie_electeur_cin();

                // On supprime l'électeur de la liste principale
                supprime_electeur(liste, cin_electeur_supprimer);
                break;

            case 4 :
                // Affichage d'un message informatif pour l'utilisateur
                printf("Vous avez choisi de supprimer le dernier electeur.\n");

                // On supprime le dernier électeur de la liste principale
                supprime_dernier_elec(liste);
                break;

            case 5 :
                // Affichage d'un message informatif pour l'utilisateur
                printf("Vous avez choisi de rechercher un electeur.\n");

                // On initialise le cin de l'électeur en appelant la fonction saisie_electeur_cin
                long cin_electeur_rechercher = saisie_electeur_cin();

                // On recherche l'électeur dans la liste principale
                trouve_electeur(liste, cin_electeur_rechercher);
                break;

            case 6 :
                // Affichage d'un message informatif pour l'utilisateur
                printf("Vous avez d'afficher la liste des electeurs.\n");

                // On affiche la liste des électeurs
                afficheliste(*liste);
                break;

            case 7 :
                // Affichage d'un message informatif pour l'utilisateur
                printf("Vous avez choisi de calculer le nombre des electeurs.\n");

                // On initialise le nombre d'électeurs
                int nb_electeurs = 0;
                nb_electeurs = compte_electeur(liste);

                // On affiche le nombre d'électeurs
                printf("Le nombre d'electeur est de : %d\n", nb_electeurs);
                break;

            case 8:
                // Affichage d'un message informatif pour l'utilisateur
                printf("Vous avez choisi de decouper la liste en trois sous-listes selon les choix: droite, gauche et blanc.\n");

                // On initialise les trois sous-listes en découpant la liste principale
                decoupeliste(*liste, liste_gauche, liste_droite, liste_blanc);

                // On affiche les options supplémentaires avec une boucle do while
                printf("Vous pouvez effectuer une action supplementaire.\n");

                do {
                    // On affiche le menu secondaire
                    affiche_menu_secondaire();

                    // On récupère le choix de l'utilisateur
                    scanf("%d", &rep_menu_8);
                    switch (rep_menu_8) {
                        case 1:
                            // Affichage d'un message informatif pour l'utilisateur
                            printf("Vous avez choisi de trier les sous listes.\n");

                            // On trie les sous-listes
                            triliste(liste_gauche);
                            triliste(liste_droite);
                            triliste(liste_blanc);
                            break;

                        case 2:
                            // Affichage d'un message informatif pour l'utilisateur
                            printf("Vous avez choisi d'afficher les sous listes.\n");

                            // On affiche les sous-listes
                            printf("\nListe gauche :\n");
                            afficheliste(*liste_gauche);

                            printf("\nListe droite :\n");
                            afficheliste(*liste_droite);

                            printf("\nListe blanc :\n");
                            afficheliste(*liste_blanc);

                            break;
                        case 3:
                            // Affichage d'un message informatif pour l'utilisateur
                            printf("Vous avez choisi de fusionner les sous listes.\n");

                            // On fusionne les sous-listes vers la liste gauche
                            fusionlistes(liste_gauche, *liste_droite);

                            // On rend posssible le calcul du pourcentage
                            calcul_pourcentage_possible = 1;
                            break;
                        case 4:
                            // Affichage d'un message informatif pour l'utilisateur
                            affiche_message_quitter();
                            break;
                        default:
                            // Affichage d'un message informatif pour l'utilisateur
                            affiche_message_erreur ();
                            break;
                    }
                } while (rep_menu_8 != 4); // Tant que l'utilisateur ne quitte pas le menu secondaire, on continue la boucle
                break;

            case 9 :
                // Affichage d'un message informatif pour l'utilisateur
                printf("Vous avez choisi de calculer les pourcentages de gauche et de droite pour le 2eme tour.\n");

                // On vérifie que le calcul du pourcentage est possible
                if (calcul_pourcentage_possible == 1) {
                    // On initialise les deux pourcentages
                    int nb_electeurs_gauche = 0;
                    int nb_electeurs_droite = 0;

                    // On calcule le nombre d'électeurs (ayant voté à gauche ou à droite)
                    int nb_electeur = compte_electeur(liste_gauche);

                    // On calcule le nombre d'électeurs ayant voté à gauche
                    nb_electeurs_gauche = compteGD(*liste_gauche);

                    // On en déduit le nombre d'électeurs ayant voté à droite
                    nb_electeurs_droite = nb_electeur - nb_electeurs_gauche;

                    // On calcule puis on affiche le pourcentage de gauche
                    float pourcentage_gauche = ((float) nb_electeurs_gauche / (float) nb_electeur) * 100;
                    printf("Le pourcentage d'electeurs de gauche est de : %.3f %\n", pourcentage_gauche);

                    // On calcule puis on affiche le pourcentage de droite
                    float pourcentage_droite = ((float) nb_electeurs_droite / (float) nb_electeur) * 100;
                    printf("Le pourcentage d'electeurs de droite est de : %.3f %\n", pourcentage_droite);
                }
                else {
                    // Si le calcul du pourcentage n'est pas possible, on affiche un message d'erreur
                    printf("Vous ne pouvez pas calculer les pourcentages car les listes n'ont pas ete fusionnes.\n");

                    //  On guide l'utilisateur pour qu'il puisse faire une fusion des sous-listes pour pouvoir calculer les pourcentages
                    printf("Veuillez selectionner 8 puis 3 puis revenir effectuer les calculs.\n");
                }
                break;

            case 10 :
                // Affichage d'un message informatif pour l'utilisateur
                printf("Vous avez choisi de trier la liste principale.\n");

                // On trie la liste principale
                triliste(liste);
                break;

            case 11 :
                // Affichage d'un message informatif pour l'utilisateur
                printf("Vous avez choisi de liberer les listes.\n");

                // On libère les listes
                libereliste(*liste);
                libereliste(*liste_gauche);
                libereliste(*liste_droite);
                libereliste(*liste_blanc);
                break;



            case NUM_REP_MAX :
                // Affichage d'un message informatif pour l'utilisateur à l'aide de la fonction affiche_message_quitter
                affiche_message_quitter();
                break;

            default:
                // Affichage d'un message informatif pour l'utilisateur à l'aide de la fonction affiche_message_erreur
                affiche_message_erreur();
                break;
        }
    } while (rep != NUM_REP_MAX); // Tant que l'utilisateur ne quitte pas le programme

    // Affiche le message de fin
    printf("===========================\tFIN\t===========================\n");

    // Retourne le code de sortie
    return 0;
}


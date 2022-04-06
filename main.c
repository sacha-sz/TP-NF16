#include <stdio.h>
#include "election_presidentielle.h"

long supprimer_electeur_cin (void);
void affiche_menu (void);

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


    afficheliste(*liste);
    printf("Debut du tri :\n");
    triliste(liste);

    afficheliste(*liste);

    printf("Le nombre d'electeur est de : %d\n", compte_electeur(liste));
    printf("Le nombre d'electeur de gauche est de : %d\n", compteGD(*liste));

    trouve_electeur(liste, 2);

    printf("Debut decoupe :");

    decoupeliste(*liste, liste_gauche, liste_droite, liste_blanc);


    printf("Liste gauche :\n");
    afficheliste(*liste_gauche);


    printf("Liste droite :\n");
    afficheliste(*liste_droite);


    printf("Liste blanc :\n");
    afficheliste(*liste_blanc);


    printf("Fusion liste \n");
    fusionlistes(liste_gauche, *liste_droite);
    afficheliste(*liste_gauche);


    return 0;

}
























//    int rep = -1;
//    printf("Bienvenu dans la gestion d'une election.\nVoici le menu:\n");
//    while (rep != 10) {
//        affiche_menu();
//
//        printf("Veuillez saisir votre choix :");
//        scanf("%d", &rep);
//        printf("\n");
//        if (rep != 10) {
//              if (rep == 1) {
//                  printf("Vous avez choisi d'entrer les electeurs.\n");
//                  char *nom;
//                  printf("Veuillez saisir le nom de l'electeur :\n");
//                  scanf("%s", &nom);
//
//                  long cin = 0;
//                  printf("Veuillez entrer le cin de l'electeur :\n");
//                  scanf("%ld", &cin);
//
//                  int vote = 0;
//                  printf("Veuillez saisir le choix de l'electeur :\n");
//                  scanf("%d", &vote);
//
//                  ajoutelecteur(liste, nom, cin, vote);
//              }
//              else if (rep == 3) {
//                  printf("Vous avez choisi de supprimer unn electeur.\n");
//                  long cin_electeur_supprimer = supprimer_electeur_cin();
//                  Supprimelecteur(liste, cin_electeur_supprimer);
//              }
//              else if (rep==4) {
//                  printf("Vous avez choisi de rechercher un electeur.\n");
//              }
//              else if (rep==5) {
//                  printf("Vous avez choisi de rechercher un electeur.\n");
//              }
//              else if (rep==6) {
//                  printf("Vous avez choisi de calculer le nombre des electeurs.\n");
//              }
//              else if (rep==7) {
//                  printf("Vous avez choisi de decouper la liste en trois sous-listes selon les choix: droite, gauche et blanc.\n");
//              }
//              else if (rep==8) {
//                  printf("Vous avez choisi de calculer les pourcentages de gauche et de droite pour le 2ème tour.\n");
//              }
//              else if (rep==9) {
//                  printf("Vous avez choisi de liberer les listes.\n");
//
//              }
//        }
//    }
//    printf("Vous avez quitte le programme d'election.\n");
//    return 0;
//}
//
//long supprimer_electeur_cin(void) {
//    long cin;
//    printf("Vous avez choisi de supprimer un electeur veuillez saisir le cin de l'electeur : ");
//    scanf("%ld", &cin);
//    return cin;
//}
//
//void affiche_menu(void) {
//    printf("1.\tEntrer les electeurs,\n");
//    printf("3.\tSupprimer le dernier electeur,\n");
//    printf("4\tRechercher un electeur,\n");
//    printf("5\tAfficher la liste des electeurs,\n");
//    printf("6\tCalculer le nombre des electeurs,\n");
//    printf("7\tDecouper la liste en trois sous-listes selon les choix: droite, gauche et blanc\n");
//    printf("\ta\tTrier les sous-listes\n");
//    printf("\tb\tAfficher les sous-listes,\n");
//    printf("\tc\tFusionner les deux sous-listes : gauche et droite\n");
//    printf("8\tCalculer les pourcentages de gauche et de droite pour le 2eme tour,\n");
//    printf("9\tLiberer les listes\n");
//    printf("10\tQuitter\n\n");
//}
#include "election_presidentielle.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


T_Electeur creationelecteur(void) {
    electeur *electeur1 = malloc(sizeof(electeur));
    if (electeur1 != NULL) {
        electeur1->suivant = NULL;
    }
    return electeur1;
}

void afficheliste(T_Electeur liste_electeur) {
    T_Electeur t_elec = liste_electeur;

    while(t_elec != NULL) {
        printf("Nom : %s\n", t_elec->nom);
        printf("Cin : %ld\n", t_elec->cin_num);
        printf("Votant : %d\n\n", t_elec->choix);
        t_elec = t_elec->suivant;
    }
}

void ajoutelecteur(T_Electeur *liste, char nom[], long cin, int vote) {
    T_Electeur t_elec = creationelecteur();
    if (t_elec != NULL) {
        // Initialisation des champs
        t_elec->choix = vote;
        t_elec->cin_num = cin;
        t_elec->nom = malloc(sizeof (nom));
        strcpy(t_elec->nom, nom);


        T_Electeur actuel = *liste;

        if (actuel==NULL){
            *liste = t_elec;
        }

        else {
            T_Electeur precedent = NULL;

            while (actuel != NULL && strcmp(actuel->nom, t_elec->nom) < 0) {
                precedent = actuel;
                actuel = actuel->suivant;
            }
            if (precedent==NULL) {
                t_elec->suivant = actuel;
                *liste = t_elec;
            }
            else if (actuel==NULL) {
                precedent->suivant = t_elec;
            }
            else {
                t_elec->suivant=actuel;
                precedent->suivant = t_elec;
            }
        }
    }
}

int comptelecteur (T_Electeur *liste) {
    int nb_electeur = 0;
    T_Electeur t_elec = *liste;
    while (t_elec != NULL) {
        nb_electeur++;
        t_elec = t_elec->suivant;
    }
    return nb_electeur;
}

int trouvelecteur(T_Electeur *liste, long cin) {
    T_Electeur t_elec = *liste;

    while (t_elec != NULL && t_elec->cin_num != cin) {
        t_elec = t_elec->suivant;
    }

    if (t_elec == NULL) {
        return 0;
    }
    else {
        printf("Nom : %s\n", t_elec->nom);
        printf("Cin : %ld\n", t_elec->cin_num);
        printf("Votant : %d\n\n", t_elec->choix);
        return 1;
    }
}

void Supprimelecteur(T_Electeur *liste, long cin) {
    T_Electeur t_elec = *liste;
    T_Electeur precedent = NULL;


    while (t_elec != NULL && t_elec->cin_num != cin) {
        precedent = t_elec;
        t_elec = t_elec->suivant;
    }

    if (precedent==NULL) {
        *liste = t_elec -> suivant;
    }
    else if (t_elec==NULL) {
        printf("\nCette personne n'existe pas\n");
    }
    else {
        precedent->suivant= t_elec->suivant;
    }
}

void decoupeliste(T_Electeur liste, T_Electeur *liste_gauche, T_Electeur *liste_droite, T_Electeur *liste_blanc) {
    T_Electeur t_elec = liste;

    while (t_elec != NULL) {
        if(t_elec->choix == 1 || t_elec->choix == 3){
            ajoutelecteur(liste_gauche, t_elec->nom, t_elec->cin_num, t_elec->choix);
        }
        else if(t_elec->choix == 2 || t_elec->choix == 4){
            ajoutelecteur(liste_droite, t_elec->nom, t_elec->cin_num, t_elec->choix);
        }
        else {
            ajoutelecteur(liste_blanc, t_elec->nom, t_elec->cin_num, t_elec->choix);
        }
        t_elec = t_elec->suivant;
    }
}

void triliste(T_Electeur *liste) {
    T_Electeur actuel = *liste;


    if (actuel == NULL || actuel->suivant == NULL) {
        printf("\n\nLa liste est vide ou ne contient qu'un element, elle ne peut pas etre triee\n\n");
    } else {
        int tri = 0;

        T_Electeur precedent;
        T_Electeur tmp;

        while (tri == 0) {
            tri = 1;
            precedent = NULL;
            actuel = *liste;
            while (actuel->suivant != NULL) {
                if (actuel->cin_num > actuel->suivant->cin_num) {
                    tri = 0;
                    if (precedent == NULL) {
                        tmp = actuel->suivant;
                        actuel->suivant = actuel->suivant->suivant;
                        tmp->suivant = actuel;
                        precedent = tmp;
                        *liste = precedent;
                    } else {
                        tmp = actuel->suivant;
                        actuel->suivant = actuel->suivant->suivant;
                        precedent->suivant = tmp;
                        tmp->suivant = actuel;

                        precedent = tmp;

                    }
                } else {
                    precedent = actuel;
                    actuel = actuel->suivant;
                }
            }
        }
    }
}

T_Electeur fusionlistes(T_Electeur liste_gauche, T_Electeur liste_droite) {
    T_Electeur actuel_droite = liste_droite;
    T_Electeur actuel_gauche = liste_gauche;

    if (actuel_droite == NULL) {
        return actuel_gauche;
    }
    else if (actuel_gauche == NULL) {
        return actuel_droite;
    }
    else {
        while (actuel_droite->suivant != NULL) {
            actuel_droite = actuel_droite->suivant;
        }
        actuel_droite->suivant = actuel_gauche;
        triliste(&actuel_droite);
        return actuel_droite;
    }
}


int compteGD(T_Electeur liste){
    int nb_voix_gauche = 0;
    T_Electeur t_elec = liste;

    while (t_elec != NULL) {
        if(t_elec->choix == 1 || t_elec->choix == 3){
            nb_voix_gauche++;
        }
        t_elec = t_elec->suivant;
    }
    return nb_voix_gauche;
}

void libereliste (T_Electeur liste) {
    T_Electeur t_elec = liste;
    T_Electeur tmp;

    while (t_elec != NULL) {
        tmp = t_elec;
        t_elec = t_elec->suivant;
        free(tmp);
    }
}

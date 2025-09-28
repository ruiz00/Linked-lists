#include "list.h"

void menuPrincipal() {
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Liste simplement chaînée\n");
    printf("2. Liste doublement chaînée\n");
    printf("3. Liste simplement chaînée circulaire\n");
    printf("4. Liste doublement chaînée circulaire\n");
    printf("5. Quitter\n");
    printf("Choix : ");
}

void menuListeSimple() {
    printf("\n--- Liste simplement chaînée ---\n");
    printf("1. Insertion triée\n");
    printf("2. Supprimer toutes occurrences\n");
    printf("3. Afficher\n");
    printf("4. Retour\n");
    printf("Choix : ");
}

void menuListeDouble() {
    printf("\n--- Liste doublement chaînée ---\n");
    printf("1. Insertion triée\n");
    printf("2. Afficher\n");
    printf("3. Retour\n");
    printf("Choix : ");
}

void menuListeSCirculaire() {
    printf("\n--- Liste simplement chaînée circulaire ---\n");
    printf("1. Insertion en tête\n");
    printf("2. Insertion en queue\n");
    printf("3. Afficher\n");
    printf("4. Retour\n");
    printf("Choix : ");
}

void menuListeDCirculaire() {
    printf("\n--- Liste doublement chaînée circulaire ---\n");
    printf("1. Insertion en tête\n");
    printf("2. Insertion en queue\n");
    printf("3. Afficher\n");
    printf("4. Retour\n");
    printf("Choix : ");
}


int main() {
    int choixPrincipal, choixSousMenu, val;
    List liS = NULL;
    Dlist liD = malloc(sizeof(*liD));
    liD->begin = liD->end = NULL;
    Clist liSC = NULL;
    CDList liDC = NULL;

    do {
        menuPrincipal();
        scanf("%d", &choixPrincipal);

        switch (choixPrincipal) {
            case 1:
                do {
                    menuListeSimple();
                    scanf("%d", &choixSousMenu);
                    switch (choixSousMenu) {
                        case 1:
                            printf("Entrez une valeur : ");
                            scanf("%d", &val);
                            liS = sortedInsert(liS, val);
                            break;
                        case 2:
                            printf("Valeur à supprimer : ");
                            scanf("%d", &val);
                            liS = removeOccurence(liS, val);
                            break;
                        case 3:
                            print_list(liS);
                            break;
                    }
                } while (choixSousMenu != 4);
                break;
            case 2:
                do {
                    menuListeDouble();
                    scanf("%d", &choixSousMenu);
                    switch (choixSousMenu) {
                        case 1:
                            printf("Entrez une valeur : ");
                            scanf("%d", &val);
                            liD = sortedDinsert(liD, val);
                            break;
                        case 2:
                            print_dlist(liD);
                            break;
                    }
                } while (choixSousMenu != 3);
                break;
            case 3:
                do {
                    menuListeSCirculaire();
                    scanf("%d", &choixSousMenu);
                    switch (choixSousMenu) {
                        case 1:
                            printf("Entrez une valeur : ");
                            scanf("%d", &val);
                            liSC = insertFront(liSC, val);
                            break;
                        case 2:
                            printf("Entrez une valeur : ");
                            scanf("%d", &val);
                            liSC = insertqueue(liSC, val);
                            break;
                        case 3:
                            print_cslist(liSC);
                            break;
                    }
                } while (choixSousMenu != 4);
                break;
            case 4:
                do {
                    menuListeDCirculaire();
                    scanf("%d", &choixSousMenu);
                    switch (choixSousMenu) {
                        case 1:
                            printf("Entrez une valeur : ");
                            scanf("%d", &val);
                            liDC = insertDCfront(liDC, val);
                            break;
                        case 2:
                            printf("Entrez une valeur : ");
                            scanf("%d", &val);
                            liDC = insertDCqueue(liDC, val);
                            break;
                        case 3:
                            print_cdlist(liDC);
                            break;
                    }
                } while (choixSousMenu != 4);
                break;

            case 5:
                printf("Libération de la mémoire...\n");
                free_slist(liS);
                free_dlist(liD);
                free_cslist(liSC);
                free_cdlist(liDC);
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide\n");
        }

    } while (choixPrincipal != 5);

    return 0;
}

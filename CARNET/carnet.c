#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char nom[50];
    char telephone[15];
} Contact;

Contact* carnet[100]; // Tableau de pointeurs de Contact
int nombreContact = 0; // Nombre actuel de contacts

void ajout() {
    if (nombreContact >= 100) {
        printf("Le carnet est plein.\n");
        return;
    }

    // Allouer de la mémoire pour un nouveau contact
    carnet[nombreContact] = (Contact*)malloc(sizeof(Contact));

    // Saisie des données
    printf("Entrez le nom : ");
    scanf("%s", carnet[nombreContact]->nom);
    printf("Entrez le téléphone : ");
    scanf("%s", carnet[nombreContact]->telephone);

    nombreContact++;
    printf("Contact ajouté avec succès !\n");
}

void affiche() {
    if (nombreContact == 0) {
        printf("Le carnet est vide.\n");
        return;
    }

    printf("Liste des contacts :\n");
    for (int i = 0; i < nombreContact; i++) {
        printf("Contact %d : %s -> %s\n", i + 1, carnet[i]->nom, carnet[i]->telephone);
    }
}

int main() {
    int choix;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Ajouter un contact\n");
        printf("2. Afficher les contacts\n");
        printf("3. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajout();
                break;
            case 2:
                affiche();
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf(":n");
        }
    } while (choix != 3);

    // Libérer la mémoire allouée
    for (int i = 0; i < nombreContact; i++) {
        free(carnet[i]);
    }

    return 0;
}


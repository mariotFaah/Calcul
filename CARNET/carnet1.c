#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char nom[20];
    char numero[15];
} Contact;

Contact* carnet[100];
int nombreCt = 0;

// Fonction pour supprimer le caractère '\n' laissé par fgets
void supprimerRetourLigne(char* chaine) {
    size_t longueur = strlen(chaine);
    if (longueur > 0 && chaine[longueur - 1] == '\n') {
        chaine[longueur - 1] = '\0';
    }
}

void ajout() {
    if (nombreCt >= 100) {
        printf("Le carnet est plein. Vous ne pouvez pas ajouter plus de contacts.\n");
        return;
    }

    carnet[nombreCt] = (Contact*) malloc(sizeof(Contact));
    if (!carnet[nombreCt]) {
        printf("Erreur : Impossible d'allouer de la mémoire.\n");
        return;
    }

    printf("\nEntrer le nom : ");
    fgets(carnet[nombreCt]->nom, sizeof(carnet[nombreCt]->nom), stdin);
    supprimerRetourLigne(carnet[nombreCt]->nom); // Supprimer '\n'

    printf("Entrer le numéro : ");
    fgets(carnet[nombreCt]->numero, sizeof(carnet[nombreCt]->numero), stdin);
    supprimerRetourLigne(carnet[nombreCt]->numero); // Supprimer '\n'

    nombreCt++;
    printf("\nContact ajouté avec succès !\n");
}

void affiche() {
    if (nombreCt == 0) {
        printf("Aucun contact enregistré !\n");
        return;
    }

    for (int i = 0; i < nombreCt; i++) {
        printf("%d - %s : %s\n", i + 1, carnet[i]->nom, carnet[i]->numero);
    }
}

int main() {
    int choix = 0; // Initialisation de choix pour entrer dans la boucle
    char buffer[10]; // Tampon pour lire les choix avec fgets

    while (choix != 3) {
        printf("\n======== MENU ========\n");
        printf("1. Ajouter un contact\n");
        printf("2. Voir les contacts\n");
        printf("3. Quitter\n");
        printf("Entrez votre choix : ");
        fgets(buffer, sizeof(buffer), stdin);
        choix = atoi(buffer); // Convertir en entier

        switch (choix) {
            case 1:
                ajout();
                break;
            case 2:
                affiche();
                break;
            case 3:
                printf("Au revoir !!\n");
                break;
            default:
                printf("Choix invalide. Réessayez.\n");
        }
    }

    for (int i = 0; i < nombreCt; i++) {
        free(carnet[i]);
    }

    return 0;
}


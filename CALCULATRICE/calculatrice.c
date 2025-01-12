#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialisation
    srand(time(NULL));  // Initialise le générateur de nombres aléatoires
    int secret = rand() % 100 + 1;  // Génère un nombre entre 1 et 100
    int nombre = -1;  // Initialisation de la variable pour l'entrée utilisateur

    // Message de bienvenue
    printf("Bienvenue dans le jeu de devinette !\n");
    printf("Essayez de deviner le nombre secret entre 1 et 100.\n");

    // Boucle principale
    while (nombre != secret) {
        printf("\nEntrez votre proposition : ");
        scanf("%d", &nombre);

        if (nombre < secret) {
            printf("Trop petit ! Essayez encore.\n");
        } else if (nombre > secret) {
            printf("Trop grand ! Essayez encore.\n");
        }
    }

    // Message de victoire
    printf("\nBravo, vous avez trouve le nombre secret : %d !\n", secret);
    printf("Felicitation, vous avez gagne !\n");

    return 0;
}

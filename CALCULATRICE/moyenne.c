#include <stdio.h>

int main(){
    int nombreNote, i;
    float moyenne;
    printf("Entrez le nombre de notes: ");
    scanf("%d",&nombreNote);
    if(nombreNote <= 0 ){
        printf("nombre doit etre  + de 1 \n");
        return 1;
    }
    int notes[nombreNote];

    for(i = 0; i < nombreNote; i++){
        printf("Entrez la note %d : ", i+1);
        scanf("%d", &notes[i]);
        if (notes[i] < 0 || notes[i] > 20) {
            printf("Veuillez entrer une note valide (entre 0 et 20).\n");
            i--;
        }
    }

    printf("Les nombres saisis sont: ");
    for(i = 0; i <nombreNote; i++){
        printf("%d \t", notes[i]);
    }

    /*
        sommeNote = notes[i] + notes[i+1];
    */
    int j = 0;
    int sommeNote = 0;
    while( j != nombreNote){
        sommeNote = sommeNote + notes[j];
        j++;
    }
    moyenne = (float)sommeNote / nombreNote;
    printf("\nLa moyenne est de %.2f ", moyenne);
return 0;
}

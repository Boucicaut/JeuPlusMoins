#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int mode() {

int choixMode = 0;
printf("\nVoulez vous jouer a 1 ou 2 joueurs ? \"1\" ou \"2\" ?\n");
scanf("%d", &choixMode);
while (choixMode != 1 && choixMode != 2)
{
    printf("Vous devez entrer \"1\" ou \"2\"\n");
    scanf("%d",&choixMode);
}
return choixMode;
}


int difficulte() {

    int choixDifficulte = 0;

    do {
        printf("Vous avez decide de jouer a un joueur, choisissez la difficulte \n");
        printf("\n\n\t~~~~Difficulte~~~~\n\n");
        printf("\t1- Facile : [0;100]\n");
        printf("\t2- Moyen : [0;1000]\n");
        printf("\t3- Difficile : [0;10000]\n");
        printf("\t\nEntrez \"1\", \"2\" ou \"3\"\n");
        scanf("%d", &choixDifficulte);
    } while (choixDifficulte < 1 || choixDifficulte > 3);

        return choixDifficulte;

}


int rejoue() {
    int rejoue = 1;
    do {
    printf("\n\nVoulez vous rejouer ? \"1\" pour rejouer ou \"0\" ?\n\n");
    scanf("%d",&rejoue);
    } while (rejoue != 1 && rejoue != 0);

    if (rejoue == 1)
        {
        printf("Ok c'est reparti !\n\n");
        printf("-------------------------\n\n");
        }
    return rejoue;
}



int main( int argc, char** argv ) {

int nombre = 0;     // nombre al�atoire � trouver
int guess = 0;      // guess du joueur
int nbEssais = 0;   // nombre d'essais
int a =0, b=0;      // bornes

printf("Bonjour\n");
srand(time(NULL)); // initialisation de la donn�e seed en fonction de time (seconde au 1/1/70)

do {                // Do et While pour REJOUER
    nbEssais = 0;
if (mode() == 1)
    {
        switch (difficulte()) {
            printf("rand()");
            case 1:
                nombre = rand() % (100+1);    // Formule si borne inf�rieure a = 0
                break;
            case 2:
                nombre = rand() % (1000+1);    // Formule si borne inf�rieure a = 0
                break;
            case 3:
                nombre = rand() % (10000+1);    // Formule si borne inf�rieure a = 0
                break;
}
    } else {
        printf("Le second joueur doit choisir les bornes");

        printf("\n\nBorne inferieure ?\n");
        scanf("%d",&a);
        printf("Ok merci\n\nBorne superieure ?\n");
        scanf("%d",&b);
        printf("Ok merci\n\n");                   //PERMET DE DEMANDER LES BORNES INF ET MAX AU JOUEUR

    if (a == 0) {
    nombre = rand() % (b+1);    // Formule si borne inf�rieure a =0
    } else {
    nombre = rand() % (b-a+1)+a; // initialisation du nombre � deviner si borne inf�rieure > 0 (si initialisation par 2nd joueur
}
    }



printf("\n\n[TRICHE] Le nombre a deviner est : %d\n\n", nombre);       // afficher le nombre � deviner


// On devine le nombre
do  {
        printf("Vous devez deviner le nombre, entrez votre reponse\n");
        scanf("%d",&guess);
        nbEssais++;

    if (guess > nombre) {
        printf("C'est moins !!!\n");
    } else if (guess < nombre) {                // CONDITION IF POUR DEVINER LE NOMBRE
        printf("C'est plus !!!\n");
    } else {
        printf("\n\nBRAVO VOUS AVEZ REUSSI !\n");
    }
} while (guess != nombre);              // TANT QUE LE GUESS EST DIFFERENT ON CONTINUE

printf("Vous avez mis %d coups, c'est le record du monde !!! \n",nbEssais);     // NOMBRE DE COUPS MIS POUR TROUVER
printf("FELICITATIONS\n");



} while (rejoue());
printf("\n\nMerci d'avoir joue, aurevoir\n\n");
return 0;
}

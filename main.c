#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma set_character_execution("UTF-8")

int MenuPrincipal();
void InterfaceDeJeu();

int Gride[10][10]={{0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0}};

int Boat1[10][10]={{0,0,0,0,1,0,0,0,0,0},
                   {0,0,0,0,1,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0}};

int Boat2[10][10]={{0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {1,1,1,0,0,0,0,0,0,0}};

int Boat3[10][10]={{0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,1,1,1}};

int Boat4[10][10]={{0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,1,0,0},
                   {0,0,0,0,0,0,0,1,0,0},
                   {0,0,0,0,0,0,0,1,0,0},
                   {0,0,0,0,0,0,0,1,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0}};

int Boat5[10][10]={{1,0,0,0,0,0,0,0,0,0},
                   {1,0,0,0,0,0,0,0,0,0},
                   {1,0,0,0,0,0,0,0,0,0},
                   {1,0,0,0,0,0,0,0,0,0},
                   {1,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0}};

int y;
int x;

void Aide() {
    system("cls");
    printf("--- Aide ---\n");
    printf("Règles du jeu :\n\n");
    printf("- Il y a 5 bateaux différents cachés dans la grille de jeu.\n");
    printf("- Le but est de selectionner des cordonnées où tirer.\n");
    printf("- Un bateau peut être touché ou coulé.\n");
    printf("A toi de jouer !\n\n");
    printf("Bateaux :\n\n");
    printf("Un porte avion (5 cases) \n");
    printf("Un Croiseur (4 cases) \n");
    printf("Deux Contre torpilleurs (3 cases) \n");
    printf("Un Torpilleur (2 cases) \n\n");
    printf("Quelques notions : :\n\n");
    printf("? = non découvert\n");
    printf("X = à l'eau\n");
    printf("O = Touché\n\n");
    system("Pause");
    MenuPrincipal();
}

int Quitter(){
    char Quit;
    system("cls");
    printf("--- Quitter ---\n\n");
    printf("Vous êtes sûr(e) de vouloir quitter? \n\n");
    printf("Réponse (Y/N) : ");
    scanf("%c", &Quit);
    fflush(stdin);
    if(Quit == 89 || Quit == 121 ){

    }
    else{
        if(Quit == 78 || Quit == 110){
            MenuPrincipal();
        }
        else{
            printf("\n\n Mauvaise réponse \n\n");
            Quitter();
        }
    }
}

void Tirer(){
    if(Boat5[x-1][y-1] == 1){
        Gride[x-1][y-1] = 1;
        Boat5[x-1][y-1] = 0;
    }
    else{
        Gride[x-1][y-1] = 2;
        if(Boat4[x-1][y-1] == 1){
            Gride[x-1][y-1] = 1;
            Boat4[x-1][y-1] = 0;
        }
        else{
            Gride[x-1][y-1] = 2;
            if(Boat3[x-1][y-1] == 1){
                Gride[x-1][y-1] = 1;
                Boat3[x-1][y-1] = 0;
            }
            else{
                Gride[x-1][y-1] = 2;
                if(Boat2[x-1][y-1] == 1){
                    Gride[x-1][y-1] = 1;
                    Boat2[x-1][y-1] = 0;
                }
                else{
                    Gride[x-1][y-1] = 2;
                    if(Boat1[x-1][y-1] == 1){
                        Gride[x-1][y-1] = 1;
                        Boat1[x-1][y-1] = 0;
                    }
                    else{
                        Gride[x-1][y-1] = 2;
                    }
                }
            }
        }
    }
    InterfaceDeJeu();
}

void InterfaceDeJeu() {
    //Juste pour faire tourner en boucle histoire de tester
        system("cls");
        printf("--- Bataille Navale ---\n\n");
        printf("     |  1  ||  2  ||  3  ||  4  ||  5  ||  6  ||  7  ||  8  ||  9  || 10  |\n");
        for (char i = 1; i < 11; i++) {
            printf("\n---------------------------------------------------------------------------\n");
            if(i < 10) {
                printf("%d    ", i);
            }
            else{
                printf("%d   ", i);
            }
            for (char e = 1; e < 11; e++) {
                if (Gride[i - 1][e - 1] == 1) {
                    printf("|  O  |");
                } else {
                    if(Gride[i - 1][e - 1] == 2){
                        printf("|  X  |");
                    }
                    else{
                        printf("|  ?  |");
                    }
                }
            }
        }
        printf("\n\n? = Inconnu\n");
        printf("X = A l'eau\n");
        printf("O = Touché");
        printf("\n\nX = ");
        scanf("%d", &y);
        fflush(stdin);
        printf("Y = ");
        scanf("%d", &x);
        fflush(stdin);
        Tirer();
}

void Redirection (Choix){
    switch(Choix){
        case 1:
            InterfaceDeJeu();
            break;
        case 2:
            Aide();
            break;
        case 3:
            Quitter();
            break;
        default:
            break;
    }
}

int MenuPrincipal(){
    int Choix;
    system("cls");
    printf("--- Bataille Navale --- \n");
    printf("1 - Jouer \n");
    printf("2 - Aide \n");
    printf("3 - Quitter \n\n");
    printf("Selection : ");
    scanf("%d", &Choix);
    fflush(stdin);
    Redirection(Choix);
}

int main() {
    SetConsoleOutputCP(65001);

    MenuPrincipal();

    return 0;
}
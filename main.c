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
char y;
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

    if(Boat1[y][x] == 1 || Boat3[y][x] == 1 || Boat4[y][x] == 1 || Boat5[y][x] == 1){
        Gride[y][x] = 1;
        Boat1[y][x] = 0;
        Boat1[y][x] = 0;
        Boat1[y][x] = 0;
        Boat1[y][x] = 0;
        Boat1[y][x] = 0;
    }
    else{
        if(Boat2[y][x] == 1){
            Gride[y][x] = 1;
            Boat1[y][x] = 0;
            Boat1[y][x] = 0;
            Boat1[y][x] = 0;
            Boat1[y][x] = 0;
            Boat1[y][x] = 0;
        }
        else{
            if(Boat3[y][x] == 1){
                Gride[y][x] = 1;
                Boat1[y][x] = 0;
                Boat1[y][x] = 0;
                Boat1[y][x] = 0;
                Boat1[y][x] = 0;
                Boat1[y][x] = 0;
            }
            else{
                if(Boat4[y][x] == 1){
                    Gride[y][x] = 1;
                    Boat1[y][x] = 0;
                    Boat1[y][x] = 0;
                    Boat1[y][x] = 0;
                    Boat1[y][x] = 0;
                    Boat1[y][x] = 0;
                }
                else{
                    if(Boat5[y][x] == 1){
                        Gride[y][x] = 1;
                        Boat1[y][x] = 0;
                        Boat1[y][x] = 0;
                        Boat1[y][x] = 0;
                        Boat1[y][x] = 0;
                        Boat1[y][x] = 0;
                    }
                    else{
                        Gride[y][x] = 9;
                    }
                }
            }
        }
    }
    InterfaceDeJeu();
}

void InterfaceDeJeu(){
    system("cls");
    printf("--- Bataille Navale ---\n\n");
    printf("     |  1 ||  2 ||  3 ||  4 ||  5 ||  6 ||  7 ||  8 ||  9 || 10 |\n");
    for(char i = 'A'; i < 'K'; i++) {
        printf("\n--------------------------------------------------------------------\n");
        printf("%c    ", i);
        for(char e = 1; e < 11 ; e++){
            if(Gride[i-65][e-1] == 1) {
                printf("|  1 |");
            }
            else{
                printf("|    |");
            }
        }
    }
    printf("Y = ");
    scanf("%c", &y);
    fflush(stdin);
    printf("\n");
    printf("X = ");
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
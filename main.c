#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma set_character_execution("UTF-8")

int MenuPrincipal();
void InterfaceDeJeu();

int Boat1Life = 2;
int Boat2Life = 3;
int Boat3Life = 3;
int Boat4Life = 4;
int Boat5Life = 5;
int Try;

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

int score(){
    int Score;
    Score = 100 / Try * 100;
    return Score;
}

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
    system("cls");
    char Quit;
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
            Quitter();
        }
    }
}

void Tirer(){
    if(Boat5[x-1][y-1] == 1){
        Gride[x-1][y-1] = 1;
        Boat5[x-1][y-1] = 0;
        Boat5Life = Boat5Life - 1;
        Try = Try + 1;
    }
    else{
        if(Boat4[x-1][y-1] == 1){
            Gride[x-1][y-1] = 1;
            Boat4[x-1][y-1] = 0;
            Try = Try + 1;
            Boat4Life = Boat4Life - 1;
        }
        else{
            if(Boat3[x-1][y-1] == 1){
                Gride[x-1][y-1] = 1;
                Boat3[x-1][y-1] = 0;
                Try = Try + 1;
                Boat3Life = Boat3Life - 1;
            }
            else{
                if(Boat2[x-1][y-1] == 1){
                    Gride[x-1][y-1] = 1;
                    Boat2[x-1][y-1] = 0;
                    Boat2Life = Boat2Life - 1;
                    Try = Try + 1;
                }
                else{
                    if(Boat1[x-1][y-1] == 1){
                        Gride[x-1][y-1] = 1;
                        Boat1[x-1][y-1] = 0;
                        Boat1Life = Boat1Life - 1;
                        Try = Try + 1;
                    }
                    else{
                        if(Gride[x-1][y-1] == 1) {
                            //Si déjà touché, ne rien faire
                        }
                        else{
                            if(Gride[x-1][y-1] == 2){
                                //Si déjà tiré, ne rien faire
                            }
                            else{
                                Gride[x - 1][y - 1] = 2;
                                Try = Try + 1;
                            }
                        }
                    }
                }
            }
        }
    }
    InterfaceDeJeu();
}

void InterfaceDeJeu() {
    system("cls");
    int ContreTorpilleurNumber = 1;
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
    if(Boat1Life == 0){
        printf("\n\nTorpilleur coulé !");
    }
    if(Boat2Life == 0){
        printf("\n\nContre Torpilleur %d coulé !", ContreTorpilleurNumber);
        ContreTorpilleurNumber++;
    }
    if(Boat3Life == 0){
        printf("\n\nContre Torpilleur %d coulé !", ContreTorpilleurNumber);
        ContreTorpilleurNumber++;
    }
    if(Boat4Life == 0){
        printf("\n\nCroiseur coulé !");
    }
    if(Boat5Life == 0){
        printf("\n\nPorte Avion coulé !");
    }
    if(Boat1Life == 0 && Boat2Life == 0 && Boat3Life == 0 && Boat4Life == 0 && Boat5Life == 0){
        int Score = score();
        printf("\n\nVotre score est de %d points", Score);
        system("\n\nPause");
        MenuPrincipal();
    }
    else{
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
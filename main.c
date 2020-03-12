#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma set_character_execution("UTF-8")

int MenuPrincipal(){
    int Choix;
    printf("--- Bataille Navale --- \n");
    printf("1 - Jouer \n");
    printf("2 - Pseudo \n");
    printf("3 - Leaderboard \n");
    printf("4 - Aide \n");
    printf("5 - Quitter \n\n");
    printf("Séléction : ");
    scanf("%d", &Choix);
    fflush(stdin);
    return Choix;
}

void Redirection (Choix){
    switch(Choix){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
    }
}

int main() {
    SetConsoleOutputCP(65001);

    int Choix = MenuPrincipal();

    Redirection(Choix);
    return 0;
}
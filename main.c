#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma set_character_execution("UTF-8")

int MenuPrincipal(){
    int Choix;
    printf("--- Bataille Navale --- \n");
    printf("1 - Jouer \n");
    printf("2 - Aide \n");
    printf("3 - Quitter \n\n");
    printf("Séléction : ");
    scanf("%d", &Choix);
    fflush(stdin);
    return Choix;
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

void Aide() {
    printf("--- Aide ---\n");
    system("Pause");
}

void Quitter(){
    printf("--- Quitter ---\n");
    system("Pause");
}

void InterfaceDeJeu(){
    printf("--- Bataille Navale ---\n");
    system("Pause");
}

int main() {
    SetConsoleOutputCP(65001);

    int Choix = MenuPrincipal();

    Redirection(Choix);


    return 0;
}
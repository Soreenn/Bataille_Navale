#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma set_character_execution("UTF-8")

int MenuPrincipal();

void Aide() {
    system("cls");
    printf("--- Aide ---\n");
    system("Pause");
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

int Check(){

}

int InterfaceDeJeu(){
    printf("--- Bataille Navale ---\n\n");
    printf("     |  1 ||  2 ||  3 ||  4 ||  5 ||  6 ||  7 ||  8 ||  9 || 10 |\n");
    for(char i = 'A'; i < 'K'; i++) {
        printf("\n--------------------------------------------------------------------\n");
        printf("%c    ", i);
        printf("|    ");
        for(char e = 0; e < 5 ; e++){
            printf("||    ||    ");
        }
    }
    system("Pause");
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
/**
 * author: Gabriel Pereira
 * date: 17.03.2020
 * description: Bataille Navale jouable avec différents menus
 * version: 0.1
 */
/**
* author: Gabriel Pereira
* date: 08.04.2020
* description: Bataille Navale jouable avec différents menus et cartes aléatoires
* version: 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>
//Sert à afficher les caractères latins
#pragma set_character_execution("UTF-8")

//Prototype des fonctions
int MenuPrincipal();
void InterfaceDeJeu();

//Initialisation des variables des HP des différents bateaux et déclaration de la variable du nombre d'essaies
int Boat1Life = 2;
int Boat2Life = 3;
int Boat3Life = 3;
int Boat4Life = 4;
int Boat5Life = 5;
int Try;
int Auth = 0;
int map;
int mapChoosingProcess = 1;
//Mise en place des différentes grilles pour reset, positions des bateaux et tableau affiché en jeux
//Les 0 sont vides et les 1 sont des bateaux (parties de bateaux plus précisément)
int Restart[10][10]={{0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0}};

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

int Boat1[10][10] = {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat1Model[10][10] = {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat2[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}};

int Boat2Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}};

int Boat3[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 1, 1}};

int Boat3Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1}};

int Boat4[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat4Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat5[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat5Model[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat1b[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat1Modelb[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat2b[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat2Modelb[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat3b[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 1, 1, 1, 0, 0, 0, 0}};

int Boat3Modelb[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 1, 1, 0, 0, 0, 0}};

int Boat4b[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat4Modelb[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat5b[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat5Modelb[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat1c[10][10] = {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat1Modelc[10][10] = {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat2c[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat2Modelc[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat3c[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat3Modelc[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat4c[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat4Modelc[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat5c[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat5Modelc[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

//Déclaration des variables de positions
int y;
int x;

/**
 * Fonction de tableau de score malheuresmenet pas abouti
 */
void tableauScore() {
        system("cls");
        printf("1 - None..........0pts\n");
        printf("2 - None..........0pts\n");
        printf("3 - None..........0pts\n");
        printf("4 - None..........0pts\n");
        printf("5 - None..........0pts\n\n");
        system("Pause");
        MenuPrincipal();
}

/**
 * Calcule du score
 * @return du score
 */
int score(){
    int Score;
    Score = 100 / Try * 100;
    return Score;
}

/**
 * Attribution des structures
 */
typedef struct{
    char name[32];
}user;

/**
 * Objet pour l'identification (Aide reçu de Kenan)
 * @return authenticatingUser
 */
user authenticate(){
    user authenticatingUser;

    fflush(stdin);
    scanf("%s",authenticatingUser.name);

    return authenticatingUser;
}

/**
 * Fonction de pseudo
 */
void Pseudo(){
    system("cls");
    printf("--- Pseudo ---\n");
    printf("Entrez un pseudonyme : \n\n");
    user pseudo;
    pseudo = authenticate();
    printf("\n\nBievenue %s !\n\n", pseudo.name);
    system("Pause");
    Auth = 1;
    MenuPrincipal();
}

/**
 * Fonction de l'aide du jeu renvoyant après la pause au Menu Principal
 */
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

/**
 * Fonction permettant de quitter avec une confirmation de l'utilisateur
 */
void Quitter(){
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


/**
 * Fonction permettant de vérifier quel bateau est touché (si touché), sinon, il permettra de définir sois un tire à l'eau sois un tire déjà effectué auparavent
 */
void Tirer(user authenticatingUser) {
    if (map == 1) {
        if (Boat5[x - 1][y - 1] == 1) {
            Gride[x - 1][y - 1] = 1;
            Boat5[x - 1][y - 1] = 0;
            Boat5Life = Boat5Life - 1;
            Try = Try + 1;
        }
        else {
            if (Boat4[x - 1][y - 1] == 1) {
                Gride[x - 1][y - 1] = 1;
                Boat4[x - 1][y - 1] = 0;
                Try = Try + 1;
                Boat4Life = Boat4Life - 1;
            }
            else {
                if (Boat3[x - 1][y - 1] == 1) {
                    Gride[x - 1][y - 1] = 1;
                    Boat3[x - 1][y - 1] = 0;
                    Try = Try + 1;
                    Boat3Life = Boat3Life - 1;
                }
                else {
                    if (Boat2[x - 1][y - 1] == 1) {
                        Gride[x - 1][y - 1] = 1;
                        Boat2[x - 1][y - 1] = 0;
                        Boat2Life = Boat2Life - 1;
                        Try = Try + 1;
                    }
                    else {
                        if (Boat1[x - 1][y - 1] == 1) {
                            Gride[x - 1][y - 1] = 1;
                            Boat1[x - 1][y - 1] = 0;
                            Boat1Life = Boat1Life - 1;
                            Try = Try + 1;
                        }
                        else {
                            if (Gride[x - 1][y - 1] == 1) {
                                //Si déjà touché, ne rien faire
                            }
                            else {
                                if (Gride[x - 1][y - 1] == 2) {
                                    //Si déjà tiré, ne rien faire
                                }
                                else {
                                    Gride[x - 1][y - 1] = 2;
                                    Try = Try + 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        InterfaceDeJeu(authenticatingUser);
    }
    else{
        if (map == 2) {
            if (Boat5b[x - 1][y - 1] == 1) {
                Gride[x - 1][y - 1] = 1;
                Boat5b[x - 1][y - 1] = 0;
                Boat5Life = Boat5Life - 1;
                Try = Try + 1;
            }
            else {
                if (Boat4b[x - 1][y - 1] == 1) {
                    Gride[x - 1][y - 1] = 1;
                    Boat4b[x - 1][y - 1] = 0;
                    Try = Try + 1;
                    Boat4Life = Boat4Life - 1;
                }
                else {
                    if (Boat3b[x - 1][y - 1] == 1) {
                        Gride[x - 1][y - 1] = 1;
                        Boat3b[x - 1][y - 1] = 0;
                        Try = Try + 1;
                        Boat3Life = Boat3Life - 1;
                    }
                    else {
                        if (Boat2b[x - 1][y - 1] == 1) {
                            Gride[x - 1][y - 1] = 1;
                            Boat2b[x - 1][y - 1] = 0;
                            Boat2Life = Boat2Life - 1;
                            Try = Try + 1;
                        }
                        else {
                            if (Boat1b[x - 1][y - 1] == 1) {
                                Gride[x - 1][y - 1] = 1;
                                Boat1b[x - 1][y - 1] = 0;
                                Boat1Life = Boat1Life - 1;
                                Try = Try + 1;
                            }
                            else {
                                if (Gride[x - 1][y - 1] == 1) {
                                    //Si déjà touché, ne rien faire
                                }
                                else {
                                    if (Gride[x - 1][y - 1] == 2) {
                                        //Si déjà tiré, ne rien faire
                                    }
                                    else {
                                        Gride[x - 1][y - 1] = 2;
                                        Try = Try + 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            InterfaceDeJeu(authenticatingUser);
        }
        else{
                if (Boat5c[x - 1][y - 1] == 1) {
                    Gride[x - 1][y - 1] = 1;
                    Boat5c[x - 1][y - 1] = 0;
                    Boat5Life = Boat5Life - 1;
                    Try = Try + 1;
                }
                else {
                    if (Boat4c[x - 1][y - 1] == 1) {
                        Gride[x - 1][y - 1] = 1;
                        Boat4c[x - 1][y - 1] = 0;
                        Try = Try + 1;
                        Boat4Life = Boat4Life - 1;
                    }
                    else {
                        if (Boat3c[x - 1][y - 1] == 1) {
                            Gride[x - 1][y - 1] = 1;
                            Boat3c[x - 1][y - 1] = 0;
                            Try = Try + 1;
                            Boat3Life = Boat3Life - 1;
                        }
                        else {
                            if (Boat2c[x - 1][y - 1] == 1) {
                                Gride[x - 1][y - 1] = 1;
                                Boat2c[x - 1][y - 1] = 0;
                                Boat2Life = Boat2Life - 1;
                                Try = Try + 1;
                            }
                            else {
                                if (Boat1c[x - 1][y - 1] == 1) {
                                    Gride[x - 1][y - 1] = 1;
                                    Boat1c[x - 1][y - 1] = 0;
                                    Boat1Life = Boat1Life - 1;
                                    Try = Try + 1;
                                }
                                else {
                                    if (Gride[x - 1][y - 1] == 1) {
                                        //Si déjà touché, ne rien faire
                                    }
                                    else {
                                        if (Gride[x - 1][y - 1] == 2) {
                                            //Si déjà tiré, ne rien faire
                                        }
                                        else {
                                            Gride[x - 1][y - 1] = 2;
                                            Try = Try + 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                InterfaceDeJeu(authenticatingUser);
        }
    }
}

/**
 * Fonction permettant de faire un reset du jeu en utilisant les tableaux models ainsi que réinitialiser les variables
 */
void ResetGame(){
    for(int o = 0; o < 11; o++){
        Gride[o][o] = Restart[o][o];
        for(int p =1; p < 10; p++){
            Gride[o+p][o] = Restart[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Gride[o][o+l] = Restart[o][o+l];
        }
    }

    for(int o = 0; o < 11; o++){
        Boat1[o][o] = Boat1Model[o][o];
        for(int p =1; p < 10; p++){
            Boat1[o+p][o] = Boat1Model[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat1[o][o+l] = Boat1Model[o][o+l];
        }
    }
    for(int o = 0; o < 11; o++){
        Boat2[o][o] = Boat2Model[o][o];
        for(int p =1; p < 10; p++){
            Boat2[o+p][o] = Boat2Model[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat2[o][o+l] = Boat2Model[o][o+l];
        }
    }
    for(int o = 0; o < 11; o++){
        Boat3[o][o] = Boat3Model[o][o];
        for(int p =1; p < 10; p++){
            Boat3[o+p][o] = Boat3Model[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat3[o][o+l] = Boat3Model[o][o+l];
        }
    }
    for(int o = 0; o < 11; o++){
        Boat4[o][o] = Boat4Model[o][o];
        for(int p =1; p < 10; p++){
            Boat4[o+p][o] = Boat4Model[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat4[o][o+l] = Boat4Model[o][o+l];
        }
    }
    for(int o = 0; o < 11; o++){
        Boat5[o][o] = Boat5Model[o][o];
        for(int p =1; p < 10; p++){
            Boat5[o+p][o] = Boat5Model[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat5[o][o+l] = Boat5Model[o][o+l];
        }
    }

    for(int o = 0; o < 11; o++){
        Boat1b[o][o] = Boat1Modelb[o][o];
        for(int p =1; p < 10; p++){
            Boat1b[o+p][o] = Boat1Modelb[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat1b[o][o+l] = Boat1Modelb[o][o+l];
        }
    }
    for(int o = 0; o < 11; o++){
        Boat2b[o][o] = Boat2Modelb[o][o];
        for(int p =1; p < 10; p++){
            Boat2b[o+p][o] = Boat2Modelb[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat2b[o][o+l] = Boat2Modelb[o][o+l];
        }
    }
    for(int o = 0; o < 11; o++){
        Boat3b[o][o] = Boat3Modelb[o][o];
        for(int p =1; p < 10; p++){
            Boat3b[o+p][o] = Boat3Modelb[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat3b[o][o+l] = Boat3Modelb[o][o+l];
        }
    }
    for(int o = 0; o < 11; o++){
        Boat4b[o][o] = Boat4Modelb[o][o];
        for(int p =1; p < 10; p++){
            Boat4b[o+p][o] = Boat4Modelb[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat4b[o][o+l] = Boat4Modelb[o][o+l];
        }
    }
    for(int o = 0; o < 11; o++){
        Boat5b[o][o] = Boat5Modelb[o][o];
        for(int p =1; p < 10; p++){
            Boat5b[o+p][o] = Boat5Modelb[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat5b[o][o+l] = Boat5Modelb[o][o+l];
        }
    }

    for(int o = 0; o < 11; o++){
        Boat1c[o][o] = Boat1Modelc[o][o];
        for(int p =1; p < 10; p++){
            Boat1c[o+p][o] = Boat1Modelc[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat1c[o][o+l] = Boat1Modelc[o][o+l];
        }
    }
    for(int o = 0; o < 11; o++){
        Boat2c[o][o] = Boat2Modelc[o][o];
        for(int p =1; p < 10; p++){
            Boat2c[o+p][o] = Boat2Modelc[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat2c[o][o+l] = Boat2Modelc[o][o+l];
        }
    }
    for(int o = 0; o < 11; o++){
        Boat3c[o][o] = Boat3Modelc[o][o];
        for(int p =1; p < 10; p++){
            Boat3c[o+p][o] = Boat3Modelc[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat3c[o][o+l] = Boat3Modelc[o][o+l];
        }
    }
    for(int o = 0; o < 11; o++){
        Boat4c[o][o] = Boat4Modelc[o][o];
        for(int p =1; p < 10; p++){
            Boat4c[o+p][o] = Boat4Modelc[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat4c[o][o+l] = Boat4Modelc[o][o+l];
        }
    }
    for(int o = 0; o < 11; o++){
        Boat5c[o][o] = Boat5Modelc[o][o];
        for(int p =1; p < 10; p++){
            Boat5c[o+p][o] = Boat5Modelc[o+p][o];
        }
        for(int l =1; l < 10; l++){
            Boat5c[o][o+l] = Boat5Modelc[o][o+l];
        }
    }

    Try = 0;
    Boat1Life = 2;
    Boat2Life = 3;
    Boat3Life = 3;
    Boat4Life = 4;
    Boat5Life = 5;
}

/**
 * Fonction d'affichage de la grille de jeu, vérification des HP des bateaux et affichage du score
 */
void InterfaceDeJeu(user authenticatingUser) {
    system("cls");
    if(Auth == 0){
        printf("Oops, vous n'êtes pas identifié !\n");
        system("Pause");
        MenuPrincipal();
    }
    if(mapChoosingProcess == 1) {
        srand((unsigned)time(NULL));
        map = 1 + rand() % 3;
        mapChoosingProcess = 0;
    }
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
        printf("\n\nVotre score est de %d points !\n\n", Score);
        system("Pause");
        ResetGame();
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
        Tirer(authenticatingUser);
    }
}

/**
 * Redirection dans les différents menus
 */
void Redirection (int Choix, user authenticatingUser){
    switch(Choix){
        case 1:
            InterfaceDeJeu(authenticatingUser);
            break;
        case 2:
            Pseudo();
            break;
        case 3:
            Aide();
            break;
        case 4:
            Quitter();
            break;
        default:
            MenuPrincipal();
            break;
    }
}

/**
 * Fonction d'affichage du Menu Principal et de demande de choix
 * @return du choix
 */
int MenuPrincipal(user authenticatingUser){
    system("cls");
    int Choix;
    system("cls");
    printf("--- Bataille Navale --- \n");
    printf("1 - Jouer \n");
    printf("2 - Pseudo \n");
    printf("3 - Aide \n");
    printf("4 - Quitter \n\n");
    printf("Selection : ");
    scanf("%d", &Choix);
    fflush(stdin);
    Redirection(Choix, authenticatingUser);
}

/**
 * Fonction main contenant de quoi afficher les caractères latins et lancement du Menu Principal
 * @return
 */
int main(user authenticatingUser){
    SetConsoleOutputCP(65001);

    MenuPrincipal(authenticatingUser);

    return 0;
}
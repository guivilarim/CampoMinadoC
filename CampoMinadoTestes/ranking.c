
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "menu.h"
#include "ranking.h"
#define Backspace 8


void addRanking(double timePlayer)
{
    FILE *ranking;
    ranking = fopen("ranking.txt", "a+");
    char nome[12];

    //timer.dif = difftime(timer.end, timer.start);

    if(ranking == NULL)
    {
        printf("ERRO AO ABRIR O RANKING");
    }

    printf("Digite o seu nome:\n");
    gotoxy(55, 26);
    scanf("%s", nome);


    fprintf(ranking,"%s\t\t %lf\n", nome, timePlayer);

    fclose(ranking);
}

void printRanking()
{
    char nome[12];
    double timeRanking;
    int tecla = 0;

    FILE *ranking;
    ranking = fopen("ranking.txt", "r");

    printf("\n\n\t NOME\t\t |  TIME\n");

    while(fscanf(ranking,"%s   \t\t%lf", nome, &timeRanking) != EOF)
    {
        printf("\t%s \t\t    %lfs\n", nome, timeRanking);
    }

    printf("\n\n\t\t \(Utileze o backspace para voltar ao menu\)\n");

    while(1)
    {
        tecla = getch();
        if(tecla == Backspace)
        {
            system("cls");
            menu();
            break;
        }
    }

    fclose(ranking);


}

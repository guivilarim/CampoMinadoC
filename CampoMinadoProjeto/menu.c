#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "instrucoes.h"
#include "campos.h"

void menu()
{
    int opcoes, pausa;

    do
    {
        system("cls");
        printf("\t\t\tCAMPO MINADO\n\n1- JOGAR\n2- INSTRUCOES\n3- RANKING\n4- SAIR\n");
        scanf("%d", &opcoes);
        switch(opcoes)
        {
        case 1:
            system("cls");
            printf("Carregando o jogo. . .");
            Sleep(100);
            campoFacil();
            pausa = getch();
            break;
        case 2:
            system("cls");
            Sleep(100);
            instrucoes();
            pausa = getch();
            break;
        case 3:
            system("cls");
            Sleep(100);
            printf("Ranking");
            pausa = getch();
            break;
        case 4:
            system("cls");
            printf("Voce esta saindo do jogo. . .");
            Sleep(2000);
            exit(0);
            break;

        }
    }
    while(1);
}

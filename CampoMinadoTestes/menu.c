#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu()
{
    char pausa;
    char opcoes;

    do
    {
        system("cls");
        gotoxy(58, 12);
        printf("Campo Minado: \n");
        gotoxy(58, 13);
        printf(" 1-Jogar\n");
        gotoxy(58, 14);
        printf(" 2-Ranking\n");
        gotoxy(58, 15);
        printf(" 3-Instrucoes\n");
        gotoxy(58, 16);
        printf(" 4-Sair\n");
        scanf(" %c", &opcoes);

        switch(opcoes)
        {
        case '1':
            system("cls");
            niveis();
            pausa = getch();
            break;
        case '2':
            system("cls");

            printRanking();
            pausa = getch();
            break;
        case '3':
            system("cls");
            instrucoes();
            pausa = getch();
            break;
        case '4':
            system("cls");
            Sleep(2000);
            gotoxy(58,15);
            printf("VOCE SAIU\n");
            pausa = getch();
            exit(0);
        }
    }
    while(1);
}

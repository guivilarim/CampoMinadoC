
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "menu.h"
#include "campo.h"
#define Backspace 8


void niveis()
{
    char pausa;
    char opcoes;
    int tecla = 0;




    do
    {
        system("cls");
        gotoxy(58, 12);
        printf(" Niveis:\n");
        gotoxy(58, 13);
        printf(" 1-Facil\n");
        gotoxy(58, 14);
        printf(" 2-Medio\n");
        gotoxy(58, 15);
        printf(" 3-Dificil\n");
        gotoxy(15, 25);
        printf(" \(Utilize o backspace para voltar ao menu\)\n");
        tecla = getch();
        if(tecla == Backspace)
        {
            system("cls");
            menu();
            break;
        }
        scanf(" %c", &opcoes);



        switch(opcoes)
        {
        case '1':
            system("cls");
            campo3(1);
            pausa = getch();
            break;
        case '2':
            system("cls");
            campo3(2);
            pausa = getch();
            break;
        case '3':
            system("cls");
            campo3(3);
            pausa = getch();
            break;
        }
    }
    while(1);

}

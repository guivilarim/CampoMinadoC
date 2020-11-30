#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "menu.h"

#define Backspace 8

void instrucoes()
{
    int tecla = 0;

    printf("\n\n\t Instrucoes:\n\n\n");
    printf("\t Objetivo: Encontrar espacos vazios e evitar as bombas.\n\t Quanto mais rapido voce esvaziar o tabuleiro maior sera a sua pontuacao!\n\n");
    printf("\t 1- As regras sao simples, se voce descobrir uma bomba o jogo acaba,\n\t se voce descobrir um quadrado vazio o jogo continua.\n\n");
    printf("\t 2- Caso apareca algum numero, ele informara quantas bombas estao escondidas nos 8 quadrados que o cercam.\n");
    printf("\t    Voce pode usar essa informacao para deduzir em quais quadrados eh seguro clicar.\n\n");
    printf("\t 3- Se voce desconfia que algum quadrado contem uma bomba, marque-o.\n\n");
    printf("\t 4- Utilize as teclas W,A,S e D para mover o cursor do jogo.\n\n");
    printf("\t 5- Utilize a tecla ESPACO para revelar o que esta escondido.\n\n");
    printf("\t Bom Jogo!!!\n\n\n\n\n\n\n\n");

    printf("\t\t \(Utilize o backspace para voltar ao menu\)\n");

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
}

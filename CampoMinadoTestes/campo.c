#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "ranking.h"
#include "menu.h"
#define ESPACO 32
#define Backspace 8
#define enter 13
char tabuleiro[30][30][2];

void limpaCampo(int x,int y)
{
    //metodo para tentar abrir as casas
    printf("%c", tabuleiro[y
           ]][x][0]);
    if(tabuleiro[y][x][0]== '0'){
        printf("%c", tabuleiro[y+1][x][0]);
        if(tabuleiro[y+1][x][0]=='0'){
            limpaCampo(y+1,x);
        }
        else
            return;
    }
    if(tabuleiro[y][x][0]== '0'){
        printf("%c", tabuleiro[y-1][x][0]);
        if(tabuleiro[y-1][x][0]=='0'){
            limpaCampo(y-1,x);
        }
        else
            return;
    }
    if(tabuleiro[y][x][0]== '0'){
        printf("%c", tabuleiro[y][x+1][0]);
        if(tabuleiro[y][x+1][0]=='0'){
            limpaCampo(y,x+1);
        }
        else
            return;
    }
    if(tabuleiro[y][x][0]== '0'){
        printf("%c", tabuleiro[y][x-1][0]);
        if(tabuleiro[y][x-1][0]=='0'){
            limpaCampo(y,x-1);
        }
        else
            return;
    }
}



void campo3(int dificul)
{
    srand(time(NULL));
    int i, j, contador, tamanho, bomba, lixo, band = 0, pontos=0;
    int contErro = 0;
    int x = 0, y = 0, tecla;
    //char nome[12];
    /*char tabuleiro[30][30][2];*/
    double timePlayer = 0;

    time(&timer.start);

    if (dificul == 1)
    {
        tamanho = 20;
        bomba = 20;
    }
    else if(dificul == 2)
    {
        tamanho = 25;
        bomba = 25;
    }
    else if(dificul == 3)
    {
        tamanho = 30;
        bomba = 30;
    }

    for(i = 0; i < tamanho; i++)
    {
        for(j = 0; j < tamanho; j++)
        {
            if((i == 0 || i == (tamanho-1)) && (j == 0 || j == (tamanho-1)))
                tabuleiro[i][j][0] = '+';

            else if((i == 0 || i == (tamanho-1)))
                tabuleiro[i][j][0] = '+';

            else if(j != i && (j == 0 || j == (tamanho-1)))
                tabuleiro[i][j][0] = '+';

            else
                tabuleiro[i][j][0] = 48;
                //colocar os valores  48 em char é 0
        }
    }



    for(contador = 0; contador < bomba; contador++)
    {
        x = rand() % bomba;
        y = rand() % bomba;
        if(tabuleiro[x][y][0] != '*' && x != 0 && x != (tamanho-1) && y != 0 && y != (tamanho-1))
            tabuleiro[x][y][0] = '*';
        else
            contador--;
    }


    for(i = 0; i < tamanho; i++)
    {
        for(j = 0; j < tamanho; j++)
        {
            if (tabuleiro[i][j][0] == '*')
            {
                if(tabuleiro[i-1][j][0] == '*' || tabuleiro[i-1][j][0] == '+')
                    lixo++;

                else
                    tabuleiro[i-1][j][0]++;

                if(tabuleiro[i+1][j][0] == '*' || tabuleiro[i+1][j][0] == '+')
                    lixo++;

                else
                    tabuleiro[i+1][j][0]++;

                if(tabuleiro[i][j-1][0] == '*' || tabuleiro[i][j-1][0] == '+')
                    lixo++;

                else
                    tabuleiro[i][j-1][0]++;

                if(tabuleiro[i][j+1][0] == '*' || tabuleiro[i][j+1][0] == '+')
                    lixo++;

                else
                    tabuleiro[i][j+1][0]++;

                if(tabuleiro[i-1][j-1][0] == '*' || tabuleiro[i-1][j-1][0] == '+')
                    lixo++;

                else
                    tabuleiro[i-1][j-1][0]++;

                if(tabuleiro[i+1][j+1][0] == '*' || tabuleiro[i+1][j+1][0] == '+')
                    lixo++;

                else
                    tabuleiro[i+1][j+1][0]++;

                if(tabuleiro[i-1][j+1][0] == '*' || tabuleiro[i-1][j+1][0] == '+')
                    lixo++;

                else
                    tabuleiro[i-1][j+1][0]++;

                if(tabuleiro[i+1][j-1][0] == '*' || tabuleiro[i+1][j-1][0] == '+')
                    lixo++;

                else
                    tabuleiro[i+1][j-1][0]++;
                    //contador lixo n serve p nada apenas foi a maneira que conseguimos fzr pois o codeblocks é bugado

            }
        }
        printf("\n");
    }


    for(i = 0; i < tamanho; i++)
    {
        for(j = 0; j < tamanho; j++)
        {
            if(i==0 || i== (tamanho-1) || j==0 || j==(tamanho-1))
                tabuleiro[i][j][1]=tabuleiro[i][j][0];
                //bordas
            else
                tabuleiro[i][j][1] = 254;
                //esconder o tabuleiro
        }
    }

    gotoxy(0,0);
    for(i = 0; i < tamanho; i++)
    {
        for(j = 0; j < tamanho; j++)
        {
            printf("%c", tabuleiro[i][j][1]);
        }
        printf("\n");
    }
    printf("\n");
    for(i = 0; i < tamanho; i++)
    {
        for(j = 0; j < tamanho; j++)
        {
            printf("%c", tabuleiro[i][j][0]);
        }
        printf("\n");
    }

    x = 1;
    y = 1;

    while(1)
    {
        //para usar as teclas wasd
        gotoxy(x,y);
        if(kbhit())
        {

            tecla = getch();

            if(tecla == 'd' && x < tamanho-2)//tamanho-2 para não chegar na borda do mapa
            {
                x++;
                contErro++;
            }
            else if(tecla == 'a' && x >= 2)
            {
                x--;
                contErro--;
            }
            else if(tecla == 'w' && y >= 2)
                y--;
            else if(tecla == 's' && y < tamanho-2)
                y++;

            else if(tecla == 'b' && band<bomba && tabuleiro[y][x][1] != 'P')
                {

                        tabuleiro[y][x][1] = 'P';
                        printf("%c", tabuleiro[y][x][1]);
                        band++;
                        //limitar a quantidade bombas


                }
            else if(tecla == 'n' && tabuleiro[y][x][1]== 'P')
                {

                        tabuleiro[y][x][1] = 254;
                        printf("%c", tabuleiro[y][x][1]);
                        band--;
                }

            gotoxy(50,10);
            printf("                  ");
            gotoxy(50,10);
            printf("%d    %d", x, y);
            gotoxy(x,y);

            // ESPACO revela o que esta escondido
            if (tecla == ESPACO && tabuleiro[y][x][1]!= 'P')
            {
                //tabuleiro[x][y][1]= tabuleiro[x][y][0];
                printf("%c", tabuleiro[y][x][0]);
                if(tabuleiro[y][x][0]== '*')
                {
                    system("cls");
                    for(i=0; i<tamanho; i++)
                    {
                        for(j=0; j<tamanho; j++)
                        {
                            printf("%c", tabuleiro[i][j][0]);
                        }
                        printf("\n");
                    }

                    time(&timer.end);
                    timePlayer = difftime(timer.end, timer.start);//diferenca de tempo do inicio e o fim do jogo em segundos

                    gotoxy(55,21);
                    printf("Minas acertadas = %d", pontos);
                    gotoxy(55,23);
                    printf("Voce perdeu. . . e gastou: %lfs\n\n", timePlayer);
                    gotoxy(55, 25);
                    addRanking(timePlayer);
                    gotoxy(55,30);
                    printf("(Utilize o backspace para voltar ao menu)\n");
                    break;


                    }


                    if(tabuleiro[y][x][0]== '0'){
                    limpaCampo(y,x);
                    }




            }
            if(tabuleiro[y][x][1]== 'P' && tabuleiro [y][x][0]== '*')
            {
                pontos++;
                if(pontos == bomba)
                {
                    time(&timer.end);
                    timePlayer = difftime(timer.end, timer.start);//diferenca de tempo do inicio e o fim do jogo em segundos

                    gotoxy(55,23);
                    printf("Voce venceu! ! ! e gastou: %lfs\n\n", timePlayer);
                    gotoxy(55, 25);
                    addRanking(timePlayer);
                    gotoxy(55,30);
                    printf("(Utilize o backspace para voltar ao menu)\n");
                    break;

                }
            }




            }

            if(tecla == Backspace)
            {
                system("cls");
                menu();
                break;
            }

        }

    }





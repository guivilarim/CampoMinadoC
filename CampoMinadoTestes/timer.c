#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "ranking.h"

void tempo()
{
    int  i = 0;

    time(&timer.start);//inicia quando o cursor do jogo estiver em movimento
    Sleep(1000);
    time(&timer.end);// quando o jogo tiver acabado
    timer.dif = difftime(timer.end, timer.start);//diferenca de tempo do inicio e o fim do jogo em segundos
    printf("%lf", timer.dif);



    while(i < 10)
    {
        printf("\t %ds", timer.sec);
        Sleep(1000); // vai pausar o programa por 1 segundo
        system("cls");
        timer.sec++;

        if(timer.sec == 60)
        {
            timer.sec = 0;
        }

    }

}

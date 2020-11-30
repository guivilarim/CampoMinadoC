#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void campoFacil()
{
    system("cls");
    int i,j, contador,cont,x,y, lixo=0;
    char matriz[10][10];
    char tabuleiro[10][10][2];

    for(i=0; i<10; i++){
        for(j=0;j<10;j++){
            if((i== 0 || i== 9) && (j== 0 || j== 9))
            {
                matriz[i][j]= '+';
            }
            else if( i==0 || i==9)
            {
                matriz[i][j]= '+';
            }
            else if( j!=i && (j==0 || j==9))
            {
                matriz[i][j]= '+';
            }
            else
            {
                matriz[i][j] = 48;
            }
        }
    }

    struct celula
    {
        char caractere;
        COORD coordenada;
    };

    srand(time(NULL));
    struct celula celulas[10][10];


    for(contador=0; contador<9;contador++)
    {
     for(cont=0;cont<9;cont++)
     {
         celulas[contador][cont].caractere = ' ';
     }
    }
    for(contador=0;contador<9;contador++)
    {
        x=rand()%9;
        y=rand()%9;
        if(matriz[x][y] != '*' && x != 0 && x !=9 && y != 0 && y != 9)
            matriz[x][y] = '*';
        else contador--;
    }
    for(contador = 0; contador<9; contador++)
    {
        for(cont=0;cont<9;cont++)
        {
         if(matriz[contador][cont]== '*' && i!=0 && i!=9 && j !=0 && j!=9)
         {
             if(matriz[contador-1][cont] == '*' || matriz[contador-1][cont] == '+')
             lixo++;
             else
            matriz[contador-1][cont]++;
             if(matriz[contador+1][cont] == '*' ||  matriz[contador+1][cont] == '+')
             lixo++;
             else
            matriz[contador+1][cont]++;
             if(matriz[contador][cont-1] == '*' ||  matriz[contador][cont-1] == '+')
             lixo++;
             else
            matriz[contador][cont-1]++;
             if(matriz[contador][cont+1] == '*' || matriz[contador][cont+1] == '+')
             lixo++;
             else
            matriz[contador][cont+1]++;
             if(matriz[contador-1][cont-1] == '*' || matriz[contador-1][cont-1] == '+')
             lixo++;
             else
            matriz[contador-1][cont-1]++;
             if(matriz[contador+1][cont+1] == '*' || matriz[contador+1][cont+1] == '+')
             lixo++;
             else
            matriz[contador+1][cont+1]++;
             if(matriz[contador-1][cont+1] == '*' || matriz[contador-1][cont+1] == '+')
             lixo++;
             else
            matriz[contador-1][cont+1]++;
             if(matriz[contador+1][cont-1] == '*' || matriz[contador+1][cont-1] == '+')
             lixo++;
             else
            matriz[contador+1][cont-1]++;
         }
        }
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(matriz[i][j]=='0')
                matriz[i][j]== ' ';
        }
    }

    for(i =0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
         printf("%2c", matriz[i][j]);
        }
        printf("\n");
    }

}

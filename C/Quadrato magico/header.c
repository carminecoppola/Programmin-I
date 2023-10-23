
// Created by Carmine on 03/01/2021.


#include "header.h"

int in_arr(int a[][100],int num,int n_ut)
{
    for ( int i = 0; i < n_ut; i++) {
        for ( int j = 0; j < n_ut; j++){   //Per verificare se il numero generato sia presente all'interno della matrice
            if(num == a[i][j]){
                return 1;
            }
        }
    }
    return 0;
}
void riempi_arr(int a[][100],int n_ut)
{
    for (int i = 0; i < n_ut; i++) {            //Viene utilizzata per riempire la matrice di zeri
        for (int j = 0; j < n_ut; j++) {
            a[i][j]=0;
        }
    }
}
int costante_magica(int n_ut)
{
    return (n_ut *(n_ut * n_ut + 1)) /2;        //Formula per calcolare la costante magica [n*(n^2)]/2
}
int operazioni(int a[][100], int magic,int n_ut)
{
    int i,j;                            //(i su righe, j su colonne)
    int som_rig,som_col,som_d1,som_d2;

    /*ESEGUO LE OPERAZIONI*/

    /*Eseguo il controllo delle RIGHE*/

    som_rig=0;
    for(i=0; i < n_ut;i++) {
        for(j=0; j< n_ut; j++)
            som_rig+=a[i][j];
        if (som_rig!=magic)
            return 6;                          /*6 codice errore sulle righe*/
        else
            som_rig=0;
    }
    /* Eseguo il controllo delle COLONNE*/

    som_col=0;
    for(j=0; j < n_ut; j++){
        for(i=0; i < n_ut; i++)
            som_col+=a[i][j];
        if (som_col!=magic)
            return 7;                        /*7 codice errore sulle righe*/
        else
            som_col=0;
    }

    /*Eseguo il controllo della Prima Diagonale Principale (Dx)*/

    som_d1=0;
    for(i=0; i < n_ut; i++)
        som_d1+=a[i][i];
    if(som_d1!=magic)
        return 8;                   /*8 codice errore diagonale 1*/

    /*Eseguo il controllo della Seconda Diagonale Principale (Sx)*/
    som_d2=0;
    for(i=0; i < n_ut;i++)
        som_d2+=a[i][n_ut-1-i];     /*forse n-i*/
    if(som_d2!=magic)
        return 9;                /*9 codice errore su diagonale 2*/

    return 0;                   /*0 codice che indica che è un quadrato magico*/
}
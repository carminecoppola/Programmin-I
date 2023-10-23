//
// Created by Carmine on 19/01/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct Correntista {
    char Nome[50];
    char Cognome[50];
    int ID_UTENTE;

    struct Correntista *new_user;

} Correntista;

typedef struct Movimenti_Bancari{
    Correntista dati_utente;     //ID_conto-Nome-Cognome
    int operazione;             //1)Deposito-2)Prelievo
    float saldo;               //Saldo del conto
    Data  data;               //Data di un operazione

} Movimenti;

#ifndef CONTO_CORRENTE_FINITO_HEADER_H
#define CONTO_CORRENTE_FINITO_HEADER_H

#endif //CONTO_CORRENTE_FINITO_HEADER_H

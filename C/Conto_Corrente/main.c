#include <stdio.h>
#include "header.h"
#define MAX_CORR 10
#define MAX_MOVIM 10
int main() {

    //Definisco la mia Lista di Correntisti
    Correntista correntista[MAX_CORR];
    Movimenti  movi[MAX_MOVIM];

    char nom_ins[20],cog_ins[20];
    int scelta=0,sec_scelta=0,scelta_op=0;
    int id_utente=1;
    int i_correntista=0;
    int i_movi=0;
    int i;
    int meseinteresse;
    int day,month,year;
    char name_ins,surname_ins;
    int cod_ut_inserito;
    float quantita_prel=0.00;
    float quantita_dep=0.00;
    int trovato=0;
    while(scelta!=-1) {
        printf("----------------------------------------\n");
        printf("|                                      |\n");
        printf("|   Menu Iniziale:                     |\n");
        printf("|   1) Inserisci nuovo Correntista     |\n");
        printf("|   2) Correntista gia esistente       |\n");
        printf("|   9) Esci                            |\n");
        printf("|                                      |\n");
        printf("----------------------------------------\n");
        printf("Scegli:");
        scanf("%d",&scelta);
        //Tramite uno switch il programma esegue diverse procedure
        switch (scelta) {
            case 9:{
                exit(0);
            }
            case 1: {

                printf("\nInserisci il Nome:");
                scanf("%s",nom_ins);
                printf("Inserisci il Conome:");
                scanf("%s",cog_ins);
                printf("\nQuesto e' il tuo Id_utente:%d\n",id_utente);

                //copio i dati nella struct Correntista
                strcpy(correntista[i_correntista].Nome,nom_ins);
                strcpy(correntista[i_correntista].Cognome, cog_ins);
                correntista[i_correntista].ID_UTENTE=id_utente;
                //copio i dati nei movimenti correntistari
                movi[i_movi].saldo=0.00;

                movi[i_movi].dati_utente=correntista[i_correntista];

                id_utente++;
                i_correntista++;
                i_movi++;
                printf("\n**Il Correntista e' stato inserito**\n\n");
            }break;

            case 2:{
                printf("\nScegliere quale di questo dato si vuole inserire\n1)Nome\n2)Cognome\n3)ID_utente");
                printf("\nScelta:");
                scanf("%d",&sec_scelta);


                /*Ho scelto di inserire il NOME*/
                if (sec_scelta==1) //ho scelto di inserire il nome
                {
                    printf("\nInserisci il nome:");
                    scanf("%s",&name_ins);
                    //verifico se il correntista esisre
                    for (i = 0; i < MAX_MOVIM; i++){
                        if (strcmp(movi[i].dati_utente.Nome,nom_ins)) {
                            trovato=1;
                            printf("\n***IL NOME E' CORRETTO***\n");
                            printf("\n\n");
                            printf("\n\n");
                            printf("****************************************\n");
                            printf("*   Menu Operazioni:                   *\n");
                            printf("*   1) Prelievo                        *\n");
                            printf("*   2) Versamento                      *\n");
                            printf("*   3) Lista Movimenti                 *\n");
                            printf("*   9) Uscire                          *\n");
                            printf("****************************************\n");
                            printf("\n Scelta:");
                            scanf("%d", &scelta_op);
                            switch (scelta_op) {
                                //CASO DI USCITA
                                case 9:{

                                    exit(0);
                                }
                                    //PRELIEVO
                                case 1: {
                                    printf("\nInserire la quantita' da prelevare:");
                                    scanf("%f", &quantita_prel);

                                    if (quantita_prel < movi[i].saldo) {
                                        //Inserisco la data dell'operazione
                                        printf("\nInserisci data nel formato giorno/mese/anno (Es: 10/11/2012):");
                                        scanf("%d/%d/%d", &day, &month, &year);
                                        movi[i].data.giorno = day;
                                        movi[i].data.mese = month;
                                        movi[i].data.anno = year;

                                        movi[i_movi]=movi[i];

                                        movi[i_movi].saldo =
                                                movi[i_movi].saldo - quantita_prel; //sottraggo l'importo inserito al saldo

                                        printf("\nIl prelievo e' andato a buon fine\n");
                                        printf("\nIl tuo saldo e':%f\n",movi[i_movi].saldo);
                                        movi[i_movi].operazione=2;//Aggiungo il tipo di operazione
                                        i_movi++;
                                    } else{
                                        printf("\nIl saldo e' insufficiente\n");
                                    }
                                }break;
                                    //DEPOSITO
                                case 2: {
                                    //Faccio inserire la data dell'operazione
                                    printf("Inserisci data nel formato giorno/mese/anno (Es: 10/11/2012) :");
                                    scanf("%d/%d/%d", &day, &month, &year);
                                    movi[i].data.giorno = day;
                                    movi[i].data.mese = month;
                                    movi[i].data.anno = year;


                                    movi[i_movi]=movi[i];


                                    //Effettuo l'accredito
                                    printf("\nInserire la quantita' da accreditare:");
                                    scanf("%f", &quantita_dep);

                                    movi[i_movi].saldo = movi[i_movi].saldo + quantita_dep;

                                    //Aggiungo un'operazione poiche è stata effettuata
                                    movi[i_movi].operazione=1;//Aggiungo il tipo di operazione
                                    printf("\nIl tuo saldo e':%f\n",movi[i_movi].saldo);
                                    printf("\n\n***L'accredito e' avvenuto correttamente***\n\n");
                                    i_movi++;
                                }break;
                                    //LISTA MOVIMENTI
                                case 3: {
                                    //Faccio inserire la data dell'operazione
                                    printf("\nInserisci il mese di interesse:");
                                    scanf("%d",&meseinteresse);

                                    //movi[i] è il mio correntista

                                    for (int j = 0; j < MAX_MOVIM; j++){

                                        if(movi[i].dati_utente.ID_UTENTE == movi[j].dati_utente.ID_UTENTE){

                                            if(movi[i].data.mese==meseinteresse){

                                                printf("\nQuesti sono i movimenti correntistari che hai fatto:\nNumero di movimenti=%d\n\n", movi[i].operazione);

                                            }
                                        }

                                    }

                                    movi[i].data.giorno = day;
                                    movi[i].data.mese = month;
                                    movi[i].data.anno = year;

                                }break;
                            }
                            break;
                        }
                    }
                    if (trovato!=1){//IL NOME NON E' STATO TROVATO
                        printf("\n\nIl nome non e' stato torovato");
                    }
                    trovato=0;
                }

                /*Ho scelto di inserire il COGNOME*/
                if (sec_scelta==2){
                    printf("\nInserisci il cognome:");
                    scanf("%s",&cog_ins);
                    //verifico se il correntista esisre
                    for (i = 0; i < MAX_MOVIM; i++){
                        if (strcmp(movi[i].dati_utente.Cognome,cog_ins)) {
                            trovato=1;
                            printf("\n***IL COGNOME E' CORRETTO***\n");
                            printf("\n\n");
                            printf("\n\n");
                            printf("****************************************\n");
                            printf("*   Menu Operazioni:                   *\n");
                            printf("*   1) Prelievo                        *\n");
                            printf("*   2) Versamento                      *\n");
                            printf("*   3) Lista Movimenti                 *\n");
                            printf("*   9) Uscire                          *\n");
                            printf("****************************************\n");
                            printf("\n Scelta:");
                            scanf("%d", &scelta_op);

                            switch (scelta_op) {
                                //CASO DI USCITA
                                case 9:{
                                    exit(0);
                                }
                                    //PRELIEVO
                                case 1: {
                                    //Effettuo il prelievo
                                    printf("\nInserire la quantita' da prelevare:");
                                    scanf("%f", &quantita_prel);

                                    if (quantita_prel < movi[i].saldo) {

                                        //Inserisco la data dell'operazione
                                        printf("\nInserisci data nel formato giorno/mese/anno (Es: 10/11/2021):");
                                        scanf("%d/%d/%d", &day, &month, &year);
                                        movi[i].data.giorno = day;
                                        movi[i].data.mese = month;
                                        movi[i].data.anno = year;

                                        movi[i_movi]=movi[i];

                                        movi[i_movi].saldo = movi[i_movi].saldo - quantita_prel; //sottraggo l'importo inserito al saldo

                                        printf("\nIl prelievo e' andato a buon fine\n");
                                        printf("\nIl tuo saldo e':%f\n",movi[i_movi].saldo);
                                        movi[i_movi].operazione=2;//Aggiungo il tipo di operazione
                                        i_movi++;
                                    } else{
                                        printf("\nIl saldo e' insufficiente\n");
                                    }
                                }break;
                                    //DEPOSITO
                                case 2: {
                                    //Faccio inserire la data dell'operazione
                                    printf("Inserisci data nel formato giorno/mese/anno (Es: 10/11/2012) :");
                                    scanf("%d/%d/%d", &day, &month, &year);
                                    movi[i].data.giorno = day;
                                    movi[i].data.mese = month;
                                    movi[i].data.anno = year;

                                    movi[i_movi]=movi[i];

                                    /*Effettuo l'accredito*/
                                    printf("\nInserire la quantita' da accreditare:");
                                    scanf("%f", &quantita_dep);

                                    movi[i_movi].saldo = movi[i_movi].saldo + quantita_dep;

                                    /*Aggiungo un'operazione poiche è stata effettuata*/
                                    movi[i_movi].operazione=1;//Aggiungo il tipo di operazione
                                    printf("\n***L'accredito e' avvenuto correttamente***\n\n");
                                    printf("\nIl tuo saldo e':%f\n",movi[i_movi].saldo);
                                    i_movi++;
                                }break;
                                    //LISTA MOVIMENTI
                                case 3: {
                                    //Faccio inserire la data dell'operazione
                                    printf("\nInserisci il mese di interesse:");
                                    scanf("%d",&meseinteresse);

                                    for (int j = 0; j < MAX_MOVIM; j++){

                                        if(movi[i].dati_utente.ID_UTENTE == movi[j].dati_utente.ID_UTENTE){
                                            if(movi[i].data.mese==meseinteresse){

                                                printf("%d", movi[i].operazione);

                                            }
                                            else if(strcmp(movi[i].dati_utente.Nome,movi[j].dati_utente.Nome)){
                                                if(movi[i].data.mese==meseinteresse)
                                                {
                                                    printf("%d", movi[i].operazione);
                                                }

                                            } else if (strcmp(movi[i].dati_utente.Cognome,movi[j].dati_utente.Cognome))
                                            {
                                                if(movi[i].data.mese==meseinteresse)
                                                {
                                                    printf("\nQuesti sono i movimenti correntistari che hai fatto:\nNumero di movimenti=%d\n\n", movi[i].operazione);
                                                }
                                            }
                                        }
                                        movi[i].data.giorno = day;
                                        movi[i].data.mese = month;
                                        movi[i].data.anno = year;


                                    }break;
                                }break;
                            }
                        }
                        //IL COGNOME NON E' STATO TROVATO
                        if (trovato!=1)
                        {
                            printf("\n\nIl Cognome non e' stato torovato");
                        }
                        trovato=0;

                    }
                }

                /*Ho scelto di inserire l'ID_utente*/
                else if(sec_scelta==3){
                    printf("\nInserisci l'ID Utente:");
                    scanf("%d",&cod_ut_inserito);
                    //verifico se il correntista esisre
                    for (i = 0; i < MAX_MOVIM; i++){
                        if (movi[i].dati_utente.ID_UTENTE==cod_ut_inserito) {
                            trovato=1;
                            printf("\n***L ID UTENTE E' CORRETTO***\n");
                            printf("\n\n");
                            printf("\n\n");
                            printf("****************************************\n");
                            printf("*   Menu Operazioni:                   *\n");
                            printf("*   1) Prelievo                        *\n");
                            printf("*   2) Versamento                      *\n");
                            printf("*   3) Lista Movimenti                 *\n");
                            printf("*   9) Uscire                          *\n");
                            printf("****************************************\n");
                            printf("\n Scelta:");
                            scanf("%d", &scelta_op);
                            switch (scelta_op) {
                                //CASO DI USCITA
                                case 9:{

                                    exit(0);
                                }
                                    //PRELIEVO
                                case 1: {
                                    //Effettuo il prelievo
                                    printf("\nInserire la quantita' da prelevare:");
                                    scanf("%f", &quantita_prel);

                                    if (quantita_prel < movi[i].saldo) {

                                        //Inserisco la data dell'operazione
                                        printf("\nInserisci data nel formato giorno/mese/anno (Es: 10/11/2021):");
                                        scanf("%d/%d/%d", &day, &month, &year);
                                        movi[i].data.giorno = day;
                                        movi[i].data.mese = month;
                                        movi[i].data.anno = year;

                                        movi[i_movi]=movi[i];

                                        movi[i_movi].saldo =
                                                movi[i_movi].saldo - quantita_prel; //sottraggo l'importo inserito al saldo

                                        printf("\nIl prelievo e' andato a buon fine\n\n");
                                        printf("\nIl tuo saldo e':%f\n",movi[i_movi].saldo);
                                        movi[i_movi].operazione=2;//Aggiungo il tipo di operazione
                                        i_movi++;
                                    } else{
                                        printf("\nIl saldo e' insufficiente\n");
                                    }
                                }break;
                                    //DEPOSITO
                                case 2: {
                                    //Faccio inserire la data dell'operazione
                                    printf("Inserisci data nel formato giorno/mese/anno (Es: 10/11/2021) :");
                                    scanf("%d/%d/%d", &day, &month, &year);
                                    movi[i].data.giorno = day;
                                    movi[i].data.mese = month;
                                    movi[i].data.anno = year;
                                    //movi[i] è il mio correntista
                                    movi[i_movi]=movi[i];

                                    //Effettuo l'accredito
                                    printf("\nInserire la quantita' da accreditare:");
                                    scanf("%f", &quantita_dep);

                                    movi[i_movi].saldo = movi[i_movi].saldo + quantita_dep;

                                    //Aggiungo un'operazione poiche è stata effettuata
                                    movi[i_movi].operazione=1;//Aggiungo il tipo di operazione
                                    printf("\n***L'accredito e' avvenuto correttamente***\n\n");
                                    printf("\nIl tuo saldo e':%f\n",movi[i_movi].saldo);
                                    i_movi++;
                                }break;
                                    //LISTA MOVIMENTI
                                case 3: {

                                    //Faccio inserire la data dell'operazione
                                    printf("Inserisci il mese di interesse:");
                                    scanf("%d",&meseinteresse);
                                    //movi[i] è il mio correntista
                                    for (int j = 0; j < MAX_MOVIM; j++)
                                    {
                                        if(movi[i].dati_utente.ID_UTENTE == movi[j].dati_utente.ID_UTENTE)
                                        {
                                            if(movi[i].data.mese==meseinteresse)
                                            {
                                                printf("\nQuesti sono i movimenti correntistari che hai fatto:\nNumero di movimenti=%d\n\n", movi[i].operazione);
                                            }

                                        }
                                    }
                                    movi[i].data.giorno = day;
                                    movi[i].data.mese = month;
                                    movi[i].data.anno = year;
                                }break;
                            }
                            break;
                        }
                    }
                    if (trovato!=1){//IL NOME NON E' STATO TROVATO
                        printf("\n\nIl nome non e' stato torovato");
                    }
                    trovato=0;

                }
            }
        }
    }
}



// Created by Carmine on 03/01/2021.

#include "header.h"
int main()
{
    int contatore;
    int conta_volte=3;       /*Le vote in cui chiedo di inserire una nuova matrice*/
    int trovate_tot=0;
    int dim_utente=0;
    int a[MAX][MAX];


    srand(time(NULL));
    while(conta_volte >0)
    {   conta_volte--;
        //Faccio inserire le dimensioni del quadrato all'utente
        printf("\n Inserire la dimensione che deve avere il quadrato, "
               "oppure inserire 0 per chiudere: ");
        scanf("%d",&dim_utente);
        //Uscire dal programma se la dimensione è 0
        if(dim_utente==0){
            exit(0);
        }
        riempi_arr(a,MAX);  //matrice piena di 0 per leggerla tutta
        for (contatore = 0;contatore <1000;contatore++)
        {
            int esecuz_op=0;
            riempi_arr(a,dim_utente);    //riempimento della matrice
            int i, j;
            int num;

            //Generazione e stampa del quadrato
            for (i = 0; i < dim_utente; i++) {
                for (j = 0; j < dim_utente; j++) {
                    while (in_arr(a, num = 1 + rand() % (dim_utente * dim_utente),
                                  dim_utente));
                    {}                               //per non far ripetere i numeri

                    a[i][j] = num;
                }
            }
            int co_mg = costante_magica(dim_utente);               //assegnazione della costante magica

            printf("\n Quadrato numero:%d",contatore);
                esecuz_op=operazioni(a, co_mg,dim_utente);

            if(esecuz_op == 0) {
                printf ("\n ******Trovato****** \n");
                trovate_tot++;//Incremento la variabile dei quadrati trovati
                //Mostro la percentuale attuale di trovare un quadrato
                printf("\n La percentuale parziale di trovare un quadrato magico e': %f",
                                                                (trovate_tot*100/(float)contatore));

                for (i = 0; i < dim_utente; i++) {
                    printf("\n");                           //per far si che si visualizzi la forma di un quadrato
                    for (j = 0; j < dim_utente; j++) {
                        printf("|%d|", a[i][j]);            //scrivo la matrice trovata
                    }
                }
                printf("\n\n Premi invio per continuare a cercare");
                getchar();                                       //Serve a bloccare il programma per leggere
            }
        }
        //Mostro il numero di quadrati trovati e la percentuale totale di trovare un quadrato
        printf("\n\n I quadrati che sono stati trovati sono :%d \n ",trovate_tot);
        printf("\n La percentuale totale di trovare un quadrato magico e': %f \n",(trovate_tot*100/(float)contatore));
    }
        return 0;
}

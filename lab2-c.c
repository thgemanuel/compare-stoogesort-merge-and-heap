#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
// LAB 2 PAA - THIAGO EMANUEL SILVA ANTUNES LOPES
// STOOGE SORT - 3 PATETAS

void stoogesort(int *vetor, int primeiro, int ultimo)
{
    if(primeiro >= ultimo)
        return;

    //verifica se primeiro do vetor eh maior, se sim faz a troca
    if(vetor[primeiro] > vetor[ultimo])
    {
        int auxiliar;
        auxiliar = vetor[primeiro];
        vetor[primeiro] = vetor[ultimo];
        vetor[ultimo] = auxiliar;
    }
    //verifica se o vetor nao tem tamanho 1
    if(ultimo - primeiro + 1 > 2)
    {
        //calcular tamanho de cada terco do vetor
        int terco = (ultimo - primeiro + 1) / 3;
        //chamar recursivamente para a primeira e segunda parte
        stoogesort(vetor, primeiro, ultimo - terco);
        //chamar recursivamente para a segunda e terceira parte
        stoogesort(vetor, primeiro + terco, ultimo);
        //chamar recursivamente novamente para a primeira e segunda parte
        stoogesort(vetor, primeiro, ultimo - terco);
    }
}

// FUNCAO TEMPO //
long double getNow()
{
   struct timeval now;
   long double valor = 1000000;

   gettimeofday(&now,NULL);

   return ((long double)(now.tv_sec*valor)+(long double)(now.tv_usec));
}

void temp(int *vetor)
{
    long double t=0, ti, tf;
    int i=10;
    while(t<60)
    {
        vetor=(int *) malloc(i * sizeof (int));
        for(int j=0;j<i;j++)
        {
            vetor[j]=rand()%100;
        }
        //for(int k=0;k<i; k++)
            //printf("%d ", vetor[k]);

        ti = getNow();
        
        stoogesort(vetor,0,i-1);

        tf = getNow();
        t=(tf-ti)/1000000;
	    printf("\n %d elementos = %Lf segundos\n", i, t);
        i=i*2;
	free(vetor);
    }
    //for(int k=0;k<i; k++)
        //printf("\n%d", vetor[k]);

}

int main()
{
    srand(time(NULL));
    int* vetor;
    temp(vetor);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 10000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int i, j, vetor[tam], vetor2[tam], vetor3[tam];

void preencher(){
	printf("\n Gerando um vetor com %d inteiros aleatorios\n",tam);
	for(i = 0; i<tam;i++)
	{
		vetor[i] = rand()%100;
		printf("%d\t", vetor[i]);
	}
}
		
void copiarVetor(){
	for(i=0;i<tam;i++)
	{
		vetor2[i]=vetor[i];
		vetor3[i]=vetor[i];
	}
}

void busca_bin(){
	int achou = 0, inicio = 0, fim = tam-1, meio, busca;
	printf("\nEntre com o inteiro a ser pesquisado: ");
	scanf("%d",&busca);
	while (inicio<=fim)
	{
		meio = (inicio+fim)/2;
		if (vetor[meio]==busca)
		achou = 1;
		if(busca<vetor[meio])
		fim = meio-1;
		else 
		inicio = meio+1;
	}
	if (achou==1)
	printf("\nAchou o valor %d \n", busca);
	else
	printf("\n Nao achou o valor \n");
}
	
void bubble(){
	int aux;
	for (i=0;i<tam-1;i++)
	{
		for (j=i+1; j<tam;j++)
		{
			if (vetor [i]>vetor [j])
			{
				aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
			}
		}
	}
}

void select(){
	int min, aux;
	for (i=0;i<tam-1;i++)
	{
		min = i;
		for(j=i+1;j<tam;j++)
		{
			if (vetor2[j]< vetor2[min])
			{
				min = j;
			}
		}
		aux=vetor[i];
		vetor2[i]=vetor2[min];
		vetor2[min]=aux;
	}
}
	
void insert(){
	int chave;
	for(i=1;i<tam;i++)
	{
		chave=vetor3[i];
		j=i-1;
		while ((j>=0)&&(vetor[j]>chave))
		{
			vetor3[j+1]=vetor3[j];
			j=j-1;
		}
		vetor3[j+1]=chave;
	}	
}

void opcao(int i){
	int inicio, fim, tempo;
	char str[11] = "";
	inicio = GetTickCount();
	switch (i)
	{
		case 1:
			bubble();
			strcpy(str, "Bubble Sort");
			break;
		case 2:
			select();
			strcpy(str, "Select Sort");
			break;
		case 3:
			insert();
			strcpy(str, "Insert Sort");
		    break;
	}
	fim = GetTickCount();
	tempo = fim - inicio;
	printf("\nTempo de ordenacao por %s: %d milisegundos\n",str, tempo);
}

int main(int argc, char *argv[]) {
	preencher();
	system("cls");
	copiarVetor();
	opcao(1);
	opcao(2);
	opcao(3);
	busca_bin();	
	system("pause");	
}

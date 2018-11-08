#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define tam 10000
int i, j;
typedef struct
{
	int vetor1[tam];
	int vetor2[tam];
	int vetor3[tam];
	int vetor4[tam];
} Vetores;

Vetores preencher(Vetores v)
{
	printf("\n Gerando um vetor com %d inteiros aleatorios\n", tam);
	for (i = 0; i < tam; i++)
	{
		v.vetor1[i] = rand() % tam;
		v.vetor2[i] = rand() % tam;
		v.vetor3[i] = rand() % tam;
		v.vetor4[i] = rand() % tam;
	}
	return v;
}
void mostrarTela(int *vetor, int numeroVetor)
{
	printf("VETOR %d \n", numeroVetor);
	printf("\n");
	for (i = 0; i < tam; i++)
	{
		printf("%d \t", vetor[i]);
	}
	printf("\n");
}

void busca_bin(int *vetor)
{
	int achou = 0, inicio = 0, fim = tam - 1, meio, busca;
	printf("\nEntre com o inteiro a ser pesquisado: ");
	scanf("%d", &busca);
	while (inicio <= fim)
	{
		meio = (inicio + fim) / 2;
		if (vetor[meio] == busca)
			achou = 1;
		if (busca < vetor[meio])
			fim = meio - 1;
		else
			inicio = meio + 1;
	}
	if (achou == 1)
		printf("\nAchou o valor %d \n", busca);
	else
		printf("\n Nao achou o valor \n");
}

void bubbleSort(int *vetor)
{
	int aux;
	for (i = 0; i < tam - 1; i++)
	{
		for (j = i + 1; j < tam; j++)
		{
			if (vetor[i] > vetor[j])
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
}

void selectionSort(int *vetor)
{
	int min, aux;
	for (i = 0; i < tam - 1; i++)
	{
		min = i;
		for (j = i + 1; j < tam; j++)
		{
			if (vetor[j] < vetor[min])
			{
				min = j;
			}
		}
		aux = vetor[i];
		vetor[i] = vetor[min];
		vetor[min] = aux;
	}
}

void insertSort(int *vetor)
{
	int chave;
	for (i = 1; i < tam; i++)
	{
		chave = vetor[i];
		j = i - 1;
		while ((j >= 0) && (vetor[j] > chave))
		{
			vetor[j + 1] = vetor[j];
			j = j - 1;
		}
		vetor[j + 1] = chave;
	}
}
void quicksort(int *vetor, int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end - 1;
	pivo = vetor[(began + end) / 2];
	while (i <= j)
	{
		while (vetor[i] < pivo && i < end)
		{
			i++;
		}
		while (vetor[j] > pivo && j > began)
		{
			j--;
		}
		if (i <= j)
		{
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}
	if (j > began)
		quicksort(vetor, began, j + 1);
	if (i < end)
		quicksort(vetor, i, end);
}

void opcao(Vetores v)
{
	int tempo, opcao;
	while (opcao != 0)
	{
		clock_t inicio, fim;
		printf("Escolha qual opcao de sort voce quer fazer?\n");
		printf("0) SAIR \n");
		printf("1) BUBBLESORT \n");
		printf("2) SELECTIONSORT \n");
		printf("3) INSERTIONSORT \n");
		printf("4) QUICKSORT \n");
		scanf("%d", &opcao);
		char str[20] = "";
		inicio = clock();
		switch (opcao)
		{
		case 1:
			bubbleSort(v.vetor1);
			mostrarTela(v.vetor1, 1);
			strcpy(str, "Bubble Sort");
			v = preencher(v);
			break;
		case 2:
			selectionSort(v.vetor2);
			mostrarTela(v.vetor2, 2);
			strcpy(str, "Select Sort");
			v = preencher(v);
			break;
		case 3:
			insertSort(v.vetor3);
			mostrarTela(v.vetor3, 3);
			strcpy(str, "Insert Sort");
			v = preencher(v);
			break;
		case 4:
			quicksort(v.vetor4, 0, tam);
			mostrarTela(v.vetor4, 4);
			strcpy(str, "Insert Sort");
			v = preencher(v);
			break;
		}
		fim = clock();
		tempo = fim - inicio;
		printf("\nTempo de ordenacao por %s: %d milisegundos\n", str, tempo);
	}
}

int main()
{
	Vetores v;
	v = preencher(v);
	opcao(v);
	system("pause");
	return 0;
}

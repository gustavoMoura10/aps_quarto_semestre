#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#define tam 20000
int i, j;
typedef struct
{
	int vetor1[tam];
	int vetor2[tam];
	int vetor3[tam];
	int vetor4[tam];
	
	int bubble;	
	int select;
	int insert;
	int quick;
} Vetores;

Vetores preencher(Vetores v)
{
	for (i = 0; i < tam; i++)
	{
		v.vetor1[i] = rand() % tam;
		v.vetor2[i] = v.vetor1[i];
		v.vetor3[i] = v.vetor1[i];
		v.vetor4[i] = v.vetor1[i];
	}
	return v;
}
void mostrarTela(int *vetor, int numeroVetor)
{
	printf("\n");
	for (i = 0; i < tam; i++)
	{
		printf("%d \t", vetor[i]);
	}
	printf("\n");
	printf("VETOR %d \n", numeroVetor);
	system("cls");
}

void buscaBinaria(int *vetor)
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
	system("cls");
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

void opcaoSort(Vetores v)
{
	int tempo, opcao=-1;
	bool opcao1, opcao2, opcao3, opcao4;
	while (opcao != 0)
	{
		clock_t inicio, fim;
		interface(opcao1, opcao2, opcao3, opcao4);
		scanf("%d", &opcao);
		char str[20] = "";

		switch (opcao)
		{
		case 1:
			if(opcao1) {opcao = 500; goto LINE96532;}
			inicio = clock();
			bubbleSort(v.vetor1);
			fim = clock();
			mostrarTela(v.vetor1, 1);
			strcpy(str, "Bubble Sort");
			v.bubble = fim - inicio;
			buscaBinaria(v.vetor1);
			v = preencher(v);
			printf("\nTempo de ordenacao por %s: %d milisegundos\n", str, v.bubble);
			opcao1=true;
			break;
		case 2:
			if(opcao2) {opcao = 500; goto LINE96532;}
			inicio = clock();
			selectionSort(v.vetor2);
			fim = clock();
			mostrarTela(v.vetor2, 2);
			strcpy(str, "Select Sort");
			v.select = fim - inicio;
			buscaBinaria(v.vetor2);
			printf("\nTempo de ordenacao por %s: %d milisegundos\n", str, v.select);
			opcao2=true;
			break;
		case 3:
			if(opcao3) {opcao = 500; goto LINE96532;}
			inicio = clock();
			insertSort(v.vetor3);
			fim = clock();
			mostrarTela(v.vetor3, 3);
			strcpy(str, "Insert Sort");;
			v.insert = fim - inicio;
			buscaBinaria(v.vetor3);
			printf("\nTempo de ordenacao por %s: %d milisegundos\n", str, v.insert);
			opcao3=true;
			break;
		case 4:
			if(opcao4) {opcao = 500; goto LINE96532;}
			inicio = clock();
			quicksort(v.vetor4, 0, tam);
			fim = clock();
			mostrarTela(v.vetor4, 4);
			strcpy(str, "Quick Sort");
			v.quick = fim - inicio;
			buscaBinaria(v.vetor4);
			printf("\nTempo de ordenacao por %s: %d milisegundos\n", str, v.quick);
			opcao4=true;
			break;
		case 5:
			system("cls");
			if(!opcao1&&!opcao2&&!opcao3&&!opcao4)
			{

			printf("\nNenhuma opcao ainda foi executada!\n");
			}
			if(opcao1)
			printf("Tempo de ordenacao por Bubble Sort: %d milisegundos\n\n", v.bubble);
			if(opcao2)
			printf("Tempo de ordenacao por Select Sort: %d milisegundos\n\n", v.select);
			if(opcao3)
			printf("Tempo de ordenacao por Insert Sort: %d milisegundos\n\n", v.insert);
			if(opcao4)
			printf("Tempo de ordenacao por Quick Sort:  %d milisegundos\n\n", v.quick);
			break;
		case 0:
			break;
LINE96532:
		case 500:
			system("cls");
			printf("Essa opcao ja foi executada! \n");
			break;
		default:
			printf("Opcao Invalida! \n");
			break;	
		}
	}
}
void interface(bool a, bool b, bool c, bool d)
{
	char string[20] = " (JA ESCOLHIDO)";
		        printf("\n ---------------------------------------\n");
		        printf("| Qual opcao de sort voce deseja fazer? |");
	            printf("\n ---------------------------------------\n");
	    if(!a || !b || !c || !d)
	    {
		if (!a) printf("| 1) Bubble Sort                        |\n");
        else    printf("| 1) Bubble Sort%s         |\n", string);
        		
		if (!b) printf("| 2) Selection Sort                     |\n");
		else    printf("| 2) Selection Sort%s      |\n", string);
		
		if (!c) printf("| 3) Insertion Sort                     |\n");
		else    printf("| 3) Insertion Sort%s      |\n", string);
			
		if (!d) printf("| 4) Quick Sort                         |\n");
		else    printf("| 4) Quick Sort%s          |\n", string);
		}
	            printf("| 5) Obter dados das opcoes escolhidas  |\n");
	            printf("| 0) Sair                               |\n");
	    		printf(" ---------------------------------------\n");
}
int main()
{
	printf("\n          Bem Vindo ao programa!\n");
	Vetores v;
	v = preencher(v);
	opcaoSort(v);
	system("pause");
	return 0;
}

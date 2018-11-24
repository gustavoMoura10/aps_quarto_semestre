#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
//Definir tamanho dos vetores
#define tam 20000
//apontadores para os laços de repetição
int i, j;
bool a, b, c, d; //Verificadores para saber se a opção já foi escolhida
typedef struct
{
	//Vetores para guardar valores aleatórios e logo então, serem sortedos
	int vetor1[tam];
	int vetor2[tam];
	int vetor3[tam]; 
	int vetor4[tam]; 
	
	//Guarda informação do tempo de duração do método
	int bubble;	
	int select;
	int insert;
	int quick;
} Vetores;


/*Preenche vetores aleatóriamente e faz um espelho dos vetores restantes
  para obter maior precisão ao comparar entre os métodos*/
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

//Mostra no console todos os valores dentro do vetor desejado
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

//Faz uma busca binária para achar um determinado valor dentro do vetor desejado
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

//Método de sorteamento
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

//Método de sorteamento
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

//Método de sorteamento
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

//Método de sorteamento
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


/*Interface do programa. Serve tanto para saber se a opção já foi escolhida,
  como também para obter dados de todas as opções escolhidas.*/
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


//Seleciona uma determinada opção para fazer a consulta de sort escolhida a partir do Switch
void opcaoSort(Vetores v)
{
	int opcao=-1; //Opção do SwitchCase. Está como -1 para não fechar o loop do laço de repetição
	
	while (opcao != 0)
	{
		clock_t inicio, fim; //Pega o tick da máquina para verificar performance
        interface (a, b, c, d); //Interface do programa recebe os verificadores de opção
        
		scanf("%d", &opcao);
		char str[20] = ""; //Variável para realizar uma reescrita. Utilizado apenas para teste.

		switch (opcao)
		{
		case 1:
			
			/*
			Se opção já foi escolhida> opcão do Case = 600 e ir para linha X (Código espaguete)
			o código espaguete foi realizado aqui para economizar algumas linhas de código do programa.
			*/
        	if(a) {opcao = 500; goto LINE96532;} 
			inicio = clock(); //pega o tick do programa e salva na variável inicio
			bubbleSort(v.vetor1); //Executa o método BubbleSort na variável desejada
			fim = clock(); //pega o tick do programa e salva na variável fim
			mostrarTela(v.vetor1, 1); //Mostra na tela os valores de um vetor X
			strcpy(str, "Bubble Sort"); //Reescrita da string str.
			v.bubble = fim - inicio; // subtrai fim - início para ter uma estimativa do tempo de execução do Sort
			buscaBinaria(v.vetor1); //Realiza uma busca binária a partir do valor escolhido
			printf("\nTempo de ordenacao por %s: %d milisegundos\n", str, v.bubble); //Teste de concatenação de string
			a=true; //Verificador para saber se essa opção já foi escolhida
			break;
			//case 2, 3 e 4 segue o mesmo padrão do case 1
	
		case 2:
			if(b) {opcao = 500; goto LINE96532;} 
			inicio = clock();
			selectionSort(v.vetor2);
			fim = clock();
			mostrarTela(v.vetor2, 2);
			strcpy(str, "Select Sort");
			v.select = fim - inicio;
			buscaBinaria(v.vetor2);
			printf("\nTempo de ordenacao por %s: %d milisegundos\n", str, v.select);
			b=true;
			break;
	
		case 3:
			if(c) {opcao = 500; goto LINE96532;}
			inicio = clock();
			insertSort(v.vetor3);
			fim = clock();
			mostrarTela(v.vetor3, 3);
			strcpy(str, "Insert Sort");
			v.insert = fim - inicio;
			buscaBinaria(v.vetor3);
			printf("\nTempo de ordenacao por %s: %d milisegundos\n", str, v.insert);
			c=true;
			break;
	
		case 4:
			if(d) {opcao = 500; goto LINE96532;}
			inicio = clock();
			quicksort(v.vetor4, 0, tam);
			fim = clock();
			mostrarTela(v.vetor4, 4);
			strcpy(str, "Quick Sort");
			v.quick = fim - inicio;
			buscaBinaria(v.vetor4);
			printf("\nTempo de ordenacao por %s: %d milisegundos\n", str, v.quick);
			d=true;
			break;
	
		case 5:
			system("cls"); //Apagar o que está escrito no console
			if(!a&&!b&&!c&&!d)//Se alguma opção de sort já foi executada, mostrar a performance de determinado Sort.
			{

			printf("\nNenhuma opcao ainda foi executada!\n");
			}
			if(a)
			printf("Tempo de ordenacao por Bubble Sort: %d milisegundos\n\n", v.bubble);
			if(b)
			printf("Tempo de ordenacao por Select Sort: %d milisegundos\n\n", v.select);
			if(c)
			printf("Tempo de ordenacao por Insert Sort: %d milisegundos\n\n", v.insert);
			if(d)
			printf("Tempo de ordenacao por Quick Sort:  %d milisegundos\n\n", v.quick);
			break;
		
		case 0:
			return;
			
LINE96532: //Código espaguete para não repetir código, ou criar um método apenas para verificar se a opção já foi escolhida
           // (ver linha 210 para mais informações)
		case 500:
			system("cls"); 
			printf("Essa opcao ja foi executada! \n");
			break;
		
		default:
			system("cls");
			printf("Opcao Invalida! \n");
			break;	
		}
	}
}

int main()
{
	printf("\n          Bem Vindo ao programa!\n");
	Vetores v; //Inicializa o struct Vetores (Linha 10)
	v = preencher(v); //Preenche e guarda os valores no ponteiro.
	opcaoSort(v); //Método para fazer teste de performance dos sorts
	system("pause"); //Pausa o console para não fechar na cara do fulano
	return 0;
}

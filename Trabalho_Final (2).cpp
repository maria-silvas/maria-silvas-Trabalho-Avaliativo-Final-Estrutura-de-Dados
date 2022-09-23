/*
	Trabalho Final - Estrutura de Dados 
	M�todos de Ordena��o escolhidos: Bubble Sort, Selection Sort e Insertion Sort
	
	Alunos: 
	Kemily Teixeira da Rosa
	Maria Eduarda Silva
	Vitor Gustavo da Silva
	
	Professor: Marcelo Petri 
	Turma: ADS 2022/2
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <bits/stdc++.h>
#define TAM 50
using namespace std;

int op, arr[TAM];
void printVetor (int arr[], int size); 
int randomVetor (int arr[], int size), bubbleSort (int arr[], int size), selectionSort (int arr[], int size), insertionSort (int arr[], int size);
clock_t start, end; 

int main (){
	start = 0;
	end = 0;
	setlocale(LC_ALL, "Portuguese"); 
	
	do {
		cout << "\n\n\n M�todos de Ordena��o\n";
		cout << "\n M�TODO BUBBLE SORT [1]";
		cout << "\n M�TODO SELECTION SORT [2]";
		cout << "\n M�TODO INSERTION SORT [3]";
		cout << "\n SAIR [0]\n ";
		cin >> op;
		
		switch (op) {
			case 1: {
				cout << "\n M�TODO BUBBLE SORT";
				arr[TAM] = randomVetor (arr, TAM);
				
				cout << "\n VETOR DESORDENADO: ";
				printVetor(arr, TAM);
				
				cout << "\n VETOR ORDENADO COM BUBBLE SORT: ";
				start = clock();
				arr[TAM] = bubbleSort (arr, TAM);
				end = clock();	
				printVetor(arr, TAM);
				
				double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
				cout << "\n\n Tempo de Execu��o para o M�todo Bubble Sort : " << fixed << time_taken << setprecision(5) << " segundos";
				
				cout << "\n\n ";
				system("pause");			
				break;
			}
			
			case 2: {
				cout << "\n M�TODO SELECTION SORT";
				arr[TAM] = randomVetor (arr, TAM);
				
				cout << "\n VETOR DESORDENADO: ";
				printVetor(arr, TAM);
				
				cout << "\n VETOR ORDENADO COM SELECTION SORT: ";
				start = clock();
				arr[TAM] = selectionSort (arr, TAM);
				end = clock();	
				printVetor(arr, TAM);
				
				double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
				cout << "\n\n Tempo de Execu��o para o M�todo Selection Sort : " << fixed << time_taken << setprecision(5) << " segundos";
				
				cout << "\n\n ";
				system("pause");			
				break;
			}
			
			case 3: {
				cout << "\n M�TODO INSERTION SORT";
				arr[TAM] = randomVetor (arr, TAM);
				
				cout << "\n VETOR DESORDENADO: ";
				printVetor(arr, TAM);
				
				cout << "\n VETOR ORDENADO COM INSERTION SORT: ";
				start = clock();
				arr[TAM] = insertionSort (arr, TAM);
				end = clock();	
				printVetor(arr, TAM);
				
				double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
				cout << "\n\n Tempo de Execu��o para o M�todo Insertion Sort : " << fixed << time_taken << setprecision(5) << " segundos";
				
				cout << "\n\n ";
				system("pause");
				break;
			}
			
			case 0: {
				cout << "\n OBRIGADO!";
				break;
			}
			
			default: {
				cout << "\n OP��O INV�LIDA!";
				break;
			}
		}
		
	} while (op != 0);
}

/*GERAR UM VETOR ALEAT�RIO*/
int randomVetor (int arr[], int size){
  for (int i = 0; i < size; i++){
      arr[i] = (rand () % 1000) + 1;
    }
}
/*IMPRIMIR VETOR*/
void printVetor (int arr[], int size){
  for (int i = 0; i < size; i++){
      cout << arr[i] << " | ";
    }
}

/*BUBBLE SORT
Principal Vantagem:
	Sua implementa��o � f�cil e conhecida, nele os elementos s�o trocados de lugar sem utilizar armazenamento tempor�rio, o que faz o requerimento de espa�o ser m�nimo. 
Principal Desvantagem 
	N�o apresenta bons resultados quando a lista cont�m muitos itens pois executa uma quantidade especifica de passos para cada elemento.
*/

int bubbleSort (int arr[], int size){
  	int i, j;
  	for (i = 0; i < size - 1; i++){
      	for (j = 0; j < size - i - 1; j++){
	    	if (arr[j] > arr[j + 1]){
	        	swap (arr[j], arr[j + 1]);
	        }
    	}
    }
}

/*SELECTION SORT
Principal Vantagem: 
	Funciona bem em uma lista pequena. Al�m disso, por ser um algoritmo de ordena��o de local, n�o precisa de armazenamento tempor�rio al�m do necess�rio para guardar a lista original.
Princpal Desvantagem:
	Baixa efici�ncia em grandes listas pois executa uma quantidade especifica de passos para cada elemento.
*/
int selectionSort (int arr[], int size){
	int i,j,min_in;
    for(i = 0; i < size; i++){
        min_in = i;
        for(j = i + 1;j < size;j++){
        	if (arr[j] < arr[min_in]){
        		min_in = j;	
			}   
		}    
        swap(arr[i],arr[min_in]);
    }
}

/*INSERTION SORT
Principal Vantagem: 
	Dentre os algoritmos de ordena��o, este apresenta a menor quantidade de movimentos entre os elementos, apresentando ganho de performance. 
Principal Desvantagem:
	Pouco eficiente quando se trata de grandes listas pois executa uma quantidade especifica de passos para cada elemento. 
*/
int insertionSort (int arr[], int size){
	for (int j = 0; j < size; j++) {  
        int key = arr[j];  //chave recebe o valor do array na posi��o j 
        int i = j-1; //i recebe o valor de j - 1, assim o while come�a a verificar a posi��o anterior a chave, pulando a primeira posi��o do array
        while ( (i > -1) && ( arr [i] > key ) ) {  //Enquanto o valor de i for maior que -1 e o valor da posi��o i for maior que a chave, o while continua
            arr [i+1] = arr [i];  
            i--;  //i recebe o valor de i - 1, assim o while continua verificando a posi��o anterior a chave
        }
		arr[i+1] = key; //Quando o while termina, a chave recebe o valor da posi��o i + 1
    }
}

/*
	Trabalho Final - Estrutura de Dados 
	Métodos de Ordenação escolhidos: Bubble Sort, Selection Sort e Insertion Sort
	
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
		cout << "\n\n\n Métodos de Ordenação\n";
		cout << "\n MÉTODO BUBBLE SORT [1]";
		cout << "\n MÉTODO SELECTION SORT [2]";
		cout << "\n MÉTODO INSERTION SORT [3]";
		cout << "\n SAIR [0]\n ";
		cin >> op;
		
		switch (op) {
			case 1: {
				cout << "\n MÉTODO BUBBLE SORT";
				arr[TAM] = randomVetor (arr, TAM);
				
				cout << "\n VETOR DESORDENADO: ";
				printVetor(arr, TAM);
				
				cout << "\n VETOR ORDENADO COM BUBBLE SORT: ";
				start = clock();
				arr[TAM] = bubbleSort (arr, TAM);
				end = clock();	
				printVetor(arr, TAM);
				
				double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
				cout << "\n\n Tempo de Execução para o Método Bubble Sort : " << fixed << time_taken << setprecision(5) << " segundos";
				
				cout << "\n\n ";
				system("pause");			
				break;
			}
			
			case 2: {
				cout << "\n MÉTODO SELECTION SORT";
				arr[TAM] = randomVetor (arr, TAM);
				
				cout << "\n VETOR DESORDENADO: ";
				printVetor(arr, TAM);
				
				cout << "\n VETOR ORDENADO COM SELECTION SORT: ";
				start = clock();
				arr[TAM] = selectionSort (arr, TAM);
				end = clock();	
				printVetor(arr, TAM);
				
				double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
				cout << "\n\n Tempo de Execução para o Método Selection Sort : " << fixed << time_taken << setprecision(5) << " segundos";
				
				cout << "\n\n ";
				system("pause");			
				break;
			}
			
			case 3: {
				cout << "\n MÉTODO INSERTION SORT";
				arr[TAM] = randomVetor (arr, TAM);
				
				cout << "\n VETOR DESORDENADO: ";
				printVetor(arr, TAM);
				
				cout << "\n VETOR ORDENADO COM INSERTION SORT: ";
				start = clock();
				arr[TAM] = insertionSort (arr, TAM);
				end = clock();	
				printVetor(arr, TAM);
				
				double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
				cout << "\n\n Tempo de Execução para o Método Insertion Sort : " << fixed << time_taken << setprecision(5) << " segundos";
				
				cout << "\n\n ";
				system("pause");
				break;
			}
			
			case 0: {
				cout << "\n OBRIGADO!";
				break;
			}
			
			default: {
				cout << "\n OPÇÃO INVÁLIDA!";
				break;
			}
		}
		
	} while (op != 0);
}

/*GERAR UM VETOR ALEATÓRIO*/
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
	Sua implementação é fácil e conhecida, nele os elementos são trocados de lugar sem utilizar armazenamento temporário, o que faz o requerimento de espaço ser mínimo. 
Principal Desvantagem 
	Não apresenta bons resultados quando a lista contém muitos itens pois executa uma quantidade especifica de passos para cada elemento.
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
	Funciona bem em uma lista pequena. Além disso, por ser um algoritmo de ordenação de local, não precisa de armazenamento temporário além do necessário para guardar a lista original.
Princpal Desvantagem:
	Baixa eficiência em grandes listas pois executa uma quantidade especifica de passos para cada elemento.
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
	Dentre os algoritmos de ordenação, este apresenta a menor quantidade de movimentos entre os elementos, apresentando ganho de performance. 
Principal Desvantagem:
	Pouco eficiente quando se trata de grandes listas pois executa uma quantidade especifica de passos para cada elemento. 
*/
int insertionSort (int arr[], int size){
	for (int j = 0; j < size; j++) {  
        int key = arr[j];  //chave recebe o valor do array na posição j 
        int i = j-1; //i recebe o valor de j - 1, assim o while começa a verificar a posição anterior a chave, pulando a primeira posição do array
        while ( (i > -1) && ( arr [i] > key ) ) {  //Enquanto o valor de i for maior que -1 e o valor da posição i for maior que a chave, o while continua
            arr [i+1] = arr [i];  
            i--;  //i recebe o valor de i - 1, assim o while continua verificando a posição anterior a chave
        }
		arr[i+1] = key; //Quando o while termina, a chave recebe o valor da posição i + 1
    }
}

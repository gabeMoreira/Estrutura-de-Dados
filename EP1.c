#include <stdio.h>
#include <stdlib.h>
/*
Gabriel de Souza Moreira dos Santos
18101086
ADS, FATEC - SÃO PAULO
*/

//Função do Bubblesort.
void bubblesort(int v[], int n){
	int i, j, k, aux = 0;
	for(i = n-1; i > 0 ;i--){
		
		for(j=0;j<i; j++){
			
			if(v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				printf("\nTroca do %d com o %d", v[j+1], v[j]);
				}
		printf(" - ");
		for(k=0;k<n;k++){
			printf(" %d", v[k]);}
		}
	}		
}

//Função do Selection Sort.
void selectionsort(int v[], int n) {
	int aux, aux2, i, j, menor;
	for (i = 0; i < n; i++) {
		menor = i;
		for(int aux2=0;aux2<n;aux2++){
		printf("%d", v[aux2]);
		}
		printf("\n");
		for (j = i + 1; j < n; j++)
			if (v[j] < v[menor])
				menor = j;
					
		aux = v[i];
		v[i] = v[menor];
		v[menor] = aux;
	
	}
}

//Função do Insertion Sort.
void insertionsort(int v[], int n) {
	int i, j, k, aux;
	for (i = 1; i < n; i++) {
		aux = v[i];
		j = i - 1;
		while (j > -1 && v[j] > aux) {
			v[j+1] = v[j];
			j--;
		}
		printf("\n\n");
	
		v[j+1] = aux;
		for(k=0;k<n;k++){
			printf("%d ", v[k]);
		}	
	}
	printf("\n\n");
}

//Função intercala do Merge Sort.
void intercala(int v[], int ini, int meio, int fim) {
	int i = ini, j = meio+1, k = 0, *aux;
	aux = (int *)malloc(sizeof(int) * (fim - ini + 1));
	if (aux == NULL) abort();
	while (i <= meio && j <= fim){
		if (v[i] <= v[j])
			 aux[k++] = v[i++];
		else
			 aux[k++] = v[j++];		
	}
	while (i <= meio){
		aux[k++] = v[i++];
	}
	while (j <= fim){
		aux[k++] = v[j++];
	}
		 
	for (i = ini, j = 0; i <= fim; i++, j++){
		v[i] = aux[j];
	
	}
	free(aux);
}

//Função principal do Merge Sort.
void mergesort(int v[], int ini, int fim) {
	for(int k=0;k<fim+1;k++){
		printf("%d ", v[k]);
	}
	printf("\n");
	if (ini < fim) {
		int meio = (ini + fim) / 2;
		mergesort(v, ini, meio);
		mergesort(v, meio+1, fim);
		intercala(v, ini, meio, fim);
		for(int k=0;k<fim+1;k++){
			printf("%d ", v[k]);
	}
	printf("\n");	
	}
}

//Função partição  do Quick Sort.
int particao(int v[], int ini, int fim) {
	int pivo = v[ini], esq = ini+1, dir = fim, aux;
	while (esq <= dir) {
		while (esq <= dir && v[esq] <= pivo) esq++;
		while (v[dir] > pivo) dir--;
		if (esq < dir) {
			aux = v[esq]; v[esq] = v[dir]; v[dir] = aux;
			esq++; dir--;
		}
	}
	v[ini] = v[dir]; v[dir] = pivo;
	return dir;
}

//Função principal do Quick Sort.
void quicksort(int v[], int ini, int fim) {
	for(int k=0;k<fim+1;k++){
		printf("%d ", v[k]);
	}
	printf("\n");
	if (ini < fim) {
		int pivo = particao(v, ini, fim);
		quicksort(v, ini, pivo-1);
		quicksort(v, pivo+1, fim);
		for(int k=0;k<fim+1;k++){
		printf("%d ", v[k]);
		}
		printf("\n");	
	}
}

int main(){
	
	int v[] = {5,4,3,2,1}, n =5;
	int cont = 6;
	printf("Vetor inicial: ");
	for(int i=0;i<5;i++){
		printf("%d ", v[i]);
	}
	printf("\n\n");
	

	printf("--Bubblesort--");
	bubblesort(v,5);
	printf("\n\n");
	
	for(int i =0;i<n;i++){
		v[i] = cont-1;
		cont--;
	}
	printf("--Selection Sort--\n");
	selectionsort(v,5);
	printf("\n\n");
	cont = 6;
	for(int i =0;i<n;i++){
		v[i] = cont-1;
		cont--;
	}
	printf("--Insertion Sort--\n");
	insertionsort(v,n);
	printf("\n\n");
	cont = 6;
	for(int i =0;i<n;i++){
		v[i] = cont-1;
		cont--;
	}	
	printf("--Merge Sort--\n");
	mergesort(v,0,n);
	printf("\n\n");
	cont = 6;
	for(int i =0;i<n;i++){
		v[i] = cont-1;
		cont--;
	}
	printf("--Quick Sort--");
	quicksort(v,0,n);
	printf("\n\n");
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct pilha {
	char vet[10];
	int topo;
} TPilha;

void create(TPilha *p) {
	p->topo = -1;
}

void destroy(TPilha *p) {
	p->topo = -1;
}

int isfull(TPilha *p) {
	if (p->topo == 50)
		return 1;
	else
		return 0;
}

int isempty(TPilha *p) {
	if (p->topo == -1)
		return 1;
	else
		return 0;
}
void push(TPilha *p, char x){
	if (isfull(p)) {
		printf("overflow\n");
		abort();
	}
	p->topo++; 
	p->vet[p->topo] = x;
}

char pop(TPilha *p){
	char aux;
	if (isempty(p)) {
		printf("underflow\n");
		abort();
	}
	aux = p->vet[p->topo];
	p->topo--;
	return aux;
}

char top(TPilha *p) {
	if (isempty(p)) {
		printf("underflow\n");
		abort();
	}
	return p->vet[p->topo];
}
int verPalindromo(char aux[], char palavra[], int tam2){
	if(strcmp(aux, palavra) == 0){
		return 1;
	}
	else
		return 0;
}	


int main(){
	char s [10]= {'a','b','c','d','e','f'};

	//------EXERCÍCIO A------
	int i, tam;
	tam = strlen(s);
	TPilha p;
	printf("----Exercicio A----\n");
	//Criação da Pilha.
	create(&p);
	//Verificação se a pilha está vázia.
	printf("(1)Pilha vazia | (0) N vazia: %d\n\n", isempty(&p));
	//Inserir elementos na pilha.
	for(i=0;i<tam;i++){
		printf("Inserindo elemento: %c\n", s[i]);
		push(&p, s[i]);
	}		
	//Verificar topo da pilha.
	printf("\nTopo da pilha: %c\n\n", top(&p));
	
	printf("(1)Pilha vazia | (0)N vazia: %d\n\n", isempty(&p));
	
	//Tirando elementos da pilha.
	for(i=0;i<tam;i++){
		printf("Retirando elemento: %c\n", pop(&p));
	}
		
	//Checando para ver se foi retirado os elementos da pilha e se a pilha está cheia.
	printf("\n");	
	printf("(1)Pilha vazia | (0)N vazia: %d\n", isempty(&p));
	printf("(1)Pilha cheia | (0)N cheia: %d\n\n", isfull(&p));
	
	//------EXERCÍCIO B------
	printf("----Exercicio B----\n");
	char aux[20];
	int tam2;
	char palavra[20] = "ovo";
	
	tam2 = strlen(palavra);
	for(i=0;i<tam2;i++){
		printf("Inserindo elemento: %c\n", palavra[i]);
		push(&p, palavra[i]);
	}
	printf("\n");
	for(i=0;i<tam2;i++){
		aux[i] = pop(&p);
	}
	printf("Palavra: ");
	puts(palavra);
	printf("\nPalavra invertida: ");
	puts(aux);
	//Chamando a função que verifica a palavra.
	printf("\n(1)Palindromo (2)Nao e palindromo\n--> %d\n\n", verPalindromo(aux,palavra,tam2));
	
	//------EXERCÍCIO C------
	printf("----Exercicio C----\n");
	char frase[50] = "ovo e teste";
	TPilha p2;
	for(i=0;i<frase[i]!='\0';i++){
            push(&p2, frase[i]);
	}
	for(i=0;i<frase[i]!='\0';i++){
            printf("%c",pop(&p2));
	}
		
	return 0;
}

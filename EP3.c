#include <stdio.h>
#include <stdlib.h>

// Gabriel Moreira
typedef struct fila{
	char vet[7];
	int front, rear;
}TFila;

int next(int n){
	if(n<6)
		return n+1;
	else
		return 0;
}

void createf(TFila *f){
	f->rear = 0;
	f->front = 0;
}

void destroy(TFila *f){
	f->front = f->rear;
}

int isfull(TFila *f){
	if(next(f->rear) == f->front)
		return 1;
	else
		return 0;
}

int isempty(TFila *f){
	if(f->rear == f->front)
		return 1;
	else
		return 0;
}

void store(TFila *f, char x){
	if(isfull(f)){
		printf("overflow\n");
		abort();
	}
	f->vet[f->rear] = x;
	f->rear = next(f->rear);
}

char retrieve(TFila *f){
	char aux;
	if(isempty (f)){
		printf("underflow\n");
		abort();
	}
	aux = f->vet[f->front];
	f->front = next(f->front);
	return aux;
}


void Cad_Paciente(TFila *f1, TFila *f2, TFila *f3){

	typedef struct cad_hosp{
		char nome;
		char *motivo;
		int prioridade;
	}Cadastro;

	Cadastro cad1;
	cad1.nome = 'A';
	cad1.motivo = "Gripe";
	cad1.prioridade = 1;
	
	if(cad1.prioridade == 1) store(f1, cad1.nome);
	
	else if(cad1.prioridade == 2) store(f2, cad1.nome);

	else store(f3, cad1.nome);
	
	Cadastro cad3;
	cad3.nome = 'C';
	cad3.motivo = "Febre";
	cad3.prioridade = 2;

	if(cad3.prioridade == 1) store(f1, cad3.nome);
	
	else if(cad3.prioridade == 2) store(f2, cad3.nome);

	else store(f3, cad3.nome);

	Cadastro cad4;
	cad4.nome = 'D';
	cad4.motivo = "Sinusite";
	cad4.prioridade = 2;

	if(cad4.prioridade == 1) store(f1, cad4.nome);
	
	else if(cad4.prioridade == 2) store(f2, cad4.nome);

	else store(f3, cad4.nome);

	Cadastro cad5;
	cad5.nome = 'E';
	cad5.motivo = "Rinite";
	cad5.prioridade = 2;

	if(cad5.prioridade == 1) store(f1, cad5.nome);
	
	else if(cad5.prioridade == 2) store(f2, cad5.nome);

	else store(f3, cad5.nome);

	Cadastro cad6;
	cad6.nome = 'F';
	cad6.motivo = "Queimadura";
	cad6.prioridade = 3;

	if(cad6.prioridade == 1) store(f1, cad6.nome);
	
	else if(cad6.prioridade == 2) store(f2, cad6.nome);

	else store(f3, cad6.nome);

}

void Mostrar_Fila_Prioridades(TFila *f1, TFila *f2, TFila *f3){
	printf("\nPrioridade 1\n");
	while(!isempty(f1))
		printf("%c\n", retrieve(f1));

	printf("\n");

	printf("Prioridade 2\n");
	while(!isempty(f2))
		printf("%c\n", retrieve(f2));

	printf("\n");
	printf("Prioridade 3\n");
	while(!isempty(f3))
		printf("%c\n", retrieve(f3));
	printf("\n");
}

int main() {

	TFila *f1 = malloc(sizeof(TFila));
	TFila *f2 = malloc(sizeof(TFila));
	TFila *f3 = malloc(sizeof(TFila));
	
	createf(f1);
	createf(f2);
	createf(f3);

	Cad_Paciente(f1,f2,f3);
	Mostrar_Fila_Prioridades(f1,f2,f3);

}

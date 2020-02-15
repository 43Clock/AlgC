#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex.h"

//1
int hash(char matricula[6]){
	int sum = 1,i;
	for(i = 0;i<6;i++) sum *=matricula[i];
	return (sum%SIZE);
}

int insert(Tabela t,char matricula[6]){
	int p = hash(matricula);
	struct no1 *aux = t[p];
	while(aux->matricula[0] != '\0' && strcmp(matricula,aux->matricula) != 0) aux = aux->next;
	if(strcmp(matricula,aux->matricula) == 0) return 1;
	else strcpy(aux->matricula,matricula);
	return 0;
}

//2
Arvore rr(Arvore arv){
	Arvore aux = arv->esq;
	aux -> dir = arv;
	arv -> esq = aux->dir;
	arv = aux;
	return arv;
}

//4

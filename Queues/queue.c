#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue (QUEUE *q){
	q->tamanho = 0;
	q->inicio = 0;
}

int enqueue (QUEUE *q,int x) {
	if(q->tamanho == MAX) return 1;
	q->valores[q->tamanho+q->inicio] = x;
	q->tamanho++;
	return 0;
}

int dequeue (QUEUE *q,int *x) {
	if (q->tamanho == q-> inicio) return  1;
	*x = q->valores[q->inicio];
	q->inicio++;
    q->tamanho--;
	return 0;
}

void initQueue_d (DQUEUE *q) {
	q-> cap = 1;
	q-> inicio = q-> tamanho = 0;
	q->valores = malloc(sizeof(int));
}

void grow(DQUEUE *q,int tam) {
	int i, j; 
    int *new = malloc(tam * sizeof(int));
    for(i=q->inicio, j=0; j<q->cap; i=(i+1)%q->cap, j++) new[j] = q->valores[i];
	free(q->valores);
    q->valores = new;
    q->cap = tam;
	q->inicio = 0;
}

int enqueue_d (DQUEUE *q,int x) {
	if (q->tamanho == q->cap) {
		grow(q,(q->tamanho)*2);
		printf("new capacity = %d\n",q->cap);
	}
	q->valores[(q->inicio + q->tamanho)%q->cap] = x; //%q->cap -> circularidade
	q->tamanho++;
	return 0;
}

int dequeue_d(DQUEUE *q,int *x){
	if(q->tamanho == 0) return 1;
	*x = q->valores[q->inicio];
	q->inicio = (q->inicio+1)%q->cap;
	q->tamanho--;
	return 0;
}

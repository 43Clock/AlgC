#include <stdio.h>
#include <stdlib.h>


#define MAX 10
typedef struct queue {
    int inicio, tamanho;
    int valores[MAX];    // Implem. estatica
} QUEUE;


void initQueue (QUEUE *q);
int enqueue (QUEUE *q, int x); 
int dequeue (QUEUE *q, int *x);



typedef struct dqueue {
    int inicio, tamanho;
    int cap; 
    int *valores;     // Implem. dinamina
} DQUEUE;


void initQueue_d (DQUEUE *q);
int enqueue_d (DQUEUE *q, int x); 
int dequeue_d (DQUEUE *q, int *x);


#include "graphs.h"



int readGraphM(GraphM g) {
    int i, j, n;

    printf("Número de vértices do grafo? (<=%d)\n", MAX);
    scanf("%d", &n);
    if (n > MAX) return 0; 

    printf("\nIntroduza matriz de adjacência do grafo:\n");
   
    for(i=0; i<n; i++)
       for(j=0; j<n; j++)
            scanf("%d", &g[i][j]);

    return n;
}


void printGraphM(GraphM g, int n) {
	int i, j;
	for(i=0; i<n; i++) {
        for(j=0; j<n; j++) 
            printf("%d ", g[i][j]);
        printf("\n");
    }    
}



void printGraphL(GraphL g, int n) {
    int i;
    struct edge *aux;
    for (i = 0;i<n;i++){
    	printf("%d",i);
    	for(aux = g[i];aux != NULL;aux = aux->prox)
    		printf(" --> (%d,%d)",aux -> dest,aux -> weight);
    }
}



void graphLtoM(GraphM gm, GraphL gl, int n) {
    int i,j;
    struct edge *aux;
    for(i = 0;i<n;i++){
    	aux = gl[i];
    	for(j = 0;j<n;j++){
    		if(aux && aux->dest == j){
    			gm[i][j] = aux -> weight;
    			aux = aux->prox;
    		}
    		else gm[i][j] = NE;
    	}
    }
}



void graphMtoL(GraphL gl, GraphM gm, int n) {
	int i,j;
	struct edge *aux,*novo;
	for (i = 0;i<n;i++){
		aux = NULL;
		for(j = n-1;j>=0;j--){ // começa no n-1 para meter os elementos ordenados
			if (gm[i][j] != NE){
				novo = malloc(sizeof(struct edge));
				novo -> dest = j;
				novo -> weight = gm[i][j];
				novo -> prox = aux;
				aux = novo;
			}
		}
		gl[i] = aux;
	}
}

int inDegree (GraphL g, int j, int n) {
    int i,sum = 0;
    struct edge *aux;
    for(i = 0; i<n ;i++)
        for(aux = g[i];aux && aux->dest < j;aux = aux->prox);
        if (aux->dest == j) sum++;
    return sum;
}



int outDegree (GraphL g, int j) {
    struct edge *aux;
    int sum = 0;
    aux = g[j];
    while (aux){
    	sum++;
    	aux = aux->prox;
    }
    return sum;
}


int capacidadeL (GraphL g, int v, int n) {
    int i,in = 0,out = 0;
    struct edge *aux;
    for(i = 0; i<n ;i++)
        for(aux = g[i];aux;aux = aux->prox)
        	if (aux->dest == v) in += aux -> weight;
    for(aux = g[v];aux;aux = aux->prox) out += aux->weight;
    return in-out;     
}

int maxCap (GraphL g, int n) {
    int i,temp = 0,r = 0;
    int cap[n];
    struct edge *aux;
    for (i = 0;i<n;i++) cap[i] = 0;
    for(i = 0;i<n;i++)
    	for(aux = g[i];aux;aux = aux->prox){
    		cap[i] -= aux->weight;
    		cap[aux->dest] += aux->weight;
    	}
    for(i = 0;i<n;i++) 
    	if(cap[i]>cap[temp]){
    		temp = cap[i];
    		r = i;
    	}
    return r;
}



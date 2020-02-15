#include "graphs.h"

/*int dijkstraSP(GraphL g,int o,int pesos[],int pais[]){
	int cores[MAX]; // 0->nao visitado, 1->orla, 2 -> visitado
	int i,tam,r = 0,x = o;
	struct edge *aux;
	for (i = 0; i < MAX;i++) cores[i] = 0;
	//acrescentar a orla
	cores[o] = 1;pesos[o] = 0;pais[o] = -1;
	tam = 1;
	while(tam > 0){
		r++;
		tam--;
		cores[x] = 2;
		for(aux = g[x];aux;aux = aux->prox){
			if(cores[aux -> dest] == 0){
				pesos[aux->dest] = pesos[x] + aux->weight;
				pais[aux->dest] = x;
				cores[aux->dest] = 1;
			}
			else if(cores[aux -> dest] == 1 && pesos[x] + aux-> weight<pesos[aux->dest]){
				pesos[aux->dest] = pesos[x] +aux->weight;
			}
		}
		//x = min(pesos);
	}
}*/


void inDegrees (GraphL g, int n, int inD[]) {
   int i;struct edge *aux;
   for(i = 0;i<n;i++) inD[i] = 0;
   for(i = 0;i<n;i++)
       for(aux = g[i];aux;aux = aux->prox)
       	  inD[aux->dest]++;   
}


int topSort_Kahn (GraphL g, int n, int tsort[]) {
	int x,i,ini,fim;
	int inD[n],q[MAX];
	struct edge *aux;
	inDegrees(g,n,inD);
	ini = fim = 0;
	for (i = 0;i<n;i++)
		if(inD[i] == 0) q[fim++] = i; //cria queue com todos os vertices de grau de entrada 0
	i = 0;
	while(ini!=fim){
		x = q[ini++];
		tsort[i++] = x;
		for(aux = g[x];aux;aux = aux->prox){
			inD[aux->dest]--;
			if(inD[aux -> dest] == 0) q[fim++] = aux->dest;
		}

	}
	return !(i == n); //Se i = v, nao existe ciclos no grafo
}
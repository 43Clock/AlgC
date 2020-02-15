#include "graphs.h"

void swap(int v[],int xp, int yp) 
{ 
    int temp = v[xp]; 
    v[xp] = v[yp]; 
    v[yp] = temp; 
} 

int DFS (GraphL g, int i, int color[], int *success,int tsort[]) {
	int t;
	struct edge *aux;
	color[i] = 1;
	t = 0;
	for(aux = g[i];aux;aux = aux->prox)
		if(color[aux->dest] == 0)
			t+=DFS(g,aux->dest,color,success,tsort+t);
		else if (color[aux->dest] == 1)
				*success = 0;
	tsort[t++] = i;
	color[0] = 2;
	return t; 
}


int topSort_Tarjan (GraphL g, int n, int tsort[]) {
	int color[n];
	int i,j,t,r;
	for(i = 0;i<n;i++) color [i] = 0;
	r = 1; t = 0;
	for(i = 0;i<n;i++)
		if(color[i] == 0)
			t+=DFS(g,i,color,&r,tsort+t);
	for(i = 0,j=t;i<j;i++,j--)
		swap(tsort,i,j);
	return r;
}
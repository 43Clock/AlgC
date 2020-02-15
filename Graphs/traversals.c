#include "graphs.h"

int color[MAX];
int parents[MAX];


void df_visit(GraphL g, int s){
    struct edge *aux;
    color[s] = GRAY; // GRAY == 1;
    printf("%d GRAY\n",s);
    for(aux = g[s];aux;aux = aux->prox)
    	if (color[aux->dest] == WHITE){
    		parents[aux->dest] = s;
    		df_visit(g,aux -> dest);
        }
    color[s] = BLACK; // BLACK == 2;	
    printf("%d BLACK\n",s);
}


void dfs (GraphL g, int n){
    int i;
    for(i = 0;i<MAX;i++) {
    	color[i] = WHITE;
    	parents[i] = -1;
    }
    for(i = 0;i<n;i++){
    	if (color[i] == WHITE){ // WHITE == 0, ou seja se ainda n tiver sido visitado
    		df_visit(g,i);
    	}
    }
}


DQUEUE q;

void bf_visit(GraphL g, int s){
    int u;
    struct edge *aux;
    color[s] = GRAY;
    printf("%d GRAY\n",s);
    parents[s] = -1; //Ou seja é uma raiz
    enqueue_d(&q,s);
    while (q.tamanho != 0){
    	dequeue_d(&q,&u);
    	for(aux = g[u];aux;aux = aux ->prox)
    		if(color[aux->dest] == WHITE){
    			color[aux->dest] == GRAY;
    			printf("%d GRAY\n",aux->dest);
    			parents[aux->dest] = u;
    			enqueue_d(&q,aux->dest);
    		}
    	color[u] = BLACK;
    	printf("%d BLACK\n",u);
    }
}


void bfs (GraphL g, int n){
    int i;
    initQueue_d(&q);
    for(i = 0;i<MAX;i++) {
    	color[i] = 0;
    	parents[i] = -1;
    }
    for(i = 0;i<n;i++)
    	if (color[i] == WHITE){
    		bf_visit(g,i);
    	}
}

void distsAux(GraphL g,int s, int dis,int dist[],int vis[]){
    struct edge *aux;
    for(aux = g[s];aux;aux = aux->prox){
        if(vis[aux->dest] == 0)
        dist[aux->dest] = dis;
    }
    for(aux = g[s];aux;aux  = aux ->prox)
        if (vis[aux->dest] == 0) {
            vis[aux->dest] = 1;
            distsAux(g,aux -> dest,dis+1,dist,vis);
    }
}


void dists (GraphL g, int s, int dist[]) {
    int vis[MAX];
    int i,dis = 1;
    struct edge *aux;
    for (i = 0;i<MAX;i++) {
        dist[i] = -1;
        vis[i] = 0;
    }
    dist[s] = 0;
    for(aux = g[s];aux;aux = aux->prox){
        dist[aux->dest] = dis;
        vis[aux->dest] = 1;
    }
    for(aux = g[s];aux;aux  = aux ->prox) distsAux(g,aux -> dest,dis+1,dist,vis);
}


void shortestPath (GraphL g, int x, int y) {
    int vis[MAX],q[MAX],parent[MAX];
    int i,ini,fim;
    struct edge *aux;
    for(i = 0;i<MAX;i++){
        vis[i] = 0;
        parent[i] = -1;
    }
    vis[x] = 1;
    q[0] = x;
    ini = 0;
    fim = 1;
    while(ini!=fim){
        x = q[ini++];
        if (x == y) break;
        for(aux = g[x];aux!= NULL;aux = aux->prox)
            if(vis[aux->dest] == 0){
                vis[aux->dest] = 1;
                parent[aux->dest] = x;
                q[fim++] = aux -> dest;
            }
    }

    if(parent[y] == -1) printf("%d não é alcansável a partir de %d\n", y, x);
    else {
    	i = y;
    	printf("Caminho inverso de %d para %d:\n", x, y);
    	while (i>=0){
    		printf("%d\t", i);
    		i = parent[i];
    	}
    }
    printf("\n");
}


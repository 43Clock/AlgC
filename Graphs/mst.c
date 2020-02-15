#include "graphs.h"



void printTree(GraphM g, int n, int parent[]) {
    int i, sum=0;
    printf("\nMST:\n");
    for (i = 0; i < n; i++)
        if (parent[i] >= 0) {
            printf("(%d, %d), peso %d\n", i, parent[i], g[i][parent[i]]);
            sum += g[i][parent[i]];
        }
    printf("Peso Total: %d\n", sum);
}


void mst(GraphL g, int n, int parent[]) {
    int status[MAX];
    int fringeLink[MAX];
    int fringeWgt[MAX];
    struct edge *ptr;
    int x,y;
    int fringeList;
    int edgeCount;
    int stuck;
    int sum;

      /* inicializacao */

    x = 0; 
    status[0] = INTREE;
    parent[0] = -1;
  
    stuck = 0;
  
    edgeCount = 0;

    fringeList = NIL;

    for (y = 1 ; y < n ; y++) status[y] = UNSEEN;

    while(edgeCount<n-1 && !stuck) {

        for(ptr = g[x];ptr;ptr = ptr -> prox){ //Cria/atualiza a orla
            y = ptr->dest;
            if(status[y] == UNSEEN){ //adiciona y á orla 
                status[y] = FRINGE;
                fringeLink[y] = fringeList;
                fringeList = y;
                parent[y] = x;
                fringeWgt[y] = ptr->weight;
            }
            else if(status[y] == FRINGE && ptr->weight<fringeWgt[y]){
                parent[y] = x;
                fringeWgt[y] = ptr->weight;
            }
        }
        if(fringeList == NIL) stuck = 1;
        else {
            int prev = 0;
            x = fringeList;
            for (y=fringeList; fringeLink[y] != NIL; y=fringeLink[y]) 
                if (fringeWgt[fringeLink[y]] < fringeWgt[x]) {
                    x = fringeLink[y];
                    prev = y;
                }
            if (x==fringeList) fringeList = fringeLink[x];
            else fringeLink[prev] = fringeLink[x];
            fringeLink[x] = NIL;
            status[x] = INTREE;
            edgeCount++;
        }
    }
}
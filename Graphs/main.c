#include <stdio.h>

/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>

#include "graphs.h"

int main()
{

    // matriz simétrica - grafo não-orientado representado com redundância
    GraphM gm1 = {
    {NE,  2, NE, NE, NE,  7,  3, NE, NE},
    { 2, NE,  4, NE, NE, NE,  6, NE, NE},
    {NE,  4, NE,  2, NE, NE, NE,  2, NE},
    {NE, NE,  2, NE,  1, NE, NE,  8, NE},
    {NE, NE, NE,  1, NE,  6, NE, NE,  2},
    { 7, NE, NE, NE,  6, NE, NE, NE,  5},
    { 3,  6, NE, NE, NE, NE, NE,  3,  1},
    {NE, NE,  2,  8, NE, NE,  3, NE,  4},
    {NE, NE, NE, NE,  2,  5,  1,  4, NE}
    }; 
    int n1 = 9; 

    GraphL gl1; 
    
    // grafo orientado 
    GraphM gm2 = {
    {NE, NE, NE, NE,  1},
    {NE, NE, NE,  1, NE},
    {NE,  1, NE, NE,  1},
    {NE, NE,  1, NE, NE},
    {NE, NE, NE,  1, NE},
    };
    int n2 = 5; 

    GraphL gl2;
    
    
    GraphM gm3 = {
    {0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0, 0},
    }; 
    
    GraphL gl3;

    GraphM gm4 = {
    {NE, NE, 1, NE, NE, NE, NE},
    {NE, NE, NE, NE, NE, NE, 1},
    {NE, NE, NE, 1, NE, NE, NE},
    {NE, 1, NE, NE, NE, NE, NE},
    {NE, NE, NE, 1, NE, NE, NE},
    {NE, NE, NE, NE, 1, NE,  1},
    {NE, NE, NE, NE, NE, NE,NE},
    };
    int n4 = 7;
    GraphL gl4;

    graphMtoL(gl4,gm4,n4);

    int n3 = 9;
    graphMtoL(gl3, gm3, n3); 
     
    int d[MAX];

    int i, cycle, tsort[MAX], parent[MAX];
    

     //    n = readGraphM(gm);


/*
    graphMtoL(gl1, gm1, n1);     
    
    printf("\nListas de adjacência:\n");
    printGraphL(gl1, n1);

    graphLtoM(gm1, gl1, n1);
    
    printf("\nMatriz de adjacência reconstruída:\n");
    printGraphM(gm1, n1);

*/
 
 
/*    
    printf("\nGraus do vértice 0: entrada %d, saída %d\n", 
        inDegree(gl1, 0, n1), outDegree(gl1, 0));

    printf("\nCapacidade do vértice 0: %d\n", capacidadeL(gl1, 0, n1));

    printf("\nVértice de capacidade máxima: %d\n", maxCap (gl1, n1));
*/




   /* printf("Depth-first traversal:\n");
    dfs(gl3, n3);

    printf("Breadth-first traversal:\n");
    bfs(gl3, n3);

    dists (gl3, 3, d);
    printf("\nDistances from node 3:\n");
    for (i=0; i<n3; i++) 
        printf("to %d: %d\n", i, d[i]);
    
    shortestPath(gl3, 3, 5);
    shortestPath(gl3, 3, 1);*/




    
    graphMtoL(gl2, gm2, n2); 



   cycle = topSort_Tarjan(gl4, n4, tsort);
    
    if (!cycle) {
        printf("Topological Sort:\n");
        for (i=0; i<n4; i++) printf ("%d ", tsort[i]);
        printf("\n");
    }
    else printf("The graph contains cycles\n");


  /*
    cycle = topSort_Kahn(gl4, n4, tsort);
    
    if (!cycle) {
        printf("Topological Sort:\n");
        for (i=0; i<n4; i++) printf ("%d ", tsort[i]);
        printf("\n");
    }
    else printf("The graph contains cycles\n");
 
*/
   

  /*  mst(gl, n, parent);
   
    printTree(gm, n, parent);
*/

    return EXIT_SUCCESS;
}

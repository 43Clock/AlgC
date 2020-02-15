 

#include <stdio.h>
#include <stdlib.h>

#define NE 0

#define MAX 100

typedef int WEIGHT;

struct edge {
  int dest;
  WEIGHT weight;
  struct edge *prox;
};

typedef struct edge *GraphL[MAX];

typedef WEIGHT GraphM[MAX][MAX];


int readGraphM(GraphM);
void printGraphM(GraphM, int);
void printGraphL(GraphL, int);
void graphLtoM(GraphM, GraphL, int);
void graphMtoL(GraphL, GraphM, int);

int inDegree (GraphL, int, int);
int outDegree (GraphL, int);
int capacidadeL (GraphL g, int v, int n);
int maxCap (GraphL g, int n);




#define WHITE 0
#define GRAY 1
#define BLACK 2

#define NIL -1

void df_visit(GraphL g, int s); 
void dfs(GraphL g, int n); 
void bf_visit(GraphL g, int s); 
void bfs(GraphL g, int n); 
void dists (GraphL g, int s, int dist[]);
void shortestPath (GraphL g, int s, int  d);


#define INTREE 0
#define FRINGE 1
#define UNSEEN 2


int topSort_Tarjan (GraphL, int, int []);
int topSort_Kahn (GraphL g, int n, int tsort[]);
void mst(GraphL, int, int[]);
void printTree(GraphM g, int n, int parent[]);

/*
void df_visit_sol(GraphL g, int s); 
void dfs_sol(GraphL g, int n); 
void bf_visit_sol(GraphL g, int s); 
void bfs_sol(GraphL g, int n); 


int topSort_Tarjan_sol (GraphL, int, int []);
int topSort_Kahn_sol (GraphL, int, int []);
void mst_sol(GraphL, int, int[]);*/







//QUEUE

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
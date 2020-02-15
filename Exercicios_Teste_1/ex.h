#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//1
#define SIZE 1009
typedef struct no1 {
	char matricula[6];
	struct no1 *next;
} No1;
typedef No1 *Tabela[SIZE];

int hash(char matricula[6]);

//2
typedef struct no2 {
	int info;
	int bal;
	struct no2 *esq, *dir;
} No2;
typedef No2 *Arvore;

//4
#define TAM 10
typedef struct s {
	char *sin;
	struct s *next;
} Sin;

typedef struct p {
	char *pal;
	Sin *sins;
	struct p *next;
} Pal;

typedef Pal *Dic[TAM];
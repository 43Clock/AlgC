#include <stdio.h>
#include <stdlib.h>


typedef int TreeEntry;

typedef enum balancefactor { LH , EH , RH } BalanceFactor;

struct treenode {
    BalanceFactor bf;
    TreeEntry entry;
    struct treenode *left;
    struct treenode *right;
};

typedef struct treenode *Tree;

Tree insertTree(Tree t, TreeEntry e, int *cresceu);

int nonAVL_treeHeight(Tree t);
int treeHeight(Tree t);

int isAVL (Tree t);
int isAVL_opt (Tree t);
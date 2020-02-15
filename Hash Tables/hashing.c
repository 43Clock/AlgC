#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "hashing.h"


int hashV(char key[], int size) {
	int i, sum=0;
    for(i = 0; key[i] != '\0';i++) sum += key[i];
    return (sum % size);
}


void initHT(HT *h, int size) {
	int i;
	h->size = size;
	h->used = 0;
	h->tbl = malloc(size*sizeof(struct pair));
	for (i = 0;i<size;i++) strcpy(h->tbl[i].key,EMPTY);
   	
}

int freeHT(HT *h, int k) {
    if (strcmp(h->tbl[k].key, EMPTY)==0) return 1;
    if (strcmp(h->tbl[k].key, DELETED)==0) return 1;
    return 0;
}



int writeHT (HT *h, char key[], int value) {
	int hash = hashV(key,h->size);
	int ocupado = h->used/h->size;
	if (ocupado >0.8) grow(h,2*h->size);
	while (!freeHT(h,hash)) {
		hash = (hash+1)%h->size; //procura um lugar livre
		printf("* ");
	}
	strcpy(h->tbl[hash].key,key);
	h->tbl[hash].value = value;
	h->used++;
}

void grow(HT *h,int size) {
	struct pair *new;
	int i,hash;
	new = malloc(size*sizeof(struct pair));
	for (i = 0;i<size;i++) strcpy(new[i].key,EMPTY);
	for(i = 0;i<h->size;i++){
		if(!freeHT(h,i)){
			hash = hashV(h->tbl[i].key,size);
			while(strcmp(new[hash].key,EMPTY) != 0) hash = (hash+1)%size;
			strcpy(new[hash].key,h->tbl[i].key);
			new[hash].value = h->tbl[i].value; 
		}
	}
	free(h->tbl);
	h->tbl = new;
	h->size = size;
}



int readHT (HT *h, char key[], int* value) {
    int hash = hashV(key,h->size);
    int hashI = hashV(key,h->size);
    while (strcmp(h->tbl[hash].key,key) != 0) {
    	if (strcmp(h->tbl[hash].key,EMPTY) == 0) return -1;
    	hash = (hash+1)%h->size;printf("* ");
    	if (hash == hashI) return -1;
    }
    *value = h->tbl[hash].value;
    return hash;
}



int deleteHT (HT *h, char key[]) {
	int exist,v;
	exist = readHT(h,key,&v);
	if(exist != -1) {
		strcpy(h->tbl[exist].key,DELETED);
		h->used--;
	}
	return exist;
}



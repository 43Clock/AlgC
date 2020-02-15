#include <stdlib.h>

#include "minheap.h"


void swap (Elem h[], int a, int b) {
    int t = h[a];
    h[a] = h[b];
    h[b] = t;
}

void initHeap (Heap *h, int size) {
    h->values = calloc(size, sizeof(Elem));
    h->size = size;
    h->used = 0;
}


void bubbleUp (Elem h[], int i) {
	while(i!= 0 && h[i]< h[PARENT(i)]){
		swap(h,i,PARENT(i));
		i = PARENT(i);
	}
}



int  insertHeap (Heap *h, Elem x) {
    if (h -> used == h->size){
    	h->values = realloc(h->values,2*(h->size)*sizeof(Elem));
    	h->size *= 2;
    }
    h->values[h->used] = x;
    h->used++;
    //bubbleUp(h->values,h->used-1);
    return 1;
}



void bubbleDown (Elem a[], int N) {
    int i = 0, min ;
    
    while (LEFT(i) < N) {
        min = a[i] < a[LEFT(i)] ? i : LEFT(i);
        if (RIGHT(i) < N)
            min = a[min] < a[RIGHT(i)] ? min : RIGHT(i);
        if (min != i) {
            swap(a, i, min);
            i = min;
        }
        else break;
    }
    
}

int  extractMin (Heap *h, Elem *x) {
    if(h->used>0){
    	*x = h->values[0];
   	 	h->values[0] = h->values[h->used-1];
   	 	h->used--;
    	bubbleDown(h->values,h->used);
    	return 1;
    }
    return 0;
}

int minHeapAux(Heap h,int i) {
	if(LEFT(i) > h.used) return 1;
    if(RIGHT(i) > h.used) {
    	if (h.values[i] < h.values[LEFT(i)]) return 1;
    	else return 0;
    }
    if(h.values[i] > h.values[RIGHT(i)] || h.values[i] > h.values[LEFT(i)]) return 0;
    return minHeapAux(h,RIGHT(i)) && minHeapAux(h,LEFT(i));
}

int minHeapOK (Heap h) {
    return minHeapAux(h,0);
}
#include "queue.h"


int main() {
    QUEUE q;
    DQUEUE dq;
    int a, i, j, empty, full, error;

    // TEST STATIC QUEUE 
    
/*    
    initQueue(&q);

    i = 10;
    full = enqueue(&q, i);
    while (!full) {
        printf("enqueued %d\n", i);
        i += 10;
        full = enqueue(&q, i);
    }
    
    for (j=0; j<MAX/2; j++) {
        dequeue(&q, &a);
        printf("dequeued %d\n", a);
    }
    
    //  first half of array now empty
    
    full = enqueue(&q, i);
    while (!full) {
        printf("enqueued %d\n", i);
        i += 10;
        full = enqueue(&q, i);
    }
    
    empty = dequeue(&q, &a);
    while (!empty) {
        printf("dequeued %d\n", a);
        empty = dequeue(&q, &a);
    }

*/

    // TEST DYNAMIC QUEUE 

    initQueue_d(&dq);

    
    // insert 10 elements; array will grow to size 16
    // |10|20|30|40|50|60|70|80|90|100|__|__|__|__|__|__|
    
    error = 0;
    for (i=10; i<=100 && !error; i+=10) {
        error = enqueue_d(&dq, i);
        printf("enqueued %d\n", i);
    }
    
    // dequeue first 5 elements; there will be room for 11 elements
    // |__|__|__|__|__|60|70|80|90|100|__|__|__|__|__|__|
   
    empty = dequeue_d(&dq, &a);
    if (!empty) printf("dequeued %d\n", a);
    for (j=0; j<4 && !empty; j++) {
        empty = dequeue_d(&dq, &a);
        if (!empty) printf("dequeued %d\n", a);
    }

    // insert 20 more elements; first 11 will still fit, inserted with circularity
    // the remainining will cause reallocation with length 32 after insertion of 210
    // |170|180|190|200|210|60|70|80|90|100|110|120|130|140|150|160|
    // |60|70|80|90|100|110|120|130|140|150|160|170|180|190|200|210|220|230|240|250|260|270|280|290|300|__|__|__|__|__|__|__|
    
    for (; i<=300 && !error; i+=10) {
        error = enqueue_d(&dq, i);
        printf("enqueued %d\n", i);
    }
    
    // dequeue all elements
    
    empty = dequeue_d(&dq, &a);
    if (!empty) printf("dequeued %d\n", a);
    for (; !empty; i++) {
        empty = dequeue_d(&dq, &a);
        if (!empty) printf("dequeued %d\n", a);
    }

    
    return 0;
}
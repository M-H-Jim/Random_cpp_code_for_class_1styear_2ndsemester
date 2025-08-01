#include <stdio.h>

/*
 * 
 * (Traversing a Linear Array) Here LA is a linear array with lower bound LB and upper bound UB.
 * This algorithm traverses LA applying an operation 'PROCESS' to each element of LA.
 * 
 * 1. [Initialize counter] Set K := LB.
 * 2. Repeat Steps 3 and 4 while K <= UB.
 * 3.     [Visit element.] Apply PROCESS to LA[K].
 * 4.     [Increase counter] Set K := K + 1
 * 5. Exit.
 * 
 * 
 * */
 
int main() {
    
    int LA[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};    // Here upper bound is 9 because this is C.
    
    int LB = 0, UB = 9; // 0 based index in C
    
    int K = LB;
    while(K <= UB) {
        printf("%d ", LA[K]);    // We will just print the number
        K = K + 1;              // Increase counter
    }
    
    return 0;    // Exit
}


#include <stdio.h>

/*
 * (Bubble Sort) Here DATA is an array with N elements.
 * This algorithm sorts the elements in DATA.
 * 
 * 
 * 1. Repeat Steps 2 and 3 for K := 1 to N - 1
 * 2. Set PTR := 1 [Initializes pass pointer PTR]
 * 3. Repeat while PTR <= N - K: [Executes pass]
 *       (a) If DATA[PTR] > DATA[PTR + 1], then:
 *               Interchange DATA[PTR] and DATA[PTR + 1]
 *       (b) Set PTR := PTR + 1
 * 4. Exit.
 * 
 * */

void swap(int *a, int *b) {
    int tem = *a;
    *a = *b;
    *b = tem;
}


int main() {
    
    
    while(1) {    // This is done so that the user can sort again and again...
        
        printf("How many data do you want to enter? ");
        int N;
        scanf("%d", &N);
        
        int DATA[N];
        
        printf("Enter your data:\n");
        for(int i = 0; i < N; i++)
            scanf("%d", &DATA[i]);
        
        for(int K = 1; K <= N - 1; K++) {    // The number times we have to 'pass'
            int PTR = 0;                     // Initialize pass pointer
            while(PTR < N - K) {
                if(DATA[PTR] > DATA[PTR + 1])
                    swap(&DATA[PTR], &DATA[PTR + 1]);
                PTR = PTR + 1;
            }
        }
        
        printf("Your sorted array is :\n");
        for(int i = 0; i < N; i++)
            printf("%d ", DATA[i]);
        printf("\n");
        
    }
    
    return 0;    // Exit
}


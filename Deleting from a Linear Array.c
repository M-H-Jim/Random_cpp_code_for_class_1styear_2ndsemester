#include <stdio.h>

/*
 * (Deleting from a Linear Array) Here LA is a linear array with N elements and
 * K is a positive integer such that K <= N. This algorithm deletes the Kth element from LA.
 * 
 * 
 * 1. Set ITEM := LA[K]
 * 2. Repeat for J := K to N - 1
 *        [Move (J + 1)st element upward.] Set LA[J] := LA[J + 1]
 * 3. [Reset the number N of elements in LA] Set N := N - 1
 * 4. Exit.
 * 
 * */
 
int main() {
    
    printf("How many data do you want to enter? ");
    int N;
    scanf("%d", &N);
    int LA[N];
    
    printf("Enter your data: \n");
    for(int i = 0; i < N; i++)
        scanf("%d", &LA[i]);
    
    // Now we have our array which has N elements.
    
    while(1) {    // This is done so that the user can insert again and again until the memory is full
        
        printf("Enter deletion index:\n");
        int K;
        scanf("%d", &K);
        
        int ITEM = LA[K];
        
        for(int J = K; J < N - 1; J++)
            LA[J] = LA[J + 1];
        
        N--;
        
        printf("Deleted element: %d\n", ITEM);
        printf("Updated Array:\n");
        for(int i = 0; i < N; i++)
            printf("%d ", LA[i]);
        printf("\n");
        
        if(N == 0) {
            printf("Cannot delete more. Array is empty\n");
            break;
        }
        
    }
    
    return 0;    // Exit
}


#include <stdio.h>

/*
 * (Inserting into a Linear Array) Here LA is a linear array with N elements and K is a positive integer such that K <= N.
 * This algorithm inserts an element ITEM into the Kth position in LA.
 * 
 * 1. [Initialize counter] Set J := N
 * 2. Repeat Steps 3 and 4 while J >= K
 * 3.     [Move Jth element downward] Set LA[J + 1] := LA[J];
 * 4.     [Decrease counter] Set J := J - 1
 * 5. [Insert element] Set LA[K] := ITEM
 * 6. [Reset N] Set N := N + 1
 * 7. Exit.
 * 
 * */
 
int main() {
    
    printf("Enter the size of your array: ");
    int n;
    scanf("%d", &n);
    
    int LA[n];
    
    printf("How many data do you want to enter? ");
    int N;
    scanf("%d", &N);
    
    printf("Enter your data: \n");
    for(int i = 0; i < N; i++)
        scanf("%d", &LA[i]);
    
    // Now we have our array which has N elements.
    
    while(1) {    // This is done so that the user can insert again and again until the memory is full
        
        printf("In which index do you want to insert?\n");
        int K;
        scanf("%d", &K);
        
        printf("What value do you want to insert?\n");
        int ITEM;
        scanf("%d", &ITEM);
        
        int J = N;    // Initialize counter
        while(J >= K) {
            LA[J + 1] = LA[J];
            J = J - 1;
        }
        
        LA[K] = ITEM;    // Insert element
        N = N + 1;       // We have to increase N because there is one more element in the array
        
        
        printf("Updated Array:\n");
        for(int i = 0; i < N; i++)
            printf("%d ", LA[i]);
        printf("\n");
        
        if(N == n) {
            printf("Cannot insert more. Otherwise it will overflow");
            break;
        }
        
    }
    
    return 0;    // Exit
}

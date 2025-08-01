#include <stdio.h>

/*
 * (Linear Search) Here DATA is a linear array with N elements.
 * and ITEM is a given item of information. 
 * This algorithm finds the location LOC of ITEM in DATA, or sets LOC := 0 if the search is unsuccessful.
 * 
 * 
 * 1. [Insert ITEM at the end of DATA] Set DATA[N + 1] := ITEM
 * 2. [Initialize counter] Set LOC := 1
 * 3. [Search for ITEM]
 *    Repeat while DATA[LOC] != ITEM:
 *        Set LOC := LOC + 1;
 * 4. [Successful?] If LOC := N + 1, then Set LOC := 0
 * 5. Exit.
 * 
 * */


int main() {
    
    printf("How many data do you want to enter? ");
    int N;
    scanf("%d", &N);
    
    int DATA[N + 1];
    
    printf("Enter your data:\n");
    for(int i = 0; i < N; i++)
        scanf("%d", &DATA[i]);
    
    
    while(1) {
        
        printf("Enter the element you want to search: ");
        int ITEM;
        scanf("%d", &ITEM);
        
        DATA[N] = ITEM;
        
        int LOC = 0;
        while(DATA[LOC] != ITEM)
            LOC = LOC + 1;
        
        if(LOC == N)
            printf("Element %d not found in the array\n", ITEM);
        else
            printf("Element %d found at index %d\n", ITEM, LOC);
        
    }
    
    return 0;    // Exit
}

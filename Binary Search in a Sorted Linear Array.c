#include <stdio.h>

/*
 * 
 * (Binary Search) Here DATA is a sorted array with lower bound LB and upper bound UB,
 * and ITEM is a given item of information. The variables BEG, END and MID denote, repectively
 * the beginning, end and middle locations of a segment of elements of DATA. This algorithm finds 
 * the location LOC of ITEM in DATA or sets LOC = NULL
 * 
 * 1. [Initialize variables]
 *    Set BEG := LB, END := UB and MID := INT((BEG + END) / 2).
 * 2. Repeat Steps 3 and 4 while BEG <= END and DATA[MID] != ITEM
 * 3.     If ITEM < DATA[MID], then:
 *             Set END := MID - 1
 *        Else:
 *             Set BEG := MID + 1
 * 4. Set MID := INT((BEG + END) / 2);
 * 5. If DATA[MID] = ITEM, then:
 *        Set LOC := MID.
 *    Else:
 *        Set LOC := NULL
 * 6. Exit.
 * 
 * 
 * */

/*
 * Here is a function for doing binary search
 * 
 * int Bsearch(int a[], int size, int target) {
 *     int left = 0, right = size - 1;
 *     while(left <= right) {
 *         int mid = (left + right) / 2;
 *         if(a[mid] == target) return mid;
 *         a[mid] < target ? (left = mid + 1) : (right = mid - 1);
 *     }
 *     return -1;
 * }
 * 
 * 
 * */



int main() {
    
    printf("How many data do you want to enter? ");
    int N;
    scanf("%d", &N);
    
    int DATA[N];
    
    printf("Enter your data:\n");
    for(int i = 0; i < N; i++)
        scanf("%d", &DATA[i]);
    
    
    while(1) {
        
        printf("Enter the element you want to search: ");
        int ITEM;
        scanf("%d", &ITEM);
        
        int BEG = 0, END = N - 1, MID = (BEG + END) / 2, LOC;
        while(BEG <= END && DATA[MID] != ITEM) {
            
            if(ITEM < DATA[MID])
                END = MID - 1;
            else
                BEG = MID + 1;
            
            MID = (BEG + END) / 2;
            
        }
        
        if(DATA[MID] == ITEM)
            LOC = MID;
        else
            LOC = -1;
        
        if(LOC >= 0)
            printf("element %d is found at index %d\n", ITEM, LOC);
        else
            printf("element %d is not found\n", ITEM);
        
    }
    
    return 0;    // Exit
}

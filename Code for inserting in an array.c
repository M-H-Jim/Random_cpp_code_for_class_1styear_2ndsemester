#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <string.h>
//#include <limits.h>
//#include <stdbool.h>

int main(){
	
printf("Enter the size of your array:");
	int n;
	scanf("%d", &n);
	
	int Data[n];
	
	printf("How many data do you want to enter?");
	int N;
	scanf("%d", &N);
	
	printf("Enter your data:\n");
	for(int i = 0; i < N; i++)
		scanf("%d", &Data[i]);
	
	while(1) {
		
		printf("In which index do you want to insert?\n");
		int k;
		scanf("%d", &k);
		
		printf("What value do you want to insert?\n");
		int ITEM;
		scanf("%d", &ITEM);
		
		int j = N;
		while(j >= k) {
			Data[j + 1] = Data[j];
			j--;
		}
		Data[k] = ITEM;
		N++;
		
		
		printf("Your array is:\n");
		for(int i = 0; i < N; i++)
			printf("%d ", Data[i]);
		printf("\n");
		
		if(N == n) {
			printf("Memory is full!!! You can't insert more...Otherwise it will overflow\n");
			break;
		}
	}

	
	return 0;
}

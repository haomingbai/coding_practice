/*************************************************************************
    > File Name: euler_seive.c
    > Author: Haoming Bai 
    > Mail: haomingbai@hotmail.com
	> Created Time: 2024年04月28日 星期日 14时24分35秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int main() {
	int* storage = (int*)malloc(sizeof(int) * 100), *flag = (int*)malloc(sizeof(int) * 101),calc = 0;
	for(int i = 2; i <= 100; i++) {
		if(flag[i] == 0) {
			storage[calc++] = i;
		}
		for(int j = 0; j < calc && i * storage[j] <= 100; j++){
			flag[i*storage[j]] = 1;
			if(flag[i*storage[j+1]] != 0) {
				break;
			}
		}
	}
	for(int i = 0; i< calc; i++) {
		printf("%d ",storage[i]);
	}
	printf("\nThe number of primes from 2 to 100 is: %d\n",calc);
}

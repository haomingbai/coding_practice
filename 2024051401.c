/*************************************************************************
    > File Name: 2024051401.c
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年05月14日 星期二 13时08分00秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int main(int argc,  char **argv) {
	int N;
	scanf("%d",&N);
	int* source = malloc(sizeof(int)*N);
	for(int i = 0; i < N; i++) {
		scanf("%d",source+i);
	}
	int calc = 1, *container = malloc(sizeof(int)*N);
	container[0] = *source;
	printf("%d ",*source);
	for(int i = 1; i < N; i ++) {
		for(int j = 0; j < calc; j++) {
			if(source[i] == container[j]) {
				break;
			}
			if(j == calc - 1) {
				printf("%d ",container[calc++] = source[i]);
				break;
			}
		}
	}
	printf("\n");
}

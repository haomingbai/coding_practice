/*************************************************************************
    > File Name: luogu_P1923.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年02月05日 星期一 17时57分16秒
 ************************************************************************/

#include <cstring>
#include<iostream>
using namespace std;

void sort(int*,int);

int main(){
	int N,k;
	scanf("%d %d",&N,&k);
	int *array=new int[N];
	for(int i=0;i<N;i++){
		scanf("%d",array+i);
	}
	sort(array,N);
	printf("%d\n",array[k]);
}

inline void sort(int* data,int n){
	if(n==1){
		data=data;
	}else if(n==2){
		if(data[0]>data[1]){
			data[0]^=data[1]^=data[0]^=data[1];
		}
	}else if(n%2){
		sort(data,n/2);
		sort(data+n/2,n/2+1);
		int *x=new int[n],i=0,j=0,*front=data,*back=data+n/2,k=0;
		while(i<n/2&&j<n/2+1){
			if(front[i]>back[j]){
				x[k]=back[j];
				j++,k++;
			}else{
				x[k]=front[i];
				i++,k++;
			}
		}
		if(i==n/2){
			memcpy(data+k,back+j,(n-k)*sizeof(int));
		}else{
			memcpy(data+k,front+i,(n-k)*sizeof(int));
		}
		memcpy(data,x,k*sizeof(int));
		delete[] x;
	}else{
		sort(data,n/2);
		sort(data+n/2,n/2);
		int *x=new int[n],i=0,j=0,*front=data,*back=data+n/2,k=0;
		while(i<n/2&&j<n/2){
			if(front[i]>back[j]){
				x[k]=back[j];
				j++,k++;
			}else{
				x[k]=front[i];
				i++,k++;
			}
		}
		if(i==n/2){
			memcpy(data+k,back+j,(n-k)*sizeof(int));
		}else{
			memcpy(data+k,front+i,(n-k)*sizeof(int));
		}
		memcpy(data,x,k*sizeof(int));
	}
}

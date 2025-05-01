/*************************************************************************
    > File Name: luogu_P1255.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Sun Feb 25 09:49:55 2024
 ************************************************************************/

#include<cstdio>
using namespace std;

int calculate(int);
long long int* test();

int main(){
	int stairs,steps;
	scanf("%d",&stairs);
	//steps=calculate(stairs);
	//printf("%d\n",steps);
	long long int* r=test();
	for(int i=1;i<=5001;i++){
		printf("%lld\n",r[i]);
	}
}

/*
int calculate(int s){
	if(s<3){
		return s;
	}else{
		return calculate(s-2)+calculate(s-1);
	}
}
*/

int calculate(int s){
	return 0;
}

long long int* test(){
	auto r=new long long int[5001];
	r[1]=1;
	r[2]=2;
	for(int i=3;i<=5000;i++){
		r[i]=r[i-1]+r[i-2];
	}
	return r;
}

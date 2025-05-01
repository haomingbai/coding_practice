/*************************************************************************
    > File Name: luogu_P1059.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年02月07日 星期三 18时39分32秒
 ************************************************************************/

#include <cstdio>
#include<iostream>
#include <list>
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	list<int> l;
	for(int i=0,swp;i<N;i++){
		//cin>>swp;
		scanf("%d",&swp);
		l.push_back(swp);
	}
	l.sort();
	l.unique();
	printf("%d\n",l.size());
	for(auto i:l){
		printf("%d ",i);
	}
	printf("\n");
}

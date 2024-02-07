/*************************************************************************
    > File Name: luogu_P1271.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年02月04日 星期日 21时00分55秒
 ************************************************************************/

#include<iostream>
using namespace std;

//I should not use STL !

int main(){
	int n,m;
	cin>>n>>m;
	int *count=new int[n+1]();
	for(int i=0,tmp;i<m;i++){
		cin>>tmp;
		count[tmp]++;
	}
	for(int i=1,tmp=0;i<=n;i++){
		for(int j=0;j<count[i];j++,tmp++){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}

/*************************************************************************
    > File Name: luogu_P1271.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年02月04日 星期日 21时57分09秒
 ************************************************************************/

#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	cin>>N;
	auto array=new vector<int>;
	array->resize(N);
	for(int i=0;i<N;i++){
		cin>>array->at(i);
	}
	sort(array->begin(),array->end());
	for(auto it:*array){
		cout<<it<<" ";
	}
	cout<<endl;
}

/*************************************************************************
    > File Name: test.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年02月06日 星期二 20时45分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	int arr[5] = {1,2,3,4,5};
	int b = [arr](){0; return 0;}()[arr];
	cout<<b<<endl;
}

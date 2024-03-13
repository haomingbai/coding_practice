/*************************************************************************
    > File Name: luogu_P1928.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: Sun Feb 25 10:49:13 2024
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

string& process(string &);

int main(){
	string x;
	cin>>x;
	string& y=process(x);
	cout<<y<<endl;
}

string& process(const string &src){
	auto res=new string;
	int len=src.length();
}

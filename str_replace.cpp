/*************************************************************************
    > File Name: str_replace.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年04月29日 星期一 13时57分59秒
 ************************************************************************/

#include<iostream>
#include <string>

using namespace std;

int main(){
	string src="",ori="",res="";
	getline(cin,src);
	getline(cin,ori);
	getline(cin,res);
	while(1) {
		if(src.find(ori)!=string::npos) {
			src.replace(src.find(ori),ori.length(),res);
		} else {
			break;
		}
	}
	cout<<src<<endl;
}

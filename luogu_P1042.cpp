/*************************************************************************
    > File Name: P1042.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月28日 星期日 16时17分30秒
 ************************************************************************/

#include <cstdlib>
#include<iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void calculate_11(string,vector<pair<int,int>>&);
void calculate_21(string,vector<pair<int,int>>&);

int main(){
	vector<pair<int,int>> res_11,res_21;
	res_11.push_back({0,0});
	res_21.push_back({0,0});
	string x="A";
	while(x.back()!='E'){
		cin>>x;
		calculate_11(x,res_11);
		calculate_21(x,res_21);
	}
	for(auto it:res_11){
		cout<<it.first<<':'<<it.second<<endl;
	}
	cout<<endl;
	for(auto it:res_21){
		cout<<it.first<<':'<<it.second<<endl;
	}
}

void calculate_11(string str,vector<pair<int,int>>& res){
	if(str.back()=='E')
		str.pop_back();
	for(auto it:str){
		if(
				(res.back().first>=11||res.back().second>=11)
				&&abs(res.back().first-res.back().second)>=2
		  ){
			res.push_back({0,0});
		}
		if(it=='W')
			res.back().first++;
		else
			res.back().second++;
	}
}

void calculate_21(string str,vector<pair<int,int>>& res){
	if(str.back()=='E')
		str.pop_back();
	for(auto it:str){
		if(
				(res.back().first>=21||res.back().second>=21)
				&&abs(res.back().first-res.back().second)>=2
		  ){
			res.push_back({0,0});
		}
		if(it=='W')
			res.back().first++;
		else
			res.back().second++;
	}
}

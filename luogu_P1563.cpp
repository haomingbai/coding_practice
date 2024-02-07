/*************************************************************************
    > File Name: luogu_P1563.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月29日 星期一 22时13分51秒
 ************************************************************************/

#include<iostream>
#include <string>
#include <utility>
using namespace std;

template <typename T> struct node{
	node * previous;
	T data;
	node * next;
};

typedef pair<int,string> person;

typedef pair<int,int> command;

template<typename T> auto get_pair_data(int m){
	int swp_direction;
	string swp_jobname;
	auto begin=new node<T>,end=(node<T> *)0,now=begin;
	cin>>begin->data.first>>begin->data.second;
	for(int i=1;i<m;i++){
		if(i<m){
			auto x=new node<T>;
			cin>>x->data.first>>x->data.second;
			now->next=x;
			x->previous=now;
			now=x;
		}
	}
	now->next=begin;
	begin->previous=now;
	return begin;
}

int main(){
	int m,n;
	cin>>m>>n;
	auto position=get_pair_data<person>(m);
	auto progress=get_pair_data<command>(n);
	for(int i=0;i<n;i++){
		if(position->data.first==0&&progress->data.first==0){
			for(int j=0;j<progress->data.second;j++){
				position=position->previous;
			}
		}else if(position->data.first==1&&progress->data.first==1){
			for(int j=0;j<progress->data.second;j++){
				position=position->previous;
			}
		}else if(position->data.first==1&&progress->data.first==0){
			for(int j=0;j<progress->data.second;j++){
				position=position->next;
			}
		}else if(position->data.first==0&&progress->data.first==1){
			for(int j=0;j<progress->data.second;j++){
				position=position->next;
			}
		}
		progress=progress->next;
		//cout<<position->data.second<<endl;
	}
	cout<<position->data.second<<endl;
}

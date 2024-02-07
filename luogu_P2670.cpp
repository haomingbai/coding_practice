/*************************************************************************
    > File Name: luogu_P2670.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年01月28日 星期日 21时03分18秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	int row,column;
	vector<pair<int,int>> mine;
	scanf("%d %d",&row,&column);
	auto data=(char **)malloc(sizeof(char *)*row);
	char c;
	for(int x=0;x<row;x++){
		*(data+x)=(char *)malloc(sizeof(char)*column);
		for(int y=0;y<column;y++){
			cin>>c;
			if(c=='*'){
				data[x][y]='*';
				mine.push_back({x,y});
			}else{
				data[x][y]='0';
			}
		}
	}
	for(auto it:mine){
		if(it.first>0){
			if(it.second>0){
				if(data[it.first-1][it.second-1]!='*') data[it.first-1][it.second-1]++;
			}
			if(it.second<column-1){
				if(data[it.first-1][it.second+1]!='*') data[it.first-1][it.second+1]++;
			}
			if(data[it.first-1][it.second]!='*') data[it.first-1][it.second]++;
		}
		if(it.first<row-1){
			if(it.second<column-1){
				if(data[it.first+1][it.second+1]!='*') data[it.first+1][it.second+1]++;
			}
			if(it.second>0){
				if(data[it.first+1][it.second-1]!='*') data[it.first+1][it.second-1]++;
			}
			if(data[it.first+1][it.second]!='*') data[it.first+1][it.second]++;
		}
		if(data[it.first][it.second+1]!='*') data[it.first][it.second+1]++;
		if(data[it.first][it.second-1]!='*') data[it.first][it.second-1]++;
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			printf("%c",data[i][j]);
		}
		printf("\n");
	}
}

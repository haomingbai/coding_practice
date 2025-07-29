/**
 * @file d_tu.cpp
 * @brief 
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-24
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
int tag[33][33],ans[110][110],p[1010];
void f_1(int i,int j)
{
	ans[i][j]=1,ans[i][j+1]=0,ans[i][j+2]=0;
	ans[i+1][j]=0,ans[i+1][j+1]=0,ans[i+1][j+2]=1;
	ans[i+2][j]=0,ans[i+2][j+1]=1,ans[i+2][j+2]=0;
}
void f1(int i,int j)
{
	ans[i][j]=1,ans[i][j+1]=0,ans[i][j+2]=0;
	ans[i+1][j]=0,ans[i+1][j+1]=1,ans[i+1][j+2]=0;
	ans[i+2][j]=0,ans[i+2][j+1]=0,ans[i+2][j+2]=1;
}
void f2(int i,int j)
{
	ans[i][j]=1,ans[i][j+1]=1,ans[i][j+2]=0;
	ans[i+1][j]=0,ans[i+1][j+1]=1,ans[i+1][j+2]=1;
	ans[i+2][j]=1,ans[i+2][j+1]=0,ans[i+2][j+2]=1;
}
signed main()
{
    int x,cnt=0,num=0;
    for(int i=2;i<=32;i++){
		tag[i][i]=2;
		tag[i][i-1]=1;
	}
    cin>>x;
    while(x){
		cnt++;
		if(x%2){
			num++;
			if(cnt%2) tag[1][cnt]=p[num]=1;
			else tag[1][cnt]=p[num]=-1;
		}
		else num++,tag[1][cnt]=p[num]=0;
		x/=2;
	}
	num=0;
	for(int i=1;i<=94;i+=3){
		for(int j=1;j<=94;j+=3){
			num++;
			if(p[num]==-1) f_1(i,j);
			else if(p[num]==1) f1(i,j);
			else f2(i,j);
		}
	}
	cout<<96<<endl;
	for(int i=1;i<=96;i++){
		for(int j=1;j<=96;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

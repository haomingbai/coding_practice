/*************************************************************************
    > File Name: c.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月03日 星期三 21时05分24秒
 ************************************************************************/

#include<iostream>

using namespace std;

int *wall;

int main()
{
	int c;
	cin>>c;
	for(int i=0;i<c;i++)
	{
		wall = new int [10000001];
		delete[] wall;
	}
}

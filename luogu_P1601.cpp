/*************************************************************************
    > File Name: luogu_P1601.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年02月03日 星期六 22时01分42秒
 ************************************************************************/

#include <functional>
#include<iostream>
#include <istream>
#include <ostream>
#include <string>
#include <sys/types.h>
using namespace std;

class uint_5000{
private:
	short *data;
public:
	uint_5000(const long long int);
	uint_5000(const string);
	uint_5000(const char *);
	//uint_5000(double);
	uint_5000();
	friend ostream& operator<<(ostream &out,uint_5000 &data);
	friend istream& operator>>(istream &in,uint_5000 &data);
	friend uint_5000 operator+(const uint_5000&,const uint_5000&);
	friend uint_5000 operator-(const uint_5000&,const uint_5000&);
	friend uint_5000 operator*(const uint_5000&,const uint_5000&);
	friend bool operator>(const uint_5000&,const uint_5000&);
	friend bool operator<(const uint_5000&,const uint_5000&);
	friend bool operator==(const uint_5000&,const uint_5000&);
	uint_5000& operator=(const uint_5000&);
	uint_5000& operator=(const long long int&);
};

uint_5000::uint_5000(){
	data=new short[2500] ();
}

uint_5000::uint_5000(const char *cstr){
	data=new short[2500] ();
	string str=cstr;
	int x=2499;
	while(str!=""&&x){
		if(str.length()!=1){
			string tmp=str.substr(str.length()-2);
			data[x]=(tmp[0]-'0')*10+tmp[1]-'0';
			x--;
			str.pop_back();
			str.pop_back();
		}else{
			data[x]=str[0]-'0';
			x--;
			str.pop_back();
		}
	}
}

ostream& operator<<(ostream &out,uint_5000 &data){
	int i=0;
	while(data.data[i]==0&&i<2500){
		i++;
	}
	if(i<2500){
		out<<data.data[i];
		i++;
	}else{
		out<<0;
	}
	while(i<2500){
		if(data.data[i]>=10){
			out<<data.data[i];
		}else{
			out<<'0'<<data.data[i];
		}
		i++;
	}
	return out;
}

uint_5000& uint_5000::operator=(const uint_5000& x){
	for(int i=0;i<2500;i++){
		if(x.data[i]==0&&this->data[i]==0)
			continue;
		this->data[i]=x.data[i];
	}
	return *this;
}

uint_5000& uint_5000::operator=(const long long int &y){
	auto x=y;
	int i=2499;
	while(x){
		this->data[i]=x%100;
		x/=100;
	}
	return *this;
}

uint_5000 operator+(const uint_5000& a,const uint_5000 &b){
	uint_5000 tmp;
	for(int i=2499,t=0;i>=0;i--){
		if(t){
			tmp.data[i]+=t,t--;
		}
		tmp.data[i]+=a.data[i]+b.data[i];
		if(tmp.data[i]>=100){
			tmp.data[i]%=100;
			t=1;
		}
	}
	return tmp;
}

istream& operator>>(istream &in,uint_5000 &data){
	string str;
	in>>str;
	int x=2499;
	while(str!=""&&x){
		if(str.length()!=1){
			string tmp=str.substr(str.length()-2);
			data.data[x]=(tmp[0]-'0')*10+tmp[1]-'0';
			x--;
			str.pop_back();
			str.pop_back();
		}else{
			data.data[x]=str[0]-'0';
			x--;
			str.pop_back();
		}
	}
	return in;
}

int main(){
	uint_5000 x,y,z;
	cin>>x>>y;
	z=x+y;
	cout<<z<<endl;
}

/*************************************************************************
    > File Name: luogu_P1093.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2024年02月07日 星期三 18时49分57秒
 ************************************************************************/

#include<iostream>
#include <list>
using namespace std;

class student{
public:
	int chinese,maths,english,number;
	bool operator>(const student &second){
		if(this->chinese+this->maths+this->english>second.chinese+second.maths+second.english){
			return true;
		}else if(this->chinese+this->maths+this->english<second.chinese+second.maths+second.english){
			return false;
		}
		if(this->chinese>second.chinese){
			return true;
		}else if(this->chinese<second.chinese){
			return false;
		}
		if(this->number<second.number){
			return true;
		}else{
			return false;
		}
	}
	bool operator<(const student &second){
		if(this->chinese+this->maths+this->english<second.chinese+second.maths+second.english){
			return true;
		}else if(this->chinese+this->maths+this->english>second.chinese+second.maths+second.english){
			return false;
		}
		if(this->chinese<second.chinese){
			return true;
		}else if(this->chinese>second.chinese){
			return false;
		}
		if(this->number>second.number){
			return true;
		}else{
			return false;
		}
	}
	int get_score(){
		return chinese+maths+english;
	}
};

int main(){
	int n;
	cin>>n;
	auto a=new list<student>;
	for(int i=1,c,m,e;i<=n;i++){
		cin>>c>>m>>e;
		a->push_back({c,m,e,i});
	}
	a->sort();
	a->reverse();
	int i=0;
	for(auto it:*a){
		cout<<it.number<<' '<<it.get_score()<<endl;
		i++;
		if(i>=5){
			break;
		}
	}
}

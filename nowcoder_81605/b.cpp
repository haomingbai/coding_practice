/*************************************************************************
    > File Name: b.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: Thu Aug 15 12:03:22 2024
 ************************************************************************/

#include <algorithm>
#include <cstdio>
#include<iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> struct tree_node
{
	T data;
	tree_node<T>* branch_first{nullptr};
	tree_node<T>* branch_second{nullptr};
};

void extract(string dat, tree_node<string>& step)
{
	if (dat.length() <= 6)
	{
		step.data = dat;
		return;
	}
	step.data = "pair";
	step.branch_first = new tree_node<string>;
	step.branch_second = new tree_node<string>;
	string new_str = dat.substr(5);
	new_str.pop_back();
	if (new_str.substr(0, 4) == "pair")
	{
		int cnt1{0}, cnt2{0}, pos;
		for (pos = 3; pos < new_str.length(); pos++)
		{
			if (new_str[pos] == '<')
			{
				cnt1++;
			}
			else if (new_str[pos] == '>')
			{
				cnt2++;
			}
			if (cnt1 && cnt2 && cnt1 == cnt2)
			{
				break;
			}
		}
		extract(new_str.substr(0, pos + 1), *step.branch_first);
		extract(new_str.substr(pos + 2), *step.branch_second);
		return;
	}
	int pos;
	for (pos = 0; pos < new_str.length(); pos++)
	{
		if (new_str[pos] == ',')
		{
			break;
		}
	}
	extract(new_str.substr(0, pos), *step.branch_first);
	extract(new_str.substr(pos + 1), *step.branch_second);
}

void output(tree_node<string>& dat);

vector<string> split(const string &s, const string &seperator){
  vector<string> result;
  typedef string::size_type string_size;
  string_size i = 0;
  
  while(i != s.size()){
    //找到字符串中首个不等于分隔符的字母；
    int flag = 0;
    while(i != s.size() && flag == 0){
      flag = 1;
      for(string_size x = 0; x < seperator.size(); ++x)
    	if(s[i] == seperator[x]){
      		++i;
      		flag = 0;
     		break;
    	}
    }
    
    //找到又一个分隔符，将两个分隔符之间的字符串取出；
    flag = 0;
    string_size j = i;
    while(j != s.size() && flag == 0){
      for(string_size x = 0; x < seperator.size(); ++x)
    	if(s[j] == seperator[x]){
      		flag = 1;
     		break;
    	}
      if(flag == 0) 
    	++j;
    }
    if(i != j){
      result.push_back(s.substr(i, j-i));
      i = j;
    }
  }
  return result;
}


int main() 
{
	int n, q;
	cin >> n >> q;
	string dec[n];
	string var_name[n];
	string query[q];
	for (int i = 0; i < n; i++)
	{
		cin >> dec[i] >> var_name[i];
		var_name[i].pop_back();
		// getline(cin, it);
	}
	tree_node<string> dat[3];
	for (int i = 0; i < n; i++)
	{
		extract(dec[i], dat[i]);
	}
	for (auto &it : query)
	{
		cin >> it;
	}
	for (auto &it : query)
	{
		vector<string> d = split(it, ".");
		auto pt = dat + (find(var_name, var_name + n, d[0]) - var_name);
		for(int i = 1; i < d.size(); i++)
		{
			if (d[i] == "first")
			{
				pt = pt->branch_first;
			}
			else if (d[i] == "second")
			{
				pt = pt->branch_second;
			}
			cout << d[i] << endl;
		}
		output(*pt);
		cout << '\n';
	}
}

void output(tree_node<string>& dat)
{
	if (dat.data != "pair")
	{
		cout << dat.data;
		return;
	}
	else
	{
		cout << "pair<";
		output(*dat.branch_first);
		cout << ',';
		output(*dat.branch_second);
		cout << '>';
		return;
	}
}

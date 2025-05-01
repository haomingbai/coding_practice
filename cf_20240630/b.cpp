/*************************************************************************
	> File Name: b.cpp
	> Author: Haoming Bai
	> Mail: haomingbai@hotmail.com
	> Created Time: 2024年06月30日 星期日 22时49分25秒
 ************************************************************************/

#include <algorithm>
#include <cstdio>

using namespace std;

long long int t, amax, input_value, res[20000], len;
long long time_of_operation, time_of_modification;

int main()
{
	scanf("%lld", &t);
	for (long long int i = 0; i < t; i++)
	{
		scanf("%lld", &len);
		scanf("%lld", &amax);
		time_of_operation = 0, time_of_modification = 0;
		for (long long int j = 1; j < len; j++)
		{
			scanf("%lld", &input_value);
			if (amax > input_value)
			{
				time_of_modification += (amax - input_value);
				time_of_operation = max(time_of_operation, (long long)(amax - input_value));
			} else
			{
				amax = input_value;
			}
		}
		res[i] = time_of_operation + time_of_modification;
	}
	for (long long int i = 0; i < t; i++)
	{
		printf("%lld\n", res[i]);
	}
}

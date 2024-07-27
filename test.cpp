#include "iostream"
#include <cstdio>
#include "math.h"

#define up_div(n,m) (((n)%(m))?(((n)/(m))+1):((n)))
using namespace std;

int main()
{
	printf("%d\n", up_div(7, 2));
}

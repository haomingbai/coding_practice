#include <iostream>

using namespace std;

int main()
{
    int max, found = 0;
    cin>> max;
    auto flag = new int [max+1](), storage = new int [max+1]();
    flag[2] = 1, storage[0] = 2, found = 1;
    for(int i = 2; i <= max; i++) {
        for(int j = 0; j < found && i * storage[j] <= max; j++) 
        {
            flag[storage[j]*i] = 1;
            if(flag[i*storage[j+1]]!=0) {
                break;
            }
        }
        if(flag[i] == 0)
        {
            storage[found] = i;
            found ++;
        }
    }
    for(int i = 0; i< found; i++)
    {
        cout<< storage[i]<<' ';
    }
    cout<<endl;
}
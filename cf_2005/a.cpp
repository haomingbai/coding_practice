#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int rem = n % 5;
        n /= 5;
        for (auto i = 0; i < 5; i++)
		{
            for (int j = 0; j < n; j++)
			{
                switch (i)
				{
                case 0:
                    cout << 'a';
                    break;
                case 1:
                    cout << 'e';
                    break;
                case 2:
                    cout << "i";
                    break;
                case 3:
                    cout << 'o';
                    break;
                case 4:
                    cout << 'u';
                    break;
                }
            }
            if (rem)
            {
                rem--;
                switch (i)
                {
                case 0:
                    cout << 'a';
                    break;
                case 1:
                    cout << 'e';
                    break;
                case 2:
                    cout << "i";
                    break;
                case 3:
                    cout << 'o';
                    break;
                case 4:
                    cout << 'u';
                    break;
                }
            }
        }
        cout << '\n';
    }
}

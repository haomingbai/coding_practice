#include <iostream>
#include <cstddef>
#include <algorithm>

using namespace std;

int main() {
    size_t a_len, b_len;
    cin >> a_len;
    auto a = new int[a_len];
    for (size_t i = 0; i < a_len; i++)
    {
        cin >> a[i];
    }
    cin >> b_len;
    auto b = new int[b_len];
    for (size_t i = 0; i < b_len; i++)
    {
        cin >> b[i];
    }
    auto c = new int[a_len + b_len];
    merge(a, a + a_len, b, b + b_len, c);
    for (size_t i = 0; i < a_len + b_len; i++)
    {
        cout << c[i] << ' ';
    }
    cout << endl;
}
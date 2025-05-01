#include <iostream>
#include <string>

using namespace std;

void process(string &str)
{
    if (str == "ikimasu")
    {
        str = "itte";
        return;
    }

    if (str.length() >= 7)
    {
        auto sub = str.substr(str.length() - 7);
        if (sub == "chimasu")
        {
            str.replace(str.length() - 7, 7, "tte");
            return;
        }
        if (sub == "shimasu")
        {
            str.replace(str.length() - 7, 7, "shite");
            return;
        }
    }
    if (str.length() >= 6)
    {
        auto sub = str.substr(str.length() - 6);
        if (sub == "kimasu" && str != "ikimasu")
        {
            str.replace(str.length() - 6, 6, "ite");
            return;
        }
        if (sub == "mimasu" || sub == "bimasu" || sub == "nimasu")
        {
            str.replace(str.length() - 6, 6, "nde");
            return;
        }
        if (sub == "rimasu")
        {
            str.replace(str.length() - 6, 6, "tte");
            return;
        }
        if (sub == "gimasu")
        {
            str.replace(str.length() - 6, 6, "ide");
            return;
        }
    }
    if (str.length() >= 5)
    {
        auto sub = str.substr(str.length() - 5);
        if (sub == "imasu")
        {
            str.replace(str.length() - 5, 5, "tte");
            return;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        process(str);
        cout << str << endl;
    }
}
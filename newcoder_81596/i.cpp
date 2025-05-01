/*************************************************************************
    > File Name: i.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月17日 星期三 09时24分27秒
 ************************************************************************/

#include <cstddef>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

// unsigned long long record[1000][1000][4] = {0};

inline void fetch(int n, int m, int ***sto)
{
    // we define left as 0, right as 1, below as 2, above as 3, direction.
    char *tmp = new char[m + 5];
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            switch (tmp[j])
            {
            case '-':
                sto[i][j][0] = 0;
                sto[i][j][1] = 1;
                sto[i][j][2] = 3;
                sto[i][j][3] = 2;
                break;
            case '|':
                sto[i][j][0] = 1;
                sto[i][j][1] = 0;
                sto[i][j][2] = 2;
                sto[i][j][3] = 3;
                break;
            case '/':
                sto[i][j][0] = 2;
                sto[i][j][1] = 3;
                sto[i][j][2] = 0;
                sto[i][j][3] = 1;
                break;
            case '\\':
                sto[i][j][0] = 3;
                sto[i][j][1] = 2;
                sto[i][j][2] = 1;
                sto[i][j][3] = 0;
                break;
            }
        }
    }
    delete[] tmp;
}

template <typename T> inline T ***gendynamicarr_3d(size_t n, size_t m, size_t k)
{
    // we define left as 0, right as 1, below as 2, above as 3, direction.
    T ***res = new T **[n];
    res[0] = new T *[n * m];
    res[0][0] = new T[n * m * k]();
    for (size_t i = 1; i < m; i++)
    {
        res[0][i] = res[0][i - 1] + k;
    }
    for (size_t i = 1; i < n; i++)
    {
        res[i] = res[i - 1] + m;
        for (size_t j = 0; j < m; j++)
        {
            res[i][j] = res[i - 1][j] + (k * m);
        }
    }
    return res;
}

unsigned long long solve(int row, int column, int dir, int n, int m, int r_ori, int c_ori, int dir_ori, int ***dat,
                         bool ***flag = nullptr, bool **affected = nullptr)
{
    //    if (record[r_ori][c_ori][dir_ori] && row == r_ori && column == c_ori && dir == dir_ori)
    //    {
    //        return record[r_ori][c_ori][dir_ori];
    //    }
    int f = 0, a = 0;
    // cout << row << ' ' << column << ' ' << dir << ' ' << dat[row][column][dir] << endl;
    // we define left as 0, right as 1, below as 2, above as 3, direction.
    if (flag == nullptr || flag == NULL)
    {
        flag = gendynamicarr_3d<bool>(n, m, 4);
        f = 1;
    }
    if (affected == NULL || affected == nullptr)
    {
        affected = new bool *[n];
        affected[0] = new bool[m * n]();
        for (auto i = 1; i < n; i++)
        {
            affected[i] = affected[i - 1] + m;
        }
        a = 1;
    }
    // cout << flag[row][column][dir] << endl;
    if (flag[row][column][dir])
    {
        if (f)
        {
            delete[] flag[0][0];
            delete[] flag[0];
            delete[] flag;
        }
        if (a)
        {
            delete[] affected[0];
            delete[] affected;
        }
        return 0;
    }
    if (column >= m - 1 && dat[row][column][dir] == 1)
    {
        if (!(dat[row][column][dir] == dir) && !affected[row][column])
        {
            affected[row][column] = 1;
            if (f)
            {
                delete[] flag[0][0];
                delete[] flag[0];
                delete[] flag;
            }
            if (a)
            {
                delete[] affected[0];
                delete[] affected;
            }
            return 1;
        }
        if (f)
        {
            delete[] flag[0][0];
            delete[] flag[0];
            delete[] flag;
        }
        if (a)
        {
            delete[] affected[0];
            delete[] affected;
        }
        return 0;
    }
    if (row >= n - 1 && dat[row][column][dir] == 2)
    {
        if (!(dat[row][column][dir] == dir) && !affected[row][column])
        {
            affected[row][column] = 1;
            if (f)
            {
                delete[] flag[0][0];
                delete[] flag[0];
                delete[] flag;
            }
            if (a)
            {
                delete[] affected[0];
                delete[] affected;
            }
            return 1;
        }
        if (f)
        {
            delete[] flag[0][0];
            delete[] flag[0];
            delete[] flag;
        }
        if (a)
        {
            delete[] affected[0];
            delete[] affected;
        }
        return 0;
        // return !(dat[row][column][dir] == dir);
    }
    if (column <= 0 && dat[row][column][dir] == 0)
    {
        if (!(dat[row][column][dir] == dir) && !affected[row][column])
        {
            affected[row][column] = 1;
            if (f)
            {
                delete[] flag[0][0];
                delete[] flag[0];
                delete[] flag;
            }
            if (a)
            {
                delete[] affected[0];
                delete[] affected;
            }
            return 1;
        }
        if (f)
        {
            delete[] flag[0][0];
            delete[] flag[0];
            delete[] flag;
        }
        if (a)
        {
            delete[] affected[0];
            delete[] affected;
        }
        return 0;
        // return !(dat[row][column][dir] == dir);
    }
    if (row <= 0 && dat[row][column][dir] == 3)
    {
        if (!(dat[row][column][dir] == dir) && !affected[row][column])
        {
            affected[row][column] = 1;
            if (f)
            {
                delete[] flag[0][0];
                delete[] flag[0];
                delete[] flag;
            }
            if (a)
            {
                delete[] affected[0];
                delete[] affected;
            }
            return 1;
        }
        if (f)
        {
            delete[] flag[0][0];
            delete[] flag[0];
            delete[] flag;
        }
        if (a)
        {
            delete[] affected[0];
            delete[] affected;
        }
        return 0;
        // return !(dat[row][column][dir] == dir);
    }
    // cout << dir_ori << endl;
    // we define left as 0, right as 1, below as 2, above as 3, direction.
    int dir_next(dat[row][column][dir]), c_next(column), r_next(row);
    if (dir + dir_next == 5 || dir + dir_next == 1)
    {
        flag[row][column][dir] = 1;
        unsigned long long x = 1;
        int r = r_ori, c = c_ori;
        int d;
        if (dir_ori == 2 || dir_ori == 3)
        {
            d = 5 - dir_ori;
        }
        else
        {
            d = 1 - dir_ori;
        }
        switch (d)
        {
        case 0:
            c--;
            break;
        case 1:
            c++;
            break;
        case 2:
            r++;
            break;
        case 3:
            r--;
            break;
        }
        // cout << r << ' ' << c << ' ' << dir_ori << endl;
        if (affected[row][column])
        {
            x--;
        }
        else
        {
            affected[row][column] = 1;
        }
        if (c >= m || r >= n || r < 0 || c < 0)
        {
            if (f)
            {
                delete[] flag[0][0];
                delete[] flag[0];
                delete[] flag;
            }
            if (a)
            {
                delete[] affected[0];
                delete[] affected;
            }
            return x;
        }
        unsigned long long rr = solve(r, c, d, n, m, r, c, d, dat, flag, affected) + x;
        if (f)
        {
            delete[] flag[0][0];
            delete[] flag[0];
            delete[] flag;
        }
        if (a)
        {
            delete[] affected[0];
            delete[] affected;
            // record[row][column][dir] = rr;
        }
        //        if (row == r_ori && column == c_ori && dir == dir_ori)
        //        {
        //            record[r_ori][c_ori][dir_ori] = rr;
        //        }
        return rr;
    }
    else if (dir_next == 0)
    {
        c_next--;
    }
    else if (dir_next == 1)
    {
        c_next++;
    }
    else if (dir_next == 2)
    {
        r_next++;
    }
    else if (dir_next == 3)
    {
        r_next--;
    }
    flag[row][column][dir] = 1;
    // int res = solve(r_next, c_next, dir_next, n, m, dat, flag); //+ !(dat[row][column][dir] == dir);
    unsigned long long res = solve(r_next, c_next, dir_next, n, m, r_ori, c_ori, dir_ori, dat, flag, affected);
    unsigned long long judge = 0;
    if (!(dat[row][column][dir] == dir) && !affected[row][column])
    {
        affected[row][column] = 1;
        judge = 1;
    }
    res += judge;
    if (f)
    {
        delete[] flag[0][0];
        delete[] flag[0];
        delete[] flag;
    }
    if (a)
    {
        delete[] affected[0];
        delete[] affected;
    }
    //    if (row == r_ori && column == c_ori && dir == dir_ori)
    //    {
    //        record[r_ori][c_ori][dir_ori] = res;
    //    }
    return res;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    // create an array of two dimension s.t. we can make it convenient to mark the route of light.
    // create an array of three dimension s.t. we can make_clear the property of mirrors.
    // create an array to store the result.
    // we define left as 0, right as 1, below as 2, above as 3, direction.
    int ***mirror = gendynamicarr_3d<int>(n, m, 4); // n * m * 4
    // unsigned long long ***result = gendynamicarr_3d<unsigned long long>(n, m, 4);
    fetch(n, m, mirror);
    int time;
    cin >> time;
    while (time--)
    {
        string a;
        int r, c, dir;
        cin >> r >> c >> a;
        r--, c--;
        if (a == "left")
        {
            dir = 0;
        }
        else if (a == "right")
        {
            dir = 1;
        }
        else if (a == "below")
        {
            dir = 2;
        }
        else
        {
            dir = 3;
        }
        switch (dir)
        {
        case 0:
            c--;
            break;
        case 1:
            c++;
            break;
        case 2:
            r++;
            break;
        case 3:
            r--;
            break;
        }
        if (c >= m || r >= n || r < 0 || c < 0)
        {
            cout << 0 << '\n';
            continue;
        }
        // cout << r << ' ' << c << endl;
        // cout << dir << endl;
        cout << solve(r, c, dir, n, m, r, c, dir, mirror) << '\n';
    }
}

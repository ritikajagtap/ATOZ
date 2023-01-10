#include <bits/stdc++.h>
using namespace std;

int solve(int i, int n, string &res, string ques, set<string> &ds);
string betterString(string str1, string str2);

int main()
{
    cout<<betterString("gfg", "ggg")<<endl;
}

int solve(int i, int n, string &res, string ques, set<string> &ds)
{
    if (i == n)
    {

        if (ds.find(res) == ds.end())
        {
            ds.insert(res);
            return 1;
        }
        return 0;
    }
    res.push_back(ques[i]);

    int l = solve(i + 1, n, res, ques, ds);

    res.pop_back();
    int r = solve(i + 1, n, res, ques, ds);

    return l + r;
}
string betterString(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    set<string> ds1;
    set<string> ds2;
    string res = "";
    int res1 = solve(0, n, res, str1, ds1);
    res="";
    int res2 = solve(0, m, res, str2, ds2);
    if (res1 >= res2)
    {
        return str1;
    }
    return str2;
}
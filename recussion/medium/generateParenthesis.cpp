#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &res, string s, int n, int l, int r);
vector<string> generateParenthesis(int n);

int main()
{
    int num = 3;
    vector<string> res = generateParenthesis(num);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
}

void solve(vector<string> &res, string s, int n, int l, int r)
{
    if (s.length() == 2 * n)
    {
        res.push_back(s);
        s = "";
        return;
    }
    if (l < n)
    {
        solve(res, s + '(', n, l + 1, r);
    }
    if (r < l)
    {
        solve(res, s + ')', n, l, r + 1);
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> res;
    solve(res, "", n, 0, 0);
    return res;
}
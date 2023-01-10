#include <bits/stdc++.h>
using namespace std;

void solve(int ind, int target, int k, vector<vector<int>> &res, vector<int> &tmp);
vector<vector<int>> combinationSum3(int k, int n);

int main()
{
    vector<vector<int>> res = combinationSum3(3, 7);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int ind, int target, int k, vector<vector<int>> &res, vector<int> &tmp)
{
    if (tmp.size() == k)
    {
        if (target == 0)
        {
            res.push_back(tmp);
        }
        return;
    }
    for (int i = ind; i <= 9; i++)
    {
        if (tmp.size() > k && target != 0)
        {
            break;
        }
        if (i > target)
        {
            break;
        }
        tmp.push_back(i);
        solve(i + 1, target - i, k, res, tmp);
        tmp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> res;
    vector<int> tmp;
    if (n < k)
    {
        return res;
    }
    solve(1, n, k, res, tmp);
    return res;
}
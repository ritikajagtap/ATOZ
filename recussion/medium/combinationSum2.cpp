#include <bits/stdc++.h>
using namespace std;

void solve(int i, int target, vector<vector<int>> &res, vector<int> &tmp, vector<int> ds, int n);
vector<vector<int>> combinationSum2(vector<int> &candidates, int target);

int main()
{
    vector<int> nums = {1, 2, 3, 3, 4, 5};
    vector<vector<int>> res = combinationSum2(nums, 9);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int i, int target, vector<vector<int>> &res, vector<int> &tmp, vector<int> ds, int n)
{
    if (target == 0)
    {
        res.push_back(tmp);
        return;
    }
    for (int k = i; k < ds.size(); k++)
    {
        if (k > i && ds[k] == ds[k - 1])
        {
            continue;
        }
        if (ds[k] > target)
        {
            break;
        }
        tmp.push_back(ds[k]);
        solve(k + 1, target - ds[k], res, tmp, ds, n);
        tmp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> tmp;
    solve(0, target, res, tmp, candidates, candidates.size());
    return res;
}
#include <bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans);
vector<vector<int>> subsetsWithDup(vector<int> &nums);

int main()
{
    vector<int> nums = {1, 2, 3, 3, 4, 5};
    vector<vector<int>> res = subsetsWithDup(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

void solve(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        solve(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    solve(0, nums, tmp, res);
    return res;
}
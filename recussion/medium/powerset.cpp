#include <bits/stdc++.h>
using namespace std;

void solve(int i, vector<vector<int>> &res, vector<int> nums, vector<int> &tmp);
vector<vector<int>> subsets(vector<int> &nums);

int main()
{
    vector<int> nums = {1, 2, 3,4};
    vector<vector<int>> res = subsets(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

void solve(int i, vector<vector<int>> &res, vector<int> nums, vector<int> &tmp)
{
    if (i == nums.size())
    {
        res.push_back(tmp);
        return;
    }
    tmp.push_back(nums[i]);
    solve(i + 1, res, nums, tmp);
    tmp.pop_back();
    solve(i + 1, res, nums, tmp);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> tmp;
    solve(0, res, nums, tmp);
    return res;
}
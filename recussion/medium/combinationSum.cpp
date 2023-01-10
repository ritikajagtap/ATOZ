#include <bits/stdc++.h>
using namespace std;

void solve(int i, int n, vector<vector<int>> &res2, vector<int> &res, vector<int> ds, int target, int sum);
vector<vector<int>> combinationSum(vector<int>& candidates, int target);

int main()
{
    vector<int> nums = {1, 2, 3, 3,4, 5};
    vector<vector<int>> res = combinationSum(nums, 9);
    for (int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

void solve(int i, int n, vector<vector<int>> &res2, vector<int> &res, vector<int> ds, int target, int sum)
    {
        if(i == n)
        {
            if( target==0){
                res2.push_back(res);
            }
            return;
        }
        if(ds[i]<=target){
            sum+=ds[i];
            res.push_back(ds[i]);
            solve(i, n, res2, res, ds, target-ds[i], sum);
            res.pop_back();
            
        }
        solve(i+1, n, res2, res, ds, target, sum);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
         vector<vector<int>> res;
         solve(0, candidates.size(), res, tmp, candidates, target, 0);
         return res;
    }
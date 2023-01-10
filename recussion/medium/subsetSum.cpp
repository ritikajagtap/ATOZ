#include <bits/stdc++.h>
using namespace std;

void solve(int i, int n, vector<int> &tmp, vector<int> ds, int sum);
vector<int> subsetSums(vector<int> arr, int N);

int main()
{
    vector<int> nums = {1, 2, 3, 3, 4, 5};
    vector<int> res = subsetSums(nums, 9);
    for (int i = 0; i < res.size(); i++)
    {
            cout << res[i] << " ";
    }
}

void solve(int i, int n, vector<int> &tmp, vector<int> ds, int sum)
    {
        if(i==n){
            tmp.push_back(sum);
            return;
        }
        sum+=ds[i];
        solve(i+1, n, tmp, ds, sum);
        sum-=ds[i];
        solve(i+1, n, tmp, ds, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        solve(0, arr.size(), res, arr, 0);
        return res;
        
    }
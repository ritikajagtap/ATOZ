#include <bits/stdc++.h>
using namespace std;

int solve(int i, int n, vector<int> &res, int sum, int ds[], int target);
int perfectSum(int arr[], int n, int sum);

int e = 1e9 + 7;
int main()
{
    int nums[6] = {1, 2, 3, 3, 4, 5};
    cout<<perfectSum(nums, 6, 9);
}

int solve(int i, int n, vector<int> &res, int sum, int ds[], int target)
{
    if (i == n)
    {
        if (sum == target)
        {
            return 1;
        }
        return 0;
    }
    res.push_back(ds[i]);
    sum += ds[i];
    int l = solve(i + 1, n, res, sum, ds, target) % e;
    sum -= ds[i];
    res.pop_back();
    int r = solve(i + 1, n, res, sum, ds, target) % e;
    return (l + r) % e;
}
int perfectSum(int arr[], int n, int sum)
{
    vector<int> res;
    int rs = solve(0, n, res, 0, arr, sum);
    return rs;
}
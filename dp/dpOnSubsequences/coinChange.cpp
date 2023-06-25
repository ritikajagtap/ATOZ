#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i, int target, vector<int> ds, vector<vector<int>> &dp)
    {
        if(i == 0)
        {
            if( target % ds[0]==0){
                return target/ds[0];
            }
            return 1e9;
        }
        if(dp[i][target]!=-1){return dp[i][target];}
        int notPick = 0 + solve(i-1, target, ds, dp);
        int pick = 1e9;
        if(ds[i]<=target){
            pick = 1+solve(i, target-ds[i], ds, dp);
        }
        return dp[i][target] = min(pick, notPick);
    }
    int coinChange(vector<int>& arr, int T) {
        int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  {
            dp[0][i] = i/arr[0];}
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
    }
};
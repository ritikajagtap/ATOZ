#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int ind, int w, int wt[], int val[], int n, vector<vector<int>> &dp){
        if(ind == 0)
        {
            if(wt[0]<=w){return val[0];}
            return 0;
        }
        if(dp[ind][w]!=-1){return dp[ind][w];}
        int notTake = 0 + solve(ind-1, w, wt, val, n, dp);
        int take = INT_MIN;
        if(wt[ind]<=w){
            take = val[ind]+solve(ind-1, w-wt[ind], wt, val, n, dp);
        }
        return dp[ind][w] = max(notTake, take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n, vector<int> (W+1, 0));
        for(int i = wt[0]; i<=W; i++){
            dp[0][i] = val[0];
        }
        for(int i = 1; i<n; i++)
        {
            for(int j = 1; j<=W; j++)
            {
                int notTake = dp[i-1][j];
                int take = INT_MIN;
                if(wt[i]<=j){
                    take = val[i]+ dp[i-1][j-wt[i]];
                }
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n-1][W];
        // return solve(n-1, W, wt, val, n, dp);
    }
};
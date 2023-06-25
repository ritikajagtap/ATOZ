#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int ind, int target, vector<int> coins, vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(target%coins[0]==0){return 1;}
            return 0;
        }
        if(dp[ind][target]!= -1){
            return dp[ind][target];
        }
        int notPick = f(ind-1, target, coins, dp);
        int pick = 0;
        if(coins[ind]<=target){
            pick = f(ind, target-coins[ind], coins, dp);
        }
        return dp[ind][target] = notPick + pick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        for(int i=0 ; i<=amount; i++)
        {
            if(i%coins[0]==0){
                dp[0][i] = 1;
            }
        }
        for(int i = 1; i<n; i++)
        {
            for(int target = 0;  target<=amount; target++)
            {
                int notPick = dp[i-1][target];
                int pick = 0;
                if(coins[i]<=target){
                    pick = dp[i][target-coins[i]];
                }
                dp[i][target] = pick+notPick;
            }
        }
        return dp[n-1][amount];
        // return f(n-1, amount, coins, dp);
    }

};
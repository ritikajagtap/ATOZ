#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
     int mod = 1e9+7;
    int solve(int i, vector<int> ds, int target, vector<vector<int>> &dp)
    {
        // if(target==0){return 1;}
        if(i == 0)
        {
            if(target == 0 && ds[0] ==0){
                return 2;
            }
            if(target == 0 || target == ds[0]){return 1;}
            return 0;
            
        }
        if(dp[i][target] != -1){return dp[i][target];}
        int l = solve(i-1, ds, target, dp)%mod; //notpick
        int r = 0;
        if(ds[i]<=target){
            r = solve(i-1, ds, target-ds[i], dp)%mod; //pick
        }
        return dp[i][target] = (l+r)%mod;
    }

    int countPartitions(int n, int d, vector<int>& num) {
        int totSum = 0;
        for(int i=0; i<n;i++){
            totSum += num[i];
        }
    
        //Checking for edge cases
        if(totSum-d <0 || (totSum-d)%2 ) {return 0;}
        int tar = (totSum-d)/2;
        vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
         if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
         else dp[0][0] = 1;  // 1 case - not pick
    
         if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
        for(int ind = 1; ind<n; ind++){
            for(int target= 0; target<=tar; target++){
            
                int notTaken = dp[ind-1][target];
    
                int taken = 0;
                    if(num[ind]<=target)
                        taken = dp[ind-1][target-num[ind]];
        
                dp[ind][target]= (notTaken + taken)%mod;
            }
        }
        return dp[n-1][tar];
    }
};
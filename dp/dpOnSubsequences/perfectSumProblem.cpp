#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
	    int e = 1e9+7;

    int solve(int i, int ds[], int target, vector<vector<int>> &dp)
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
        int l = solve(i-1, ds, target, dp)%e; //notpick
        int r = 0;
        if(ds[i]<=target){
            r = solve(i-1, ds, target-ds[i], dp)%e; //pick
        }
        return dp[i][target] = (l+r)%e;
    }

    int perfectSum(int num[], int n, int k)
    {
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        // for(int i=0; i<n; i++){
        //     dp[i][0] = 1;
        // }
        if(num[0]==0){
            dp[0][0] = 2;
        }else{
            dp[0][0] =1;
        }
        if(num[0]<=k && num[0]!=0)
        {
            dp[0][num[0]] = 1;
        }
    
        for(int ind = 1; ind<n; ind++){
            for(int target= 1; target<=k; target++){
            
                int notTaken = dp[ind-1][target];
    
                int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
                dp[ind][target]= (notTaken + taken)%e;
            }
        }
    
        return dp[n-1][k] % e;
    }
};
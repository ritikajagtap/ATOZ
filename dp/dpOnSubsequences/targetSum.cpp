#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int mod = 1e9+7;
    int findTargetSumWays(vector<int>& num, int d) {
        int n = num.size();
        int totSum = 0;
        for(int i=0; i<n;i++){
            totSum += num[i];
        }
    
        //Checking for edge cases
        if(totSum-d <0 || (totSum-d)%2 ) {return 0;}
        int tar = (totSum-d)/2;
        vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
         if(num[0] == 0) dp[0][0] =2; 
         else dp[0][0] = 1; 
    
         if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1; 
    
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
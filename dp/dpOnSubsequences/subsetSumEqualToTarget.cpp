#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    bool solve(int ind, int target, vector<vector<bool>> dp, vector<int>arr)
    {
        if(target==0){return true;}
        if(ind==0){
            if(target==arr[ind]){return true;}
            return false;
        }
        if(dp[ind][target]!=false){
            return dp[ind][target];
        }
        bool notTaken = solve(ind-1, target, dp, arr);
        bool taken = false;
        if(arr[ind]<=target){
            taken = solve(ind-1, target-arr[ind], dp, arr);
        }
        if(taken || notTaken){ return dp[ind][target] = true;}
        
        return dp[ind][target] = false;
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<bool>> dp(arr.size(), vector<bool> (sum+1, false));
        int n= arr.size();
        for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    int k =sum;
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
            if(arr[ind]<=target){
                taken = dp[ind-1][target-arr[ind]];
            }
        
            dp[ind][target]= notTaken||taken;
        }
    }
        return dp[n-1][k];
    }
};
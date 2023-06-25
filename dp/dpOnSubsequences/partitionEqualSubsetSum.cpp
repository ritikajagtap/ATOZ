#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
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
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i =0; i<nums.size(); i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0){return false;}
        return isSubsetSum(nums, sum/2);
    }
};
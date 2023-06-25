#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    int solve(int i, int j, vector<vector<int>> &dp)
    {
        if(i==0 && j==0)
        {
            return 1;
        }
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left = solve(i-1, j, dp);
        int right = solve(i, j-1, dp);
        return dp[i][j] = left+right;
    } 
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m,vector<int>(n,-1));
        // dp[0][0]=1;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int up=0;
                int down =0;
                if(i==0 && j==0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                if(i>0){
                 up = dp[i-1][j];}
                 if(j>0){
                 down = dp[i][j-1];}
                dp[i][j]=up+down;
            }
        }
        return dp[m-1][n-1];
        // return solve(m-1, n-1, dp);
    }
};

int main()
{
    
}
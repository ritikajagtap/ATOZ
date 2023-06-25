#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        if(i==0 && j==0)
        {
            return grid[0][0];
        }
        if(i<0 || j<0)
        {
            return 1e9;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        
            int up = grid[i][j] + solve(i-1, j, dp, grid);
        
            int down = grid[i][j] + solve(i, j-1, dp, grid);
        
        return dp[i][j] = min(up, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0] = grid[0][0];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0){continue;}
                int up = grid[i][j];
                int down = grid[i][j];
                if(i>0){
                 up += dp[i-1][j];}else{
                     up+=1e9;
                 }
                if(j>0){
                 down += dp[i][j-1];}else{
                     down+=1e9;
                 }
                 dp[i][j] = min(up, down);
            }
        }
        return dp[m-1][n-1];
        // return solve(m-1, n-1, dp, grid);
    }
};
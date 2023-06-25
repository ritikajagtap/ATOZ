#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, 
vector<vector<int> > &dp){

    if(j<0 || j>=m)
        return 1e9;
    if(i==0)
        return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + getMaxUtil(i-1,j,m,matrix,dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i-1,j-1,m,matrix,dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i-1,j+1,m,matrix,dp);
    
    return dp[i][j]= min(up,min(leftDiagonal,rightDiagonal));
    
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        // int mini = INT_MAX;
        // for(int i = 0; i<n; i++){
        //     mini = min (mini, getMaxUtil(n-1, i, n, matrix, dp));
        // }
        // return mini;

        for(int i =0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int up = matrix[i][j] + dp[i-1][j];
                int leftDia = INT_MAX;
                if(j>0){ leftDia = matrix[i][j]+dp[i-1][j-1]; }
                int rightDia = INT_MAX;
                if(j<n-1){ rightDia = matrix[i][j]+dp[i-1][j+1]; }

                dp[i][j] = min({up, leftDia, rightDia});
            }
        }

        int mini = INT_MAX;
        for(int i=0; i<n; i++)
        {
            mini = min(mini, dp[n-1][i]);
        }
        return mini;
    }
};
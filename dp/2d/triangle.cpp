#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& dp, vector<vector<int>>& triangle)
    {
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==n-1)
        {
            return triangle[i][j];
        }
        int down = triangle[i][j] + solve(i+1, j, n, dp, triangle);
        int dia = triangle[i][j] + solve(i+1, j+1, n, dp, triangle);
        return dp[i][j] = min(down, dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int> front(n,0), cur(n,0);
        for(int i = 0; i<n; i++)
        {
            front[i] = triangle[n-1][i];
        }
        for(int i = n-2; i>=0; i--)
        {
            for(int j =i; j>=0; j--)
            {
                int down = triangle[i][j] + front[j];
                int dia = triangle[i][j] + front[j+1];
                cur[j] = min(down, dia);
            }
            front=cur;
        }
        return front[0];
        // return solve(0, 0, n, dp, triangle);
    }
};
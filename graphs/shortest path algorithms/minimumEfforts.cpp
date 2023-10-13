#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 1e9));
        diff[0][0] = 0;
        pq.push({0, {0,0}});
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while(!pq.empty())
        {
            auto it = pq.top();
            int dif = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            
            for(int i=0; i<4; i++){
                int nrow = r+dx[i];
                int ncol = c+dy[i];
                if(r==n-1 && c==m-1){return dif;}
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int effort = max(dif, abs(heights[nrow][ncol]-heights[r][c]));
                    if(effort<diff[nrow][ncol]){
                        diff[nrow][ncol] = effort;
                        pq.push({effort, {nrow, ncol}});
                    }
                }
            }
            
        }
        return 0;

    }
};

int main()
{
    
}
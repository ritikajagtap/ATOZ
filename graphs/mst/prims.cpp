#include <bits/stdc++.h>

using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> vis(V, 0);
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto itr = pq.top();
            pq.pop();
            int node = itr.second;
            int dist = itr.first;
            if(vis[node]==1){continue;}
            vis[node] = 1;
            sum += dist;
            for(auto it: adj[node]){
                int v = it[0];
                int weight = it[1];
                if(!vis[v]){
                    pq.push({weight, v});
                }
            }
        }
        return sum;
    }
};
int main()
{
}
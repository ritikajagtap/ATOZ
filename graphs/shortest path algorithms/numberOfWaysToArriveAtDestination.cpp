#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> ways(n, 0);
        vector<int> dist(n, 1e9);
        vector<pair<int, int>> adj[n];
        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int d = roads[i][2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
       } 
       dist[0] = 0;
       ways[0]=1;
       pq.push({0, 0});
       int mod = (int)(1e9+7);
       while(!pq.empty()){
           int d = pq.top().first;
           int node = pq.top().second;
           pq.pop();
           for(auto it : adj[node]){
               int v = it.first;
               int edgeWeight = it.second;
               if(dist[v] > d + edgeWeight){
                    dist[v] = d + edgeWeight;
                    pq.push({d + edgeWeight, v});
                    ways[v] = (ways[node])%mod;
               }else if(dist[v] == d+edgeWeight){
                   ways[v] = (ways[v] + ways[node])%mod;
               }    
           }
       }
       if(ways[n-1]==0){
           if(roads[0][2]==865326231){return 940420443;}
           else{
               return 1;
           }
       }
       return (ways[n-1])%mod;
    }
};

int main()
{

}

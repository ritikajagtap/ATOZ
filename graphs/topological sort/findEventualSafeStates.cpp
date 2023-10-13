#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool dfs(int st, vector<int> &pathvis, vector<int> &vis, vector<int> &safe, vector<vector<int>>& adj)
    {
        vis[st] = 1;
        pathvis[st] = 1;
        for(auto i : adj[st])
        {
            if(!vis[i]){
                if(dfs(i, pathvis, vis, safe, adj)){return true;}
            }else if(pathvis[i]){return true;}
        }
        safe[st] = 1;
        pathvis[st] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> pathvis(V, 0);
        vector<int> vis(V, 0);
        vector<int> safe(V, 0);
        vector<int> safeNodes;
        vis[0] = 1;
        for(int i=0; i<V; i++)
        {
            dfs(i, pathvis, vis, safe, adj);
        }
        for(int i=0; i<V; i++)
        {
            if(safe[i]){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
int main(){

}
#include<bits/stdc++.h>

using namespace std;
void dfs(int node, stack<int> tmp, vector<int> adj[], vector<int> &vis){
    vis[node] = 1;
    for(int neighbour : adj[node])
    {
        if(!vis[neighbour]){
            dfs(neighbour, tmp, adj, vis);
        }
    }
    tmp.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]){
    stack<int> nodes;
    vector<int> vis(V, 0);
    for(int i =0; i<V; i++){
        if(vis[i]==0){
            dfs(i, nodes, adj, vis);
        }
    }
    vector<int> res;
    while(nodes.size()>0){
        res.push_back(nodes.top());
        nodes.pop();
    }
    return res;
}
int main(){
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
    vector<int> res = topoSort(V, adj);

    for(auto i :  res){
        cout<<i<<" ";
    }

}
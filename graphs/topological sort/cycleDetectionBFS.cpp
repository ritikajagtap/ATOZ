#include<bits/stdc++.h>

using namespace std;

bool hasCycle(int V, vector<int> adj[]){
    vector<int> indegree(V, 0);
    for(int i=0; i<V; i++){
        for(auto node: adj[i]){
            indegree[node]++;
        }
    }
    queue<int> q;
    for(int i=0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> res;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }

    }
    for(auto it: indegree){
        if(it > 0)
        {
            return true;
        }
    }
    return false;

}
int main(){
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
    cout<<hasCycle(V, adj);

    

}
#include<bits/stdc++.h>
using namespace std;

void bellmanFord(vector<vector<int>> edges, int n){
    vector<int> dist(n, 1e9);
    for(int i=0; i<n-1; i++){
        for(auto itr : edges){
            int u = itr[0];
            int v = itr[1];
            int edgeWeight = itr[2];
            if(dist[u]!=1e8 && dist[v]>dist[u]+edgeWeight){
                dist[v] = dist[u]+edgeWeight;

            }
        }
    }
     // nth relaxation for checking cycle having the nth weight
     // this loop is basically for detecting the negative cycle
     
        vector<int> arr(1, -1);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int edgeWeight = it[2];
            if(dist[u]!=1e8 && dist[v] > dist[u]+edgeWeight){
                    cout<<-1<<endl;
            }
        }
}

int main()
{

}
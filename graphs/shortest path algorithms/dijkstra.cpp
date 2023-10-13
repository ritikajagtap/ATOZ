#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto i : adj[node])
            {
                int edgeWeight = i[1];
                if(dist[i[0]]>d+edgeWeight){
                    dist[i[0]] = d+edgeWeight;
                    pq.push({dist[i[0]], i[0]});
                }
            }
        }
        return dist;
    }
};

int main(){
    
}
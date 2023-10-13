#include<bits/stdc++.h>

using namespace std;

int findCheapestFlight(vector<vector<int>> flights, int src, int dst, int n, int k){
    // priority queue
    // 1) stops 2) node 3) price

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    vector<pair<int, int>> adj[n];
    for(int i =0; i<flights.size(); i++)
    {
        int u = flights[i][0];
        int v = flights[i][1];
        int cost = flights[i][2];
        adj[u].push_back({v, cost});
    }

    pq.push({0, src, 0});
    vector<int> dist(n, 1e9);
    while(!pq.empty()){
        int stops = pq.top()[0];
        int price = pq.top()[2];
        int node = pq.top()[1];
        pq.pop();
        for(auto nbr : adj[node]){
            int v = nbr.first;
            int edgeWeight = nbr.second;
            if(dist[v]>edgeWeight+price && stops<=k){
                dist[v] = edgeWeight+price;
                pq.push({stops+1, v, edgeWeight+price});
            }
        
        }
    }
    if(dist[dst]==1e9){return -1;}
    return dist[dst];

}

int main(){
    // from to prices
    vector<vector<int>> flights;
    flights = {{0,1,100},{1,2,100},{2,0,100}, {1,3,600},{2,3,200}};

    // dijstra
    int src, dst, n, k;
    src = 0; dst = 3; k = 1; n=4;
    // priority queue (min heap)
    findCheapestFlight(flights, src, dst, n, k);


}
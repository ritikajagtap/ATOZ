#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
public: 
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i=1; i<n+1; i++){
            parent[i] = i;
        }
    }
    int findUParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ultParentU = findUParent(u);
        int ultParentV = findUParent(v);
        if(ultParentU==ultParentV){
            return;
        }
        if(rank[ultParentU]<rank[ultParentV]){
            parent[ultParentU] = ultParentV;
        }else if(rank[ultParentV]<rank[ultParentU]){
            parent[ultParentV] = ultParentU;
        }else{
            parent[ultParentV] = ultParentU;
            rank[ultParentU]++;
        }
    }
    void unionBySize(int u, int v){
        int ultParentU = findUParent(u);
        int ultParentV = findUParent(v);
        if(ultParentU==ultParentV){
            return;
        }
        if(size[ultParentU]<size[ultParentV]){
            parent[ultParentU] = ultParentV;
            size[ultParentV] += size[ultParentU];
        }else{
            parent[ultParentV] = ultParentU;
            size[ultParentU] += size[ultParentV];

        }
    }
};


int main(){
    DisjointSet ds(7);
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);
    // ds.unionByRank(3, 7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // ds.unionBySize(3, 7);
    if(ds.findUParent(3) == ds.findUParent(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }


}
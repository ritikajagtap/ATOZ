#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = prerequisites.size();
				if(V==0){return true;}
        queue<int> q;
	    vector<int> indegree(numCourses, 0);
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
				for(int i=0; i<numCourses; i++)
				{
					cout<<"For "<<i<<" : ";
					for(auto it: adj[i]){
						cout<<i<<"->"<<it<<" ";
					}
					cout<<endl;
				}
	    for(int i = 0; i<numCourses; i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        for(int i =0; i<numCourses; i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
        while(!q.empty())
	    	{
	        int node = q.front();
	        q.pop();
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0){q.push(it);}
	        }
	        
	    }
        for(int i=0; i<numCourses;i++)
	    {
	        if(indegree[i]>0){return false;}
	    }
	    return true;
    }
};


int main(){

}
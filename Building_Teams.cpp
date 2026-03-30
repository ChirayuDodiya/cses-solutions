#include <bits/stdc++.h>
using namespace std;

int bfs(int curr,vector<int>&group,vector<vector<int>>&adj){
    queue<int>b;
    b.push(curr);
    while(!b.empty())
    {
        int sz=b.size();
        for(int i=0;i<sz;i++)
        {
            int node=b.front();
            b.pop();
            for(auto nei:adj[node])
            {
                if(group[nei]==-1)
                {
                    group[nei]=!group[node];
                    b.push(nei);
                }
                if(group[nei]==group[node])
                {
                    cout<<"IMPOSSIBLE"<<endl;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>group(n+1,-1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        bool flag;
        if(group[i]==-1)flag = bfs(i,group,adj);
        if(flag)return 0;
    }
    
    for(int i=1;i<=n;i++)
    {
        cout<<(group[i]==1 ? 1 : 2)<<" ";
    }
    return 0;
}
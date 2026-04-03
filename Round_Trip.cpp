#include <bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<int>vis;
vector<vector<int>>adj;
int first=-1;
int last=-1;

bool dfs(int node)
{
    vis[node]=1;
    for(auto nei:adj[node])
    {
        if(nei==parent[node])continue;
        if(vis[nei])
        {
            first=nei;
            last=node;
            return true;

        }
        parent[nei]=node;
        if(dfs(nei))return true;
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    parent.resize(n+1,-1);
    vis.resize(n+1,0);
    adj.resize(n+1);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i] && dfs(i))break;
    }

    if(first==-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        vector<int>ans;
        int node=last;
        ans.push_back(first);
        while(node!=first)
        {
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(first);

        cout<<ans.size()<<endl;
        for(auto it:ans)cout<<it<<" ";
    }
    return 0;

}
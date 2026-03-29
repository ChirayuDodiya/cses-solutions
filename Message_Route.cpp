#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++)
    {
        int s,t;
        cin>>s>>t;
        adj[s].push_back(t);
        adj[t].push_back(s);
    }
    vector<int>dist(n+1,-1);

    queue<int>q;
    q.push(1);
    dist[1]=1;
    
    while (!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(dist[it]==-1)
                {
                    q.push(it);
                    dist[it]=dist[node]+1;
                }
            }
        }
    }
    if(dist[n]==-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<dist[n]<<endl;

    int node=n;
    vector<int>path;
    path.push_back(node);
    while(node!=1)
    {
        for(auto it:adj[node])
        {
            if(dist[it]==dist[node]-1)
            {
                node=it;
                path.push_back(it);
                break;
            }
        }
    }
    for(auto it=path.rbegin();it!=path.rend();it++)cout<<*it<<" ";
    
    return 0;
}
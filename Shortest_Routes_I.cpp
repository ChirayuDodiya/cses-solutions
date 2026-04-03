#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>adj(n+1);
    vector<ll>dist(n+1,1e15);
    for(ll i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    dist[1]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    q.push({0,1});
    while(!q.empty())
    {
        ll d=q.top().first;
        ll node=q.top().second;
        q.pop();
        if(d>dist[node])continue;
        for(auto it:adj[node])
        {
            ll nei=it.first;
            ll w=it.second;
            if(dist[nei]>d+w)
            {
                dist[nei]=d+w;
                q.push({dist[nei],nei});
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}
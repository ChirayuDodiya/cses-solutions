#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<ll>>connection(m);
    vector<vector<ll>>revGraph(n+1);
    for(int i=0;i<m;i++)
    {
        ll a,b,x;
        cin>>a>>b>>x;
        connection[i]={a,b,x};
        revGraph[b].push_back(a);
    }

    vector<bool>canReach(n+1,0);
    canReach[n]=1;
    queue<int>q;
    q.push(n);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto nei:revGraph[node])
        {
            if(!canReach[nei])
            {
                canReach[nei]=1;
                q.push(nei);
            }
        }
    }

    vector<ll>dist(n+1,-1e15);
    dist[1]=0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            ll a=connection[j][0];
            ll b=connection[j][1];
            ll x=connection[j][2];
            if(dist[a]!=-1e15 && dist[a]+x>dist[b])dist[b]=dist[a]+x;
        }
    }
    int prev=dist[n];
    for(int j=0;j<m;j++)
    {
        ll a=connection[j][0];
        ll b=connection[j][1];
        ll x=connection[j][2];
        if(dist[a]!=-1e15 && dist[a]+x>dist[b])
        {
            if(canReach[b])
            {
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }
    cout<<dist[n]<<endl;
    return 0;
}
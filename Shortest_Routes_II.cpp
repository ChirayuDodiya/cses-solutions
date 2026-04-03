    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;

    int main(){
        ll n,m,q;
        cin>>n>>m>>q;
        
        vector<vector<ll>>dist(n+1,vector<ll>(n+1,1e15));

        for(int i=1;i<=n;i++)
        {
            dist[i][i]=0;
        }
        
        for(int j=0;j<m;j++)
        {
            ll a,b,l;
            cin>>a>>b>>l;
            dist[a][b]=min(dist[a][b],l);
            dist[b][a]=min(dist[b][a],l);
        }
        
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(dist[i][k]+dist[k][j]<dist[i][j])dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }

        while(q--)
        {
            ll a,b;
            cin>>a>>b;
            cout<<(dist[a][b]==1e15 ? -1 : dist[a][b])<<endl;
        }
        return 0;
    }
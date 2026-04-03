#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string>grid(n);
    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
    }
    vector<vector<int>>dist(n,vector<int>(m,-5));

    pair<int,int>start;
    
    //multi source bfs
    queue<pair<int,int>>monster;
    queue<pair<int,int>>a;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {

            if(grid[i][j]=='A')
            {
                a.push({i,j});
                dist[i][j]=0;
                start={i,j};
            }
            if(grid[i][j]=='M')
            {
                monster.push({i,j});
                dist[i][j]=-1;
            }
            if(grid[i][j]=='#')
            {
                dist[i][j]=-1;
            }
        }
    }
    while(!a.empty())
    {
        int sz=monster.size();
        for(int i=0;i<sz;i++)
        {
            int s=monster.front().first;
            int t=monster.front().second;
            monster.pop();

            int di[]={1,-1,0,0};
            int dj[]={0,0,1,-1};
            
            for(int j=0;j<4;j++)
            {
                int newi=s+di[j];
                int newj=t+dj[j];
                if(newi<0 || newi>=n || newj<0 || newj>=m)continue;
                if(dist[newi][newj]==-5)
                {
                    dist[newi][newj]=-1;
                    monster.push({newi,newj});
                }
            }
        }

        sz=a.size();
        for(int i=0;i<sz;i++)
        {
            int s=a.front().first;
            int t=a.front().second;
            a.pop();

            int di[]={1,-1,0,0};
            int dj[]={0,0,1,-1};
            
            for(int j=0;j<4;j++)
            {
                int newi=s+di[j];
                int newj=t+dj[j];
                if(newi<0 || newi>=n || newj<0 || newj>=m)continue;
                if(dist[newi][newj]==-5)
                {
                    dist[newi][newj]=dist[s][t]+1;
                    a.push({newi,newj});
                }
            }

        }
    }
    pair<int,int>end={-1,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i==0 || j==0 || i==n-1 || j==m-1) && dist[i][j]>=0)
            {
                end={i,j};
            }
        }
    }
    if(end.first==-1 && end.second==-1)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    int maxDist=dist[end.first][end.second];
    string ans;

    while(start!=end)
    {
        int di[]={1,-1,0,0};
        int dj[]={0,0,1,-1};
        char move[]={'U','D','L','R'};
            
        for(int j=0;j<4;j++)
        {
            int newi=end.first+di[j];
            int newj=end.second+dj[j];
            if(newi<0 || newi>=n || newj<0 || newj>=m)continue;
            if(dist[newi][newj]==dist[end.first][end.second]-1)
            {
                ans+=move[j];
                end={newi,newj};
                break;
            }
        }
    }
    reverse(ans.begin(),ans.end());

    cout<<"YES"<<endl;
    cout<<maxDist<<endl;
    cout<<ans<<endl;
    return 0;
}
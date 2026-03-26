#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    int ai,aj,bi,bj;
    ai=aj=bi=bj=-1;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            grid[i][j]=s[j];
            if(s[j]=='A')
            {
                ai=i;
                aj=j;
            }
            if(s[j]=='B')
            {
                bi=i;
                bj=j;
            }
        }
    }
    vector<vector<int>>dist(n,vector<int>(m,1e7));
    dist[ai][aj]=0;

    queue<pair<int,int>>bfsTrack;
    bfsTrack.push({ai,aj});

    while(!bfsTrack.empty())
    {
        int size=bfsTrack.size();
        for(int i=0;i<size;i++)
        {
            auto it=bfsTrack.front();
            bfsTrack.pop();
            int x=it.first;
            int y=it.second;

            int dx[]={-1,1,0,0};
            int dy[]={0,0,1,-1};
            for(int j=0;j<4;j++)
            {
                int newx=x+dx[j];
                int newy=y+dy[j];
                if(newx>=0 && newx<n && newy>=0 && newy<m && dist[newx][newy]==1e7 && (grid[newx][newy]=='.' || grid[newx][newy]=='B'))
                {
                    dist[newx][newy]=dist[x][y]+1;
                    bfsTrack.push({newx,newy});
                }
            }
        }
    }

    if(dist[bi][bj]==1e7)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<dist[bi][bj]<<endl;

    //check all 4 directions if dist is curr-1 then add in path
    string path;
    while(!(bi==ai && bj==aj))
    {
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        char direction[]={'D','U','L','R'};
        for(int j=0;j<4;j++)
        {
            int newx=bi+dx[j];
            int newy=bj+dy[j];
            if(newx>=0 && newx<n && newy>=0 && newy<m && (dist[newx][newy]==dist[bi][bj]-1))
            {
                bi=newx;
                bj=newy;
                path+=direction[j];
                break;
            }
        }
    }
    reverse(path.begin(),path.end());
    cout<<path<<endl;


    return 0;
}
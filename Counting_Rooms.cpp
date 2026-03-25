#include <bits/stdc++.h>
using namespace std;

void dfs(int i,int j,int n,int m,vector<vector<char>>&grid,vector<vector<bool>>&vis)
{
    vis[i][j]=1;
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    for(int k=0;k<4;k++)
    {   
        int newi=i+dx[k];
        int newj=j+dy[k];

        if(newi>=0 && newi<n && newj>=0 && newj<m && grid[newi][newj]=='.' && vis[newi][newj]==0)
        dfs(newi,newj,n,m,grid,vis);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            grid[i][j]=s[j];
        }
    }

    int ans=0;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j])
            {
                if(grid[i][j]=='.')
                {
                    ans++;
                    dfs(i,j,n,m,grid,vis);
                }
            }
            vis[i][j]=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
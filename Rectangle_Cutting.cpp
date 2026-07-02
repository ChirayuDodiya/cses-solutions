#include <bits/stdc++.h>
using namespace std;

// recursive method
// int recursion(int n,int m,vector<vector<int>>&dp){
//     //base case
//     if(n==m)return 0;
//     if(n==1 || m==1)return max(n,m)-1;
//     if(dp[n][m]!=-1)return dp[n][m];

//     //recursion
//     int cut=1e9;

//     for(int i=1;i<=n/2;i++)
//     {
//         cut=min(cut,1+recursion(i,m,dp)+recursion(n-i,m,dp));
//     }
//     for(int j=1;j<=m/2;j++)
//     {
//         cut=min(cut,1+recursion(n,j,dp)+recursion(n,m-j,dp));
//     }
//     return dp[n][m]=cut;

// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//     cout<<recursion(n,m,dp)<<endl;
//     return 0;
// }

// iterative method

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=2;i<n+1;i++)
    {
        dp[i][1]=i-1;
    }

    for(int j=2;j<m+1;j++)
    {
        dp[1][j]=j-1;
    }

    for(int ii=2;ii<n+1;ii++)
    {
        for(int jj=2;jj<m+1;jj++)
        {
            if(ii==jj)continue;
            int cut=1e9;
            for(int i=1;i<=ii/2;i++)
            {
                cut=min(cut,1+dp[i][jj]+dp[ii-i][jj]);
            }
            for(int j=1;j<=jj/2;j++)
            {
                cut=min(cut,1+dp[ii][j]+dp[ii][jj-j]);
            }
            dp[ii][jj]=cut;
        }
    }
    cout<<dp[n][m];
    return 0;
}
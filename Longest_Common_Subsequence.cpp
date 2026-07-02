#include <bits/stdc++.h>
using namespace std;

// int recursion(int i,int j,int n,int m,vector<int>&nn,vector<int>&mm,vector<vector<int>>&dp)
// {
//     //base case
//     if(i==n || j==m)return 0;
//     if(dp[i][j]!=-1)return dp[i][j];

//     //recursion
//     int ans=0;

//     if(nn[i]==mm[j])
//     {
//         ans=max(ans,1+recursion(i+1,j+1,n,m,nn,mm,dp));
//     }
//     else
//     {
//         ans=
//         max({
//             ans,
//             recursion(i+1,j,n,m,nn,mm,dp),
//             recursion(i,j+1,n,m,nn,mm,dp)});
//     }
//     return dp[i][j]=ans;

// }

// int main(){
//     int n,m;
//     cin>>n>>m;

//     vector<int>nn(n);
//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         nn[i]=input;
//     }

//     vector<int>mm(m);
//     for(int i=0;i<m;i++)
//     {
//         int input;
//         cin>>input;
//         mm[i]=input;
//     }

//     vector<vector<int>>dp(n,vector<int>(m,-1));

//     cout<<recursion(0,0,n,m,nn,mm,dp)<<endl;

//     int curr=dp[0][0];
//     int i=0;
//     int j=0;
//     vector<int>lcs;

//     while(curr)
//     {
//         while(i<n-1 && dp[i+1][j]==curr) i++;
//         while(j<m-1 && dp[i][j+1]==curr) j++;
//         lcs.push_back(mm[j]);
//         i++;j++; // because the next element can't be from same index
//         curr--;
//     }
//     for(auto it:lcs)cout<<it<<" ";
//     cout<<endl;
//     cout<<"  ";
//     return 0;
// }

int main(){
    int n,m;
    cin>>n>>m;

    vector<int>nn(n);
    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        nn[i]=input;
    }

    vector<int>mm(m);
    for(int i=0;i<m;i++)
    {
        int input;
        cin>>input;
        mm[i]=input;
    }

    vector<vector<int>>dp(n,vector<int>(m,0));

    //match 0th index of n with all index of m

    dp[0][0]= nn[0]==mm[0];

    for(int i=1;i<n;i++)
    {
        dp[i][0]=(dp[i-1][0] | (nn[i]==mm[0]));
    }

    for(int j=1;j<m;j++)
    {
        dp[0][j]=(dp[0][j-1] | (nn[0]==mm[j]));
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(nn[i]==mm[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[n-1][m-1]<<endl;

    int curr=dp[n-1][m-1];
    vector<int>lcs;
    int i=n-1;
    int j=m-1;

    while(curr)
    {
        while(i>0 && dp[i-1][j]==curr)i--;
        while(j>0 && dp[i][j-1]==curr)j--;
        lcs.push_back(mm[j]);
        i--;j--;curr--;
    }

    reverse(lcs.begin(),lcs.end());
    for(auto it:lcs)cout<<it<<" ";

    return 0;
}
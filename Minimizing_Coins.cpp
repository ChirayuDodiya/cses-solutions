#include <bits/stdc++.h>
#define int long long

using namespace std;

// recursive method ----------------------------------------------
// will give null output for some cases because the recursion depth is too high so it will cause stack overflow
// int recursion(int n,int sum,vector<int>&coin,vector<vector<int>>&dp)
// {
//     //base case
//     if(sum==0) return 0;
//     if(n<0)return 1e9;
//     if(dp[n][sum]!=-1)return dp[n][sum];

//     //recursion
//     int count=1e9;
    
//     //call next coin
//     count = min(count,recursion(n-1,sum,coin,dp));

//     //use current coin
//     if(sum>=coin[n])
//     count = min(count,1+recursion(n,sum-coin[n],coin,dp));

//     return dp[n][sum]=count;
// }

// int32_t main(){
//     int n,sum;
//     cin>>n>>sum;

//     vector<int>coin;
//     for(int i=0;i<n;i++)
//     {
//         int ip;
//         cin>>ip;
//         coin.push_back(ip);
//     }

//     vector<vector<int>>dp(n,vector<int>(sum+1,-1));
//     int minCoin=recursion(n-1,sum,coin,dp);
//     cout<<(minCoin==1e9 ? -1 : minCoin)<<endl;

//     return 0;
// }


// iterative method ----------------------------------------------
// will give null output for some cases because the dp table is too huge and will throw MLE or in some cases if it can't assign that much memory then it returns null output 
// int32_t main(){
//     int n,sum;
//     cin>>n>>sum;

//     vector<int>coin;
//     for(int i=0;i<n;i++)
//     {
//         int ip;
//         cin>>ip;
//         coin.push_back(ip);
//     }
//     vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    
//     for(int s=1;s<sum+1;s++)
//     {
//         dp[0][s]=1e9;
//     }
    
//     for(int i=1;i<n+1;i++)
//     {
//         for(int s=1;s<sum+1;s++)
//         {
//             dp[i][s]=dp[i-1][s];
//             if(s-coin[i-1]>=0)dp[i][s]=min(dp[i][s],1+dp[i][s-coin[i-1]]);
//         }
//     }

//     cout<<(dp[n][sum]==1e9 ? -1 : dp[n][sum])<<endl;
//     return 0;
// }

// memory optimize method ----------------------------------------
int32_t main(){
    int n,sum;
    cin>>n>>sum;

    vector<int>coin;
    for(int i=0;i<n;i++)
    {
        int ip;
        cin>>ip;
        coin.push_back(ip);
    }

    // vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    vector<int>curr(sum+1,0);
    vector<int>prev(sum+1,0);
    
    for(int s=1;s<sum+1;s++)
    {
        prev[s]=1e9;
    }
    
    for(int i=1;i<n+1;i++)
    {
        for(int s=1;s<sum+1;s++)
        {
            curr[s]=prev[s];
            if(s-coin[i-1]>=0)curr[s]=min(curr[s],1+curr[s-coin[i-1]]);
        }
        prev=curr;
    }

    cout<<(curr[sum]==1e9 ? -1 : curr[sum])<<endl;
    return 0;
}
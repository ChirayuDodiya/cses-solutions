#include <bits/stdc++.h>
#define int long long
int mod = 1e9+7;
using namespace std;

// recursive method ----------------------------------------------
// this will give null output because of stack overflow

// int recursion(int n,int sum,vector<int>&coins,vector<vector<int>>&dp){
//     //base case
//     if(sum==0)return 1;
//     if(n<0)return 0;
//     if(dp[n][sum]!=-1)return dp[n][sum];
//     // recursion
//     int count=0;

//     //go to next coin
//     count+=recursion(n-1,sum,coins,dp);
//     if(count>=mod)count-=mod;

//     // use and stick to current coin
//     if(sum>=coins[n])count+=recursion(n,sum-coins[n],coins,dp);
//     if(count>=mod)count-=mod;

//     return dp[n][sum]=count;
// }

// int32_t main(){
//     int n,sum;
//     cin>>n>>sum;
//     vector<int>coins(n);
//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         coins[i]=input;
//     }

//     vector<vector<int>>dp(n,vector<int>(sum+1,-1));

//     cout<<recursion(n-1,sum,coins,dp);

//     return 0;
// }


// iterative method ----------------------------------------------
// this will give empty output because it is impossible to allocate this much amount of space
// int main(){
//     int n,sum;
//     cin>>n>>sum;
//     vector<int>coins(n);
//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         coins[i]=input;
//     }
//     vector<vector<int>>dp(n+1,vector<int>(sum+1,0));

//     for(int i=0;i<n+1;i++)
//     {
//         dp[i][0]=1;
//     }

//     for(int i=1;i<=n;i++)
//     {
//         for(int s=1;s<sum+1;s++)
//         {
//             dp[i][s]=dp[i-1][s];
//             if(dp[i][s]>=mod)dp[i][s]-=mod;

//             if(s>=coins[i-1])dp[i][s]+=dp[i][s-coins[i-1]];
//             if(dp[i][s]>=mod)dp[i][s]-=mod;
//         }
//     }
//     cout<<dp[n][sum]<<endl;
//     return 0;
// }

// memory optimize method ----------------------------------------
int32_t main(){
    int n,sum;
    cin>>n>>sum;
    vector<int>coins(n);
    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        coins[i]=input;
    }
    vector<int>prev(sum+1,0);
    vector<int>curr(sum+1,0);

    prev[0]=1;curr[0]=1;
    
    for(int i=1;i<=n;i++)
    {
        for(int s=1;s<sum+1;s++)
        {
            curr[s]=prev[s];
            if(curr[s]>=mod)curr[s]-=mod;

            if(s>=coins[i-1])curr[s]+=curr[s-coins[i-1]];
            if(curr[s]>=mod)curr[s]-=mod;
        }
        prev=curr;
    }
    cout<<curr[sum]<<endl;
    return 0;
}

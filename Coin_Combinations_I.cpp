#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

// recursive method ----------------------------------------------
// int recursion(int sum,vector<int>&coins,vector<int>&dp)
// {
//     //base case
//     if(sum==0)return 1;
//     if(dp[sum]!=-1)return dp[sum];

//     //recursion
//     int count=0;
//     for(auto coin:coins)
//     {
//         if(sum>=coin)count+=recursion(sum-coin,coins,dp);
//         count%=mod;
//     }
//     return dp[sum]=count;
// }

// int32_t main(){
//     int n,sum;
//     cin>>n>>sum;

//     vector<int>coins;
//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         coins.push_back(input);
//     }

//     vector<int>dp(sum+1,-1);

//     sort(coins.begin(),coins.end(),greater<int>());

//     cout<<recursion(sum,coins,dp)<<endl;
//     return 0;
// }


// iterative method ----------------------------------------------
int32_t main(){
    int n,sum;
    cin>>n>>sum;

    vector<int>coins;
    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        coins.push_back(input);
    }

    vector<int>dp(sum+1,0);
    dp[0]=1;

    sort(coins.begin(),coins.end()); //optimization 1

    for(int s=1;s<sum+1;s++)
    {
        for(auto coin:coins)
        {
            if(s<coin)break;//optimization 1
            dp[s]+=dp[s-coin];
            if(dp[s]>=mod)dp[s]-=mod;
        }
    }
    cout<<dp.back()<<endl;
    return 0;
}
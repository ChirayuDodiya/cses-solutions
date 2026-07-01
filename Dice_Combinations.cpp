#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod=1e9+7;

// recursive method ----------------------------------------------

// int recursion(int n,vector<int>&dp)
// {
//     //base case
//     if(n==0)return 1;
//     if(dp[n]!=-1)return dp[n];

//     //recursion
//     int count=0;
//     for(int move=1;move<=6;move++)
//     {
//         if(n-move>=0)
//         {
//             count+=recursion(n-move,dp);
//             count%=mod;
//         }
//     }
//     return dp[n]=count%mod;
// }

// int32_t main(){
//     int n;
//     cin>>n;

//     vector<int>dp(n+1,-1);
//     cout<<recursion(n,dp)<<endl;
//     return 0;
// }

// iterative method ----------------------------------------------

int32_t main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    dp[0]=1;

    for(int num=1;num<=n;num++)
    {
        for(int move=1;move<=6;move++)
        {
            if(num-move>=0)dp[num]+=dp[num-move];
            dp[num]%=mod;
        }
    }
    cout<<dp.back();
    return 0;
}
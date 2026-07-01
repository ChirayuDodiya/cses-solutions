#include <bits/stdc++.h>
#define int long long

using namespace std;

// recursive method ----------------------------------------------
// int recursion(int n,vector<int>&dp)
// {
//     //base case
//     if(n==0)return 0;
//     if(dp[n]!=-1)return dp[n];

//     //recursion
//     vector<bool>digit(10,0);
//     int copy=n;
//     while(copy)
//     {
//         digit[copy%10]=1;
//         copy/=10;
//     }

//     int steps=1e7;

//     for(int i=1;i<10;i++)
//     {
//         if(digit[i])steps=min(steps,1+recursion(n-i,dp));
//     }
//     return dp[n]=steps;
// }

// int32_t main(){
//     int n;
//     cin>>n;
//     vector<int>dp(n+1,-1);
//     cout<<recursion(n,dp)<<endl;
//     return 0;
// }


// iterative method ----------------------------------------------

// int32_t main(){
//     int n;
//     cin>>n;
//     vector<int>dp(n+1,0);

//     for(int i=1;i<n+1;i++)
//     {
//         //find all digit for i
//         vector<bool>digit(10,0);
//         int copy=i;
//         while(copy)
//         {
//             digit[copy%10]=1;
//             copy/=10;
//         }

//         int steps=1e7;

//         for(int d=1;d<10;d++)
//         {
//             if(digit[d])steps=min(steps,1+dp[i-d]);
//         }
//         dp[i]=steps;
//     }
//     cout<<dp[n]<<endl;
//     return 0;
// }

// memory optimized
int32_t main(){
    int n;
    cin>>n;
    vector<int>dp(10,0);

    for(int i=1;i<n+1;i++)
    {
        dp[i%10]=0;
        int steps=1e7;
        int copy=i;
        while(copy)
        {
            if(copy%10)steps=min(steps,1+dp[(i-(copy%10))%10]);
            copy/=10;
        }

        dp[i%10]=steps;
    }
    cout<<dp[n%10]<<endl;
    return 0;
}
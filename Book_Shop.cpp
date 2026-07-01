#include <bits/stdc++.h>
#define int long long
using namespace std;

// recursive method ----------------------------------------------

// int recursion(int n,int m,vector<vector<int>>&dp,vector<int>&price,vector<int>&page)
// {
//     //base case
//     if(m==0 || n<0)return 0;
//     if(dp[n][m]!=-1)return dp[n][m];
    
//     //recursion
//     int pageCount=0;
    
//     //take this book
//     if(m>=price[n])pageCount = max(pageCount,page[n]+recursion(n-1,m-price[n],dp,price,page));
    
//     //skip this book
//     pageCount=max(pageCount,recursion(n-1,m,dp,price,page));

//     return dp[n][m]=pageCount;
// }

// int32_t main(){
//     int n,m;
//     cin>>n>>m;
//     vector<int>price(n);
//     vector<int>page(n);

//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         price[i]=input;
//     }

//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         page[i]=input;
//     }

//     vector<vector<int>>dp(n,vector<int>(m+1,-1));

//     cout<<recursion(n-1,m,dp,price,page)<<endl;

//     return 0;
// }

// iterative method ----------------------------------------------

// int32_t main(){
//     int n,m;
//     cin>>n>>m;
//     vector<int>price(n);
//     vector<int>page(n);

//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         price[i]=input;
//     }

//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         page[i]=input;
//     }
    
//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//     //if m<0 || n<0 then return 0;
//     for(int i=1;i<n+1;i++)
//     {
//         for(int j=1;j<m+1;j++)
//         {
//             // take
//             if(j>=price[i-1])dp[i][j]=page[i-1]+dp[i-1][j-price[i-1]];
//             // skip 
//             dp[i][j]=max(dp[i][j],dp[i-1][j]);
//         }
//     }
//     cout<<dp[n][m];

//     return 0;
// }

// memory optimized method
int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<int>price(n);
    vector<int>page(n);

    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        price[i]=input;
    }

    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        page[i]=input;
    }
    
    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    vector<int>prev(m+1,0);
    
    //if m<0 || n<0 then return 0;
    for(int i=1;i<n+1;i++)
    {
        vector<int>curr(m+1,0);
        for(int j=1;j<m+1;j++)
        {
            // take
            if(j>=price[i-1])curr[j]=page[i-1]+prev[j-price[i-1]];
            //skip
            curr[j]=max(curr[j],prev[j]);
        }
        prev=curr;
    }
    cout<<prev[m];

    return 0;
}
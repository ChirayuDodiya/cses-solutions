#include<bits/stdc++.h>
#define int long long
int NEG=-1e16;
using namespace std;

// recursive method

// int recursion(int left,int right,vector<int>&arr,vector<vector<int>>&dp)
// {
//     //base case
//     if(left==right)return arr[left];
//     if(dp[left][right]!=NEG)return dp[left][right];

//     //recursion
//     int ans=NEG;
//     //take from left
//     ans=max(ans,arr[left]-recursion(left+1,right,arr,dp));
//     //take from right
//     ans=max(ans,arr[right]-recursion(left,right-1,arr,dp));

//     return dp[left][right]=ans;
// }

// int32_t main(){
//     int n;
//     cin>>n;

//     vector<int>arr(n);
//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         arr[i]=input;
//     }

//     vector<vector<int>>dp(n,vector<int>(n,NEG));

//     int diff=recursion(0,n-1,arr,dp);

//     int sum=0;
//     for(auto it:arr)sum+=it;

//     cout<<(sum+diff)/2<<endl;
//     return 0;
// }

//iterative method

int32_t main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        arr[i]=input;
    }

    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int i=0;i<n;i++)
    {
        dp[i][i]=arr[i];
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            if(i==j)continue;
            dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
        }
    }

    int diff=dp[0][n-1];
    int sum=0;
    for(auto it:arr)sum+=it;

    cout<<(sum+diff)/2<<endl;
    return 0;
}
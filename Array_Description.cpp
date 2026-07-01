#include <bits/stdc++.h>
using namespace std;

int mod=1e9+7;
// recursive method
int recursion(int index,int prev,int n,int m,vector<int>&arr,vector<vector<int>>&dp)
{
    //base case
    if(index==n)
    {
       return 1;
    }
    if(dp[index][prev]!=-1)return dp[index][prev];

    //recursion
    int count=0;
    if(index==0)
    {
        if(arr[index]==0)
        {
            for(int i=1;i<=m;i++)
            {
                count+=recursion(index+1,i,n,m,arr,dp);
                count%=mod;
            }
        }
        else
        {
            count+=recursion(index+1,arr[index],n,m,arr,dp);
            count%=mod;
        }
    }
    else
    {
        if(arr[index]==0)
        {
            for(int i=max(1,prev-1);i<=min(m,prev+1);i++)
            {
                count+=recursion(index+1,i,n,m,arr,dp);
                count%=mod;
            }
        }
        else
        {
            if(abs(prev-arr[index])>1)return 0;
            count+=recursion(index+1,arr[index],n,m,arr,dp);
            count%=mod;
        }
    }
    return dp[index][prev]=count;
    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        arr[i]=input;
    }

    vector<vector<int>>dp(n,vector<int>(m+1,-1));

    cout<<recursion(0,0,n,m,arr,dp);
    return 0;
}
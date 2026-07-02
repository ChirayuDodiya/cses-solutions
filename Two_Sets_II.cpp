#include <bits/stdc++.h>
using namespace std;
int MOD=1e9+7;

long long power_mod(long long base,long long power)
{
    long long curr=1;
    while(power)
    {
        if(power%2)curr*=base;
        base*=base;
        curr%=MOD;
        base%=MOD;
        power=power>>1;
    }
    return curr;
}

// recursive method

// int recursion(int value,int target,vector<vector<int>>&dp)
// {
//     //base case
//     if(target==0)return 1;
//     if(value==0)return 0;

//     if(dp[value][target]!=-1)return dp[value][target];

//     //recursion
//     int count=0;
    
//     //take this value
//     if(target>=value)count+=recursion(value-1,target-value,dp);
//     count%=MOD;

//     //skip this value
//     count+=recursion(value-1,target,dp);
//     count%=MOD;

//     return dp[value][target]=count;
// }

// int main(){
//     int n;
//     cin>>n;
//     int total=(n*(n+1))/2;
//     if(total%2)
//     {
//         cout<<"0"<<endl;
//         return 0;
//     }

//     int target= total/2;

//     vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

//     // cout<<recursion(n-1,target,dp)<<endl;
    
//     /*
//     if you call recursion(n,target,dp) it will count all partition twice;
//     because for n=7 
//     1) {1,3,4,6} and {2,5,7}
//     2) {2,5,7} and {1,3,4,6}

//     so if i get left pair, one of them have n =7 and another doesn't,so call 
//     recursion(n-1,target,dp)
//     */

//     int doubleCount=recursion(n,target,dp);
//     int invMod=power_mod(2,MOD-2);

//     cout<<(1LL*doubleCount*invMod)%MOD<<endl;

//     return 0;
// }

// iterative method

int main(){
    int n;
    cin>>n;
    int total=(n*(n+1))/2;
    if(total%2)
    {
        cout<<"0"<<endl;
        return 0;
    }

    int target= total/2;

    vector<int>dp(target+1,0);

    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int t=target;t>=0;t--)
        {
            if(t>=i)dp[t]+=dp[t-i];
            dp[t]%=MOD;
        }
    }

    cout<<(dp.back()*power_mod(2,MOD-2))%MOD<<endl;

    return 0;
}

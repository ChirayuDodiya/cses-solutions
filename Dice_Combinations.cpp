#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<ll>dp(n+1,0);
    dp[0]=1;
    
    int mod=1e9+7;

    for(int i=1;i<=n;i++)
    {
        ll curr=0;
        for(int j=1;j<=6;j++)
        {
            if(i-j>=0)curr+=dp[i-j];
            curr%=mod;
        }
        dp[i]=curr;
    }
    cout<<dp[n]<<endl;
    return 0;
    
}
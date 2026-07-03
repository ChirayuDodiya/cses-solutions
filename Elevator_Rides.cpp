#include <bits/stdc++.h>
using namespace std;

/*
bitmask dp
can convert n! time complexity to 2^n if order is not important
so in this case i can reduce complexity from n * n! to n * 2^n
*/

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>w(n);
    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        w[i]=input;
    }
    vector<pair<int,int>>dp(1<<n,{n,0}); //for each mask,store count of all lift upto this point, remaining weight for last lift
    dp[0]={1,x};

    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int i=0;i<n;i++)
        {
            if(!(mask & (1<<i)))continue;

            int prevMask=mask^(1<<i);
            
            int prevLiftCount=dp[prevMask].first;
            int prevRemain=dp[prevMask].second;

            int nextLiftCount= prevLiftCount+(prevRemain<w[i]);
            int nextRemain = (prevRemain<w[i] ? x-w[i] : prevRemain-w[i]);

            int currLiftCount=dp[mask].first;
            int currRemain = dp[mask].second;

            if(currLiftCount>nextLiftCount)
            {
                dp[mask]={nextLiftCount,nextRemain};
            }
            else if(currLiftCount==nextLiftCount && currRemain<nextRemain)
            {
                dp[mask]={nextLiftCount,nextRemain};
            }
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;
    return 0;
}

// pair<int,int> recursion(int mask,int n,int x,vector<int>&w,vector<pair<int,int>>&dp){
//     //base case
//     if(mask==0)return {1,0};
//     if(dp[mask].first!=-1)return dp[mask];

//     //recursion
//     pair<int,int> ans = {n + 1, 0};

//     for(int i=0;i<n;i++)
//     {
//         if(!(mask & (1<<i)))continue;

//         int prevMask = mask ^ (1 << i);

//         pair<int,int> temp = recursion(prevMask,n,x,w,dp);

//         int rides= temp.first;
//         int lastWeight =temp.second;

//         if(lastWeight + w[i] <= x)
//         {
//             lastWeight += w[i];
//         }
//         else
//         {
//             rides++;
//             lastWeight = w[i];
//         }

//         ans = min(ans, {rides, lastWeight});
//     }

//     return dp[mask] = ans;
// }

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int>w(n);
//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         w[i]=input;
//     }
//     vector<pair<int,int>>dp(1<<n,{-1,-1}); //for each mask,store count of all lift upto this point, remaining weight for last lift
//     cout<<recursion((1<<n)-1,n,x,w,dp).first<<endl;
//     return 0;
// }
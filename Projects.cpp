#include<bits/stdc++.h>
using namespace std;
#define int long long

// bool compare(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b)
// {
//     // sort by end time asc
//     return a.first.second < b.first.second;
// }

// int32_t main(){
//     int n;
//     cin>>n;

//     vector<pair<pair<int,int>,int>>vpp(n);

//     for(int i=0;i<n;i++)
//     {
//         int s,e,m;
//         cin>>s>>e>>m;
//         vpp[i]={{s,e},m};
//     }
//     sort(vpp.begin(),vpp.end(),compare);

//     vector<int>dp(n,0);

//     dp[0]=vpp[0].second;

//     for(int i=1;i<n;i++)
//     {
//         // use previous value
//         dp[i]=dp[i-1];

//         // use current value and also find which previous value you can take
//         int take=vpp[i].second;
//         int startDate=vpp[i].first.first;

//         int low=0;
//         int high=i-1;

//         while(low<=high)
//         {
//             int mid=low+(high-low)/2;
//             if(vpp[mid].first.second<startDate)
//             {
//                 low=mid+1;
//             }
//             else high=mid-1;
//         }

//         if(high>=0)take+=dp[high];
//         dp[i]=max(dp[i],take);
//     }
//     cout<<dp.back()<<endl;
//     return 0;
// }


bool compare(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b)
{
    // sort by start time
    return a.first.first < b.first.first;
}

int recursion(int index,int n,vector<pair<pair<int,int>,int>>&vpp,vector<int>&dp){
    // base case
    if(index==n)return 0;
    if(dp[index]!=-1)return dp[index];

    // recursion
    int ans=0;

    // skip this index
    ans=max(ans,recursion(index+1,n,vpp,dp));

    // take current index and call next possible index
    int lastDate = vpp[index].first.second; //find upper bound of this index
    int low=index+1;
    int high=n-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(vpp[mid].first.first>lastDate)high=mid-1;
        else low=mid+1;
    }
    ans=max(ans,vpp[index].second + recursion(low,n,vpp,dp));

    return dp[index]=ans;
}

int32_t main(){
    int n;
    cin>>n;

    vector<pair<pair<int,int>,int>>vpp(n);

    for(int i=0;i<n;i++)
    {
        int s,e,m;
        cin>>s>>e>>m;
        vpp[i]={{s,e},m};
    }
    sort(vpp.begin(),vpp.end(),compare);

    vector<int>dp(n,-1);

    cout<<recursion(0,n,vpp,dp)<<endl;
    return 0;
}
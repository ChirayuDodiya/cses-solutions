#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;

// int main(){
//     int n;
//     cin>>n;
//     vector<string>grid;
//     for(int i=0;i<n;i++)
//     {
//         string temp;
//         cin>>temp;
//         grid.push_back(temp);
//     }

//     vector<vector<int>>dp(n,vector<int>(n,0));

//     dp[0][0]= grid[0][0]=='.' ? 1 : 0;

//     for(int i=1;i<n;i++)
//     {
//         dp[i][0]= (dp[i-1][0] && grid[i][0]=='.');
//     }

//     for(int j=1;j<n;j++)
//     {
//         dp[0][j]= (dp[0][j-1] && grid[0][j]=='.');
//     }


//     for(int i=1;i<n;i++)
//     {
//         for(int j=1;j<n;j++)
//         {
//             if(grid[i][j]=='*')continue;
//             dp[i][j]=dp[i-1][j]+dp[i][j-1];
//             dp[i][j]%=mod;
//         }
//     }

//     cout<<dp[n-1][n-1]<<endl;
//     return 0;
// }


// memory optimized

int main(){
    int n;
    cin>>n;
    vector<string>grid;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        grid.push_back(temp);
    }

    vector<int>prev(n,0);
    
    prev[0]=(grid[0][0]=='.' ? 1 : 0);
    
    for(int j=1;j<n;j++)
    {
        prev[j]= (prev[j-1] && grid[0][j]=='.');
    }
    
    
    for(int i=1;i<n;i++)
    {
        vector<int>curr(n,0);
        curr[0]=(prev[0] && grid[i][0]=='.');
        for(int j=1;j<n;j++)
        {
            if(grid[i][j]=='*')continue;
            curr[j]=prev[j]+curr[j-1];
            curr[j]%=mod;
        }
        prev=curr;
    }

    cout<<prev[n-1]<<endl;
    return 0;
}
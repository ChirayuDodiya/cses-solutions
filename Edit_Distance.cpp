#include<bits/stdc++.h>
using namespace std;

// recursive method
// int recursion(int i,int j,int n,int m,string &s,string &t,vector<vector<int>>&dp)
// {
//     //base case
//     if(i==n && j==m)return 0;
//     if(i==n || j==m)
//     {
//         return max(n-i,m-j);
//     }
//     if(dp[i][j]!=-1)return dp[i][j];

//     //recursion make s -> t
//     int move=1e6;

//     if(s[i]!=t[j])
//     {
//         //add one char
//         move=min(move,1+recursion(i,j+1,n,m,s,t,dp));
        
//         //remove one char
//         move=min(move,1+recursion(i+1,j,n,m,s,t,dp));
        
//         //replace one char
//         move=min(move,1+recursion(i+1,j+1,n,m,s,t,dp));
//     }

//     else move=min(move,recursion(i+1,j+1,n,m,s,t,dp));

//     return dp[i][j]=move;
// }

// int main(){
//     string s;
//     string t;
//     cin>>s>>t;

//     int n=s.length();
//     int m=t.length();

//     vector<vector<int>>dp(n,vector<int>(m,-1));

//     cout<<recursion(0,0,n,m,s,t,dp)<<endl;

//     return 0;
// }

// iterative method

// int main(){
//     string s;
//     string t;
//     cin>>s>>t;

//     int n=s.length();
//     int m=t.length();

//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
//     for(int i=0;i<n+1;i++)
//     {
//         dp[i][m]=n-i;
//     }

//     for(int j=0;j<m+1;j++)
//     {
//         dp[n][j]=m-j;
//     }

//     for(int i=n-1;i>=0;i--)
//     {
//         for(int j=m-1;j>=0;j--)
//         {
//             int move=1e6;

//             if(s[i]!=t[j])
//             {
//                 //add one char
//                 move=min(move,1+dp[i][j+1]);
                
//                 //remove one char
//                 move=min(move,1+dp[i+1][j]);
                
//                 //replace one char
//                 move=min(move,1+dp[i+1][j+1]);
//             }

//             else move=min(move,dp[i+1][j+1]);

//             dp[i][j]=move;
//         }
//     }

//     cout<<dp[0][0]<<endl;
//     return 0;
// }

// memory optimize method


int main(){
    string s;
    string t;
    cin>>s>>t;

    int n=s.length();
    int m=t.length();

    vector<int>next(m+1,0);
        
    for(int j=0;j<m+1;j++)
    {
        next[j]=m-j;
    }
    
    for(int i=n-1;i>=0;i--)
    {
        vector<int>curr(m+1,0);

        curr[m]=n-i;
        
        for(int j=m-1;j>=0;j--)
        {
            int move=1e6;

            if(s[i]!=t[j])
            {
                //add one char
                move=min(move,1+curr[j+1]);
                
                //remove one char
                move=min(move,1+next[j]);
                
                //replace one char
                move=min(move,1+next[j+1]);
            }

            else move=min(move,next[j+1]);

            curr[j]=move;
        }
        next=curr;
    }

    cout<<next[0]<<endl;
    return 0;
}
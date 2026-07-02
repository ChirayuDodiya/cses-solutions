#include<bits/stdc++.h>
using namespace std;

// bool recursion(int index,int sum,vector<int>&money,vector<vector<int>>&dp)
// {
//     //base case
//     if(sum==0)return true;
//     if(index<0)return false;
//     if(dp[index][sum]!=-1)return dp[index][sum];

//     //recursion
//     bool pos=false;
//     //take this index 
//     if(sum>=money[index])pos = pos | recursion(index-1,sum-money[index],money,dp);

//     //skip this index
//     pos = pos | recursion(index-1,sum,money,dp);

//     return dp[index][sum]=pos;
// }

// //recursive method
// int main(){
//     int n;
//     cin>>n;
    
//     vector<int>money(n);
//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         money[i]=input;
//     }

//     int sum=0;
//     for(auto val:money)sum+=val;

//     vector<vector<int>>dp(n,vector<int>(sum+1,-1));

//     for(int s=1;s<sum+1;s++)
//     recursion(n-1,s,money,dp);

//     vector<int>p;
//     for(int s=1;s<sum+1;s++)
//     {
//         if(dp[n-1][s]==1)p.push_back(s);
//     }
//     cout<<p.size()<<endl;
//     for(auto it:p)cout<<it<<" ";
//     return 0;
// }

// iterative method

// int main(){
//     int n;
//     cin>>n;
    
//     vector<int>money(n);
//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         money[i]=input;
//     }

//     int sum=0;
//     for(auto val:money)sum+=val;

//     vector<vector<bool>>dp(n+1,vector<bool>(sum+1,0));

//     //index,sum
//     for(int i=0;i<n+1;i++)
//     {
//         dp[i][0]=true;
//     }

//     for(int i=1;i<n+1;i++)
//     {
//         for(int s=1;s<sum+1;s++)
//         {
//             dp[i][s]=dp[i-1][s];
//             if(s>=money[i-1])dp[i][s] = dp[i][s] | dp[i-1][s-money[i-1]];
//             /*
//             0-1 Knapsack:
//             1) make table value one if that given sum is true for previous index and 
//             2) make table value one if previous index is having needsum sum true

//             ex.(using current coin valued 5)

//                         7   12  17  22

//                 1       1   0   0   0
//                 2       1   1   0   0
//             */
            
//             // dp[i][s]=dp[i-1][s];
//             // if(s>=money[i-1])dp[i][s] = dp[i][s] | dp[i][s-money[i-1]];
//             /*
//             Unbounded Knapsack:
//             1) make table value one if that given sum is true for previous index and 
//             2) make table value one if this index is having needsum sum true

//             ex.(using current coin valued 5)

                            
//                         7   12  17  22

//                 1       1   0   0   0
//                 2       1   1   1   1
//              */
//         }
//     }
//     vector<int>p;
//     for(int s=1;s<sum+1;s++)
//     {
//         if(dp[n][s])p.push_back(s);
//     }

//     cout<<p.size()<<endl;
//     for(auto it:p)cout<<it<<" ";
//     return 0;
// }

//memory optimized method

// int main(){
//     int n;
//     cin>>n;
    
//     vector<int>money(n);
//     for(int i=0;i<n;i++)
//     {
//         int input;
//         cin>>input;
//         money[i]=input;
//     }

//     int sum=0;
//     for(auto val:money)sum+=val;

//     vector<bool>dp(sum+1,0);

//     dp[0]=true;

//     for(int i=0;i<n;i++)
//     {
//         // for(int s=1;s<sum+1;s++) // Unbounded Knapsack
//         for(int s=sum;s>=1;s--) // 0-1 Knapsack
//         {
//             if(s>=money[i])dp[s] = dp[s] | dp[s-money[i]];
//         }
//     }

//     vector<int>p;
//     for(int s=1;s<sum+1;s++)
//     {
//         if(dp[s])p.push_back(s);
//     }

//     cout<<p.size()<<endl;
//     for(auto it:p)cout<<it<<" ";
//     return 0;
// }
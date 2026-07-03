#include <bits/stdc++.h>
#define int long long
using namespace std;

int recursion(string &s,int n,int index,int isBound,int prev,int isLeadingZero,int arr[20][2][11][2])
{
    //base case
    if(index==n)
    {
        return 1;
    }
    if(arr[index][isBound][prev+1][isLeadingZero]!=-1)return arr[index][isBound][prev+1][isLeadingZero];

    //recursion
    int count=0;
    int limit = (isBound==1 ? s[index]-'0' : 9);

    for(int i=0;i<=limit;i++)
    {
        if((i==prev && i!=0) || (i==0 && isLeadingZero==0 && i==prev))continue;
        count+=recursion(s,n,index+1,(isBound & i==s[index]-'0'),i,(isLeadingZero & (i==0)),arr);
    }
    return arr[index][isBound][prev+1][isLeadingZero]=count;
}


int solve(string &s){
    
    //index,isbound,prev,isLeadingZero
    int arr[20][2][11][2];
    memset(arr,-1,sizeof(arr));
    int n=s.length();
    return recursion(s,n,0,1,-1,1,arr);
    
}

int32_t main(){
    int a,b;
    cin>>a>>b;
    
    string as=to_string(a-1);
    string bs=to_string(b);
    
    cout<<solve(bs)-solve(as)<<endl;

    return 0;
}
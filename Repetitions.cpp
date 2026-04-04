#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int curr=1;
    int ans=1;

    int n=s.length();
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])curr++;
        else {
            ans=max(ans,curr);
            curr=1;
        }
    }
    ans=max(ans,curr);
    cout<<ans<<endl;
    return 0;
}
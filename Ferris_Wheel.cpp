#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>gondolas(n);
    for(int i=0;i<n;i++)cin>>gondolas[i];

    sort(gondolas.begin(),gondolas.end());

    int i=0;
    int j=n-1;
    int ans=0;

    while(i<j)
    {
        if(gondolas[i]+gondolas[j]>x)
        {
            ans++;
            j--;
        }
        else if(gondolas[i]+gondolas[j]<=x)
        {
            ans++;
            i++;
            j--;
        }
    }
    if(i==j)ans++;
    cout<<ans<<endl;
    return 0;
}
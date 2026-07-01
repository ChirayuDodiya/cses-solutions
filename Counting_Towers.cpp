#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;

int32_t main(){
    int t;
    cin>>t;
    vector<int>test(t);
    for(int i=0;i<t;i++)
    {
        int input;
        cin>>input;
        test[i]=input;
    }

    vector<pair<int,int>>vpp(1e6+1);

    vpp[1]={1,1};
    
    for(int i=2;i<=1e6;i++)
    {
        vpp[i]=
        {(vpp[i-1].first*4)%mod + (vpp[i-1].second*1)%mod,
            (vpp[i-1].first)%mod +(vpp[i-1].second*2)%mod};
    }

    for(auto it:test)
    {
        cout<<(vpp[it].first+vpp[it].second)%mod<<endl;
    }
    return 0;
}

/*
for 2 x (width = 1) column tower  = there are 5 possiblities
1) continue left tower and start right tower
2) continue right tower and start right tower
3) continue both towers
4) start both towers (width = 1)
5) start both towers as a single combined tower (width = 2)

for 1 x (width = 2) column tower = there are 3 possiblities
1) continue both towers as a single combined tower
2) start both towers as a single combined tower (width = 2)
3) start both towers (width = 1)

*/
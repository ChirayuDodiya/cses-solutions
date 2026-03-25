#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin >> n;

    cout<<n<<" ";
    
    if(n==1)return 0;
    
    while(true)
    {
        n%2==0 ? n/=2 : n=(3*n)+1;
        cout<<n<<" ";
        if(n==1)return 0;
    }
}
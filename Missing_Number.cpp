#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>list(n);
    for(int i=0;i<n-1;i++)
    {
        cin>>list[i];
    }
    list[n-1]=0;
    sort(list.begin(),list.end());
    for(int i=0;i<n;i++)
    {
        if(list[i]!=i)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    if(list[n-1]!=n)cout<<n<<endl;
    return 0;
}   
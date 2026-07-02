#include<bits/stdc++.h>
using namespace std;

// recursive and iterative approach will take n^2,and also no need to print that sequence,
// so to just find max len, we can use a below method which takes n log n

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        arr[i]=input;
    }

    vector<int>is;

    for(auto num:arr)
    {
        if(is.empty() || lower_bound(is.begin(),is.end(),num)==is.end())
        {
            is.push_back(num);
        }

        else is[lower_bound(is.begin(),is.end(),num)-is.begin()]=num;
    }

    cout<<is.size()<<endl;
    return 0;
}
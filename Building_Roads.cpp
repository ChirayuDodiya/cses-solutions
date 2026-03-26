#include <bits/stdc++.h>
using namespace std;

class DSU{
private:
    vector<int>parent;
    vector<int>size;
public:
    DSU(int n){
        for(int i=0;i<=n;i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int find_parent(int node){
        if(parent[node]==node)return node;
        return parent[node]=find_parent(parent[node]);
    }
    void connect_node(int node1,int node2){
        int p1=find_parent(node1);
        int p2=find_parent(node2);
        if(p1==p2)return;
        if(size[p1]>size[p2])
        {
            parent[p2]=p1;
            size[p1]+=size[p2];
        }
        else
        {
            parent[p1]=p2;
            size[p2]+=size[p1];
        }
    }
    void build_extra_bridge(int n){
        set<int>st;
        for(int i=1;i<=n;i++)
        {
            st.insert(find_parent(i));
        }
        vector<int>v(st.begin(),st.end());
        int sz=v.size();
        cout<<sz-1<<endl;
        for(int i=0;i<sz-1;i++)
        {
            cout<<v[i]<<" "<<v[i+1]<<endl;
        }
    }
};

int main(){
    int c,r;
    cin>>c>>r;
    DSU d(c);
    
    for(int i=0;i<r;i++)
    {
        int u,v;
        cin>>u>>v;
        d.connect_node(u,v);
    }
    d.build_extra_bridge(c);
    return 0;
}
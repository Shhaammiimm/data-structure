#include<bits/stdc++.h>
using namespace std;
const int N=2e5+12;
class dsu{
  vector<int>sz,par;
  public:
      dsu(int n){
        sz.resize(n+1);
        par.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
            sz[i]=1;
        }
      }

      int find(int v){
      if(v==par[v])return v;
      return par[v]=find(par[v]);//path compression
      }

      void Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
        if(sz[a]<sz[b])swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];//union by size
        }
      }
};
int main(){
    int n,k;cin>>n>>k;
    dsu ds(n);
    for(int i=0;i<k;i++){
        int u,v;cin>>u>>v;
        ds.Union(u,v);
    }
    //connected components
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i==ds.find(i))ans++;
    }
    cout<<ans;
}

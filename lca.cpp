#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define hello() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define nl "\n"
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ss second
#define ff first
#define all(v) v.begin(),v.end()
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pb push_back
#define mod 1000000007
#define mem(a,x) memset(a,x,sizeof(a))
int bit(ll a,int i){if(a&(1LL<<i)) return 1;return 0;}
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};
ll isqrt (ll x){ll ans = 0;for (ll k = 1LL << 30; k != 0; k /= 2){if ((ans + k) * (ans + k) <= x) {ans += k;}}return ans;}
ll bin(ll n,ll pow){ll result=1;while(pow){if(pow&1){result=(result * n);}n=(n*n);pow>>=1;}return result;}
ll binmod(ll a,ll b,ll MOD){ll ans=1;a%=MOD;while(b){if(b&1)ans=(ans*a)%MOD;b/=2;a=(a*a)%MOD;}return ans;}
ll inverse(ll a,ll MOD){return binmod(a,MOD-2,MOD);}
const int N=2e5+12,lg=30;
const  int M=998244353;
#define int long long int
int par[N][lg+1],dep[N],sz[N];
vector<int>adj[N];
void dfs(int v,int p=0){
   par[v][0]=p;
   dep[v]=dep[p]+1;
   sz[v]=1;
   for(int i=1;i<=lg;i++)par[v][i]=par[par[v][i-1]][i-1];
   for(auto u:adj[v]){
     if(u==p)continue;
     dfs(u,v);
     sz[v]+=sz[u];
   }
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i=lg;i>=0;i--){
        if(dep[par[u][i]]>=dep[v])u=par[u][i];
    }
    if(u==v)return u;
    for(int i=lg;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}
int kth(int u,int k){
    assert(k>=0);
    for(int i=0;i<lg;i++){
        if(k&(1<<i))u=par[u][i];
    }
    return u;
}
int distance(int u,int v){
    int l=lca(u,v);
    return dep[u]+dep[v]-(dep[l]<<1);
}
//kth node from u to v, 0th node is u
int go(int u, int v, int k) {
  int l = lca(u, v);
  int d = dep[u] + dep[v] - (dep[l] << 1);
  assert(k <= d);
  if (dep[l] + k <= dep[u]) return kth(u, k);
  k -= dep[u] - dep[l];
  return kth(v, dep[v] - dep[l] - k);
}
void solve(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    for(int i=1;i<=n;i++){
        int u,v;
        cin >> u;
        adj[u].pb(i);
        adj[i].pb(u);
    }
    dfs(1);
    // for(int i=1;i<=n;i++)cin>>par[i][0];
    //  for(int j=1;j<lg;j++){
    //    for(int i=1;i<=n;i++)par[i][j]=par[par[i][j-1]][j-1];
    // }
    while(q--){
        int x,k;
        cin >> x >> k ;
        cout<<kth(x,k)<<nl;
    }
}

signed main()
{
    hello();
cout.precision(10); cout.setf(ios::fixed);

    int tc;
   // cin>>tc;
 // for(int j=1;j<=tc;j++){
  //  cout<<"Case #"<<j<<": ";
       solve();
  // }
}

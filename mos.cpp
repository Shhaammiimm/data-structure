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
const int N=2e5+12;
const  int M=998244353;
#define int long long int
int a[N],n,m,mp[N],ans[N];
int res=0,block_size=1000;
struct query {
    int l, r, ind;
}q[N];
bool cmp(query a,query b)
{
    if(a.l/block_size != b.l/block_size)
    {
        return a.l/block_size < b.l/block_size;
    }
    if((a.l/block_size)&1)return a.r>b.r;
    return a.r < b.r;
}
void remove(int ind){ 
  mp[a[ind]]--;
  res-=(mp[a[ind]]==0);
}  
void add(int ind){  
  mp[a[ind]]++;
  res+=(mp[a[ind]]==1);
}    
void mos() {
    int l = 0;
    int r = -1;
    for (int i=0;i<m;i++) {
        while (l > q[i].l)add(--l);
        while (r < q[i].r)add(++r);
        while (l < q[i].l)remove(l++);
        while (r > q[i].r)remove(r--);
        ans[q[i].ind] = res;
    }
}
void solve(){
 
    cin>>n>>m;
    map<int,int>compress;
    int cnt=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(compress.find(a[i])!=compress.end()){
            a[i]=compress[a[i]];
        }
        else{
            compress[a[i]]=cnt;
            a[i]=compress[a[i]];
            cnt++;
        }
    }
    for(int i=0;i<m;i++){
       int l,r;
       cin>> l >> r;
       l--, r--;
       q[i].l=l;
       q[i].r=r;
       q[i].ind=i;
       
    }
    sort(q, q+m,cmp);
    mos();
    for(int i=0;i<m;i++){
        cout<<ans[i]<<nl;
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

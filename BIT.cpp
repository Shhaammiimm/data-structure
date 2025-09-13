#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
template <typename num_t>
using os = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
//os.order_of_key(x) returs number of elements strictly smaller than x;
//*(os.find_by_order(x)) returns which elemnt is in position x;simply work as ar[x]
ll isqrt (ll x){ll ans = 0;for (ll k = 1LL << 30; k != 0; k /= 2){if ((ans + k) * (ans + k) <= x) {ans += k;}}return ans;}
ll bin(ll n,ll pow){ll result=1;while(pow){if(pow&1){result=(result * n);}n=(n*n);pow>>=1;}return result;}
ll binmod(ll a,ll b,ll MOD){ll ans=1;a%=MOD;while(b){if(b&1)ans=(ans*a)%MOD;b/=2;a=(a*a)%MOD;}return ans;}
ll inverse(ll a,ll MOD){return binmod(a,MOD-2,MOD);}
const int N=1e5+12;
ll t[N],a[N],n,q;
ll query(int idx){
       ll sum=0;
       while(idx>0){
             sum+=t[idx];
             idx -= idx & (-idx);
       }
       return sum;
}
void update(int idx, int x)
{
       while(idx<=n)
       {
             t[idx]+=x;
             idx += idx & (-idx);
       }
}
void build(int n){
 for(int i=1;i<=n;i++){
    update(i,a[i]);
 }
}
void solve(){
   cin>>n>>q;
   for(int i=1;i<=n;i++){
     cin>>a[i];t[i]=0;
   }
   build(n);
   while(q--){
    int k,l,r;
    cin>>k;
    if(k==1){
        cin>>l;
        l++;
        ll ans=query(l)-query(l-1);
        cout<<ans<<nl;
        update(l,-ans);
    }
    else if(k==2){
        cin>>l>>r;
        l++;
        update(l,r);
    }
    else{
        cin>>l>>r;
        l++,r++;
        cout<<query(r)-query(l-1)<<nl;
    }
   }
}

int main()
{
     hello();
cout.precision(10); cout.setf(ios::fixed);

     int tc;
   cin>>tc;
  for(int j=1;j<=tc;j++){
     //cout<<"Case "<<j<<": ";
        solve();

 }
}


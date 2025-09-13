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

void solve(){

    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    int len=sqrt(n)+1;
    vector<int>block(len);
    for(int i=0;i<n;i++){
        block[i/len]+=a[i];
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        int sum=0;
         int c_l = l / len,   c_r = r / len;
         if (c_l == c_r){
            for (int i=l; i<=r; ++i) sum += a[i];
         }
         else {
            for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)sum += a[i];
            for (int i=c_l+1; i<=c_r-1; ++i)sum += block[i];
            for (int i=c_r*len; i<=r; ++i)sum += a[i];
         }
         cout<<sum<<nl;
        }
        
    }

}

signed main()
{
    hello();
cout.precision(10); cout.setf(ios::fixed);

    int tc;
    cin>>tc;
  for(int j=1;j<=tc;j++){
    cout<<"Case "<<j<<": "<<nl;
       solve();
   }
}

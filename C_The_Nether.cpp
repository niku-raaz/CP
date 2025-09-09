#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,s,n) for(ll i=s; i<n; i++)
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define endl "\n"
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define all(v) (v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define vi vector<ll>
#define pll pair<ll,ll>
#define vp vector<pair<ll,ll>>
#define seea(a,n) for(ll i=0;i<n;i++){cin>>a[i];}
#define seed(a,n,m) for(ll i = 0;i<n;i++){for(ll j = 0;j<m;j++){cin>>a[i][j];}}
#define show(a,n) for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;
#define yy cout<<"YES"<<"\n";
#define nn cout<<"NO"<<"\n";
const ll mod = 1e9+7;

// vector<ll> segTree;
// void buildTree(ll idx, ll l, ll r, ll a[]){
//     if(l==r){
//         segTree[idx] = a[l];
//     }
//     ll mid = l+(r-l)/2;
//     buildTree(2*idx+1,l,mid,a);
//     buildTree(2*idx+2,mid+1,r,a);
//     segTree[idx] = segTree[2*idx+1]+segTree[2*idx+2];
// }

// binary exponentiation code :)
// long long binaryExp(long long a, long long b) {
//     long long res = 1;
//     a %= mod;
//     while(b>0){
//         if(b&1){
//             res = (res*a)%mod;
//         }
//         b >>= 1;
//         a = (a*a)%mod;
//     }
//     return res;
// }

ll query(ll x, vector<ll> v){
    cout<<"? "<<x<<" "<<v.size()<<" ";
    cout.flush();
    for(auto it:v){
        cout<<it<<" ";
        cout.flush();
    }
    cout<<endl;
    cout.flush();
    ll ans;
    cin>>ans;
    cout.flush();
    return ans;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll> v;
    for(int i=1;i<=n;i++){
        v.pb(i);
    }
    vector<vector<int>> list(n+1);
    ll maxi = INT_MIN;
    ll node = 0;
    for(int i=1;i<=n;i++){
        ll res = query(i,v);
        if(res>maxi){
            maxi = res;
            node = i;
        }
        list[res].pb(i);
    }
    vector<ll> path;
    path.pb(node);
    for(int i=maxi-1;i>=1;i--){
        for(auto it:list[i]){
            ll res = query(it,{it,node});
            if(res==2){
                path.pb(it);
                node = it;
                break;
            }
        }
    }
    cout<<"! "<<node<<" "<<path.size()<<" ";
    cout.flush();
    for(auto it:path){
        cout<<it<<" ";
        cout.flush();
    }
    cout<<endl;
    cout.flush();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}

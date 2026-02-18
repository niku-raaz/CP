#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   
   
   
   
//#include <ext/pb_ds/assoc_container.hpp> // Common file   
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update   
//#include <ext/pb_ds/detail/standard_policies.hpp>   
   
//using namespace __gnu_pbds;  
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;   
    
//void myerase(ordered_set &t, int v){   
//     int rank = t.order_of_key(v);//Number of elements that are less than v in t   
//     ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t   
//     t.erase(it);  
//}   
   
   
   
#define int long long 
#define ll long long 
#define nl cout<<endl; 
#define raaz ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define take(n) int n; cin>>n;
#define takearr(a,n)  int a[n]; for(int i=0; i<n; i++) cin>>a[i];
#define takevec(a,n)  vector<int> a(n); for(int i=0; i<n; i++) cin>>a[i];
#define sortv(v) sort(v.begin(),v.end());
#define sortarr(arr,n) sort(arr,arr+n);
#define show(ds) for(auto it: ds) cout<<it<<" ";cout<<endl;
#define pb push_back
#define pl cout<<endl;
#define ps cout<<" ";
#define pY cout<<"YES"<<endl;
#define pN cout<<"NO"<<endl;
#define py cout<<"Yes"<<endl;
#define pn cout<<"No"<<endl;
#define ff(i,a,n) for(int i = a;i<n;i++)
#define fl(i,a,n) for(int i = n-1;i>=a;i--)
   
   
bool isPrime(int n){
      if(n<=1){
      return false;
      }
   for(int i = 2;i*i<=n;i++){
     if(n%i==0){
     return false;
       }
    }
  return true;
    }
   
   
   
bool sbs(const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
   }
   
long long binpow(long long a, long long b, long long m) {
   a %= m;
   long long res = 1;
   while (b > 0) {
        if (b & 1)
          res = res * a % m;
        a = a * a % m;
        b >>= 1;
   }
  return res;
}  


// dont fear immplementation

void solve(){
    int n,m;
    cin>>n>>m;

    // Good Question

    // find the largest fib seq ??
    // overlapping 

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<vector<int>> g(n),gR(n);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        gR[y].push_back(x);
    }

    // proceess in sorted order ??
    // will it work ?? 
    // Lets try 

    // vector<int> dp(n,0);
    // dp[i]= # of fib. paths starting at i

    // start with dp[i] =0
    
    // could be cyclic (so process in sorted order)

    vector<pair<int,int>> vp(n);

    for(int i=0;i<n;i++){
        vp[i]={i,a[i]};
    }

    sort(vp.begin(),vp.end(),sbs);

    // ulte order mein process kro 
    

    // Got the idea, but could optimise the time
    // thought using map would result in bad implementation

    vector<map<int,int>> dp(n);

    int mod=998244353;

    for(int i=0;i<n;i++){
        int node=vp[i].first;
        int val=vp[i].second;

        for(auto par: gR[node]){

            if(a[node]>a[par]){
                int diff=a[node]-a[par];

                if(dp[par].count(diff)){
                    int ct= dp[par][diff];

                    dp[node][a[par]]+=ct;
                    dp[node][a[par]]%=mod;
                }
            }


            // normall to hoga hi

            dp[node][a[par]]++;
            dp[node][a[par]]%=mod;

        }
    }

    int ans=0;


    for(int i=0;i<n;i++){
        for(auto it: dp[i]){
            ans+=it.second;
            ans%=mod;
        }
    }

    cout<<ans;pl;
    
        
}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case #"<<xyz<<": ";
             solve(); };        
   return 0;
   }
 
// RAGON MEIN DAUDTE FIRNE KE HAM NAHI QAYAL
// JAB AANKH SE HI NA TAPKA TO FIR LAHU KYA HAI
   
   
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
   
 int mod=1e9+7;
// long long fact[200005];
// long long invf[200005];

// int nCr(int n,int r){

//     int ans=fact[n];
//     ans*=invf[r];
//     ans%=mod;
//     ans*=invf[n-r];
//     ans%=mod;

//     return ans;
    
// }

   
   
void solve(){
    // if n is even 
    // cant make odd
   // int mod=1e9+7;
    

    int n,k;
    cin>>n>>k;
    if(k==0){
        cout<<1;pl;
        return;
    }

    int ans=0;
    ans=binpow(2,n,mod);

    
    // calculate ways where and< xors
    // and is 0 && xor=1
    
    // and is 0 && xor is 1
    // odd numbers of 1
    // 
    // if n is odd
    // nC1+nC3+...+nCn-2;
    // if n is even
    // nC1+nC3+...
    // 

    int ways=binpow(2,n-1,mod);
    if(n%2==1){
        ways=(ways-1+mod)%mod;
    }
    ans=(ans+mod-ways)%mod;

    cout<<binpow(ans,k,mod)%mod;;pl;
    

        
}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
//       int N=200004;
//    fact[0]=1;
//    fact[1]=1;
//    for(int i=2;i<=N;i++){
//        fact[i]=(fact[i-1]*i)%mod;
//    }


//    for(int i=0;i<=N;i++){
//        invf[i]=binpow(fact[i],mod-2,mod);
//    }

    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
 
  
// JITNA BHI DEKHU, DIL BHAR NA PAAYE 
// KAISA SAMAA HAI, HUM TUM YAHA HAI
// JAAHIR KARU KYA HAI JO, MERE IRAADAY
   
   
#include <bits/stdc++.h>
using namespace std;
   
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
   
   
// think of binary search,prefix sum , DP, graph duplication, think in rreverse,    
 // add +M int mod questions  
// think properly   
   
   
// in DP check its subarray / subsequence / subset  
  // then check if its counting problem / optimising problem 
 // then decides the states of DP and transitions and write recurrsion  
   
   
   
 // DP Forms  
 //  Form 1: level wise take/not take  
 //  Form 2: Answer ending here (0...level)  
 //  Form 3: Multisequence eg. LIS, LCS  
 //  Form 4: DP(L,R)=> DP(L,P)*DP(P,R), break in between  
 // Form 5: Game DP  (may have some pattern)  
   
int par[100005];
int cost[100005];
int n;
int root;
   
   
void solve(){
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>par[i]>>cost[i];
        if(par[i]==-1){
            root=i;
        }
    }

    vector<vector<int>> g(n+1);

    for(int i=1;i<=n;i++){
        if(par[i]==-1){
            continue;
        }
        g[par[i]].pb(i);
    }

    vector<int> ans;

    for(int i=1;i<=n;i++){
        if(cost[i]){
            bool f=true;
            for(auto child: g[i]){
               
               if(cost[child]==0){
                f=0;
                break;
               }

            }

            if(f){
                ans.pb(i);
            }
        }
    }

    sortv(ans);

    if(ans.size()==0){
        cout<<-1; return;
    }
    show(ans);
    






        
}
   
   
   
int32_t main(){
        raaz
        int test_case=1; 
       // cin>>test_case; 
        while(test_case--){
                  solve();
              }
   return 0;
   }
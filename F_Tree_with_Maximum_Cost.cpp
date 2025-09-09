 
  
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

int N=200005; 
int sum[200005];
int cost[200005];
int val[200005];
vector<int> g[200005];



void dfs(int node, int parent){
    int s=val[node];
    int c=0;

    for(auto child: g[node]){
        if(child==parent) continue;;
        dfs(child,node);

        s+=sum[child];
        c+=sum[child]+cost[child];
    }

    sum[node]=s;
    cost[node]=c;

}


void rdfs(int node, int parent, int& ans){
    ans=max(ans,cost[node]);
    for(auto child: g[node]){
        if(child==parent) continue;
        int temp=cost[node]-cost[child]-sum[child];
        cost[child]+=temp+sum[node]-sum[child];
        sum[child]=sum[node];
        
        rdfs(child,node,ans);
    }


}



   
void solve(){
    take(n);

    ff(i,1,n+1){
        cin>>val[i];
    }

    ff(i,1,n){
        take(a); take(b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0);

    int ans=0;
    rdfs(1,0,ans);
    cout<<ans;pl;




        
}
   
   
   
int32_t main(){
        raaz
        solve();
   return 0;
   }
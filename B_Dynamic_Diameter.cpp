 
  
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
   
   
   
void solve(){
  take(n);
  if(n==1){
    cout<<1;pl;
    return;

  }

  vector<vector<int>> g(n+2);

  

  ff(i,0,n-1){
    take(x); take(y);

    g[x].pb(y);
    g[y].pb(x);
  }// 

  vector<bool> isleaf(n+1,0);

  
  // calculate diam

  int node=1;

   vector<bool> vis(n+2,0);
   vis[node]=1;

   vector<int> dd(n+1,0);


  int last=node;

  queue<pair<int,int>> q;

  dd[node]=0;

  q.push({node,0});
  while(!q.empty()){
    int v=q.front().first;
    int dis=q.front().second;

    last=v;
    q.pop();

    vis[v]=1;
    dd[v]=dis;

    for(auto neg: g[v]){
      if(vis[neg]==0){
        q.push({neg,dis+1});
      }
    }



  }

  int dmx=dd[last];
  for(int i=1;i<=n;i++){
    if(dd[i]==dmx){
      isleaf[i]=1;
    }
  }

  // 
  int one=last;
  queue<pair<int,int>> qp;

  ff(i,0,n+2){
    vis[i]=0;
  }


  vector<int> d(n+2,0);

  d[one]=0;

  qp.push({one,0});

  vis[one]=1;

  while(!qp.empty()){
    int v=qp.front().first;
    int dis=qp.front().second;
    d[v]=dis;

    vis[v]=1;
    qp.pop();

    for(auto neg: g[v]){
        if(vis[neg]==0){


            qp.push({neg,dis+1});
            
        }
    }




  }

  int mx=0;
  for(int i=1;i<=n;i++){
    mx=max(mx,d[i]);
  }

  //show(d);

  for(int i=1;i<=n;i++){
     if(d[i]==mx || d[i]==0 || isleaf[i]==1){
        cout<<mx+1;pl;
     }else{
        cout<<mx;pl;
     }
  }




  


}





        

   
   
   
int32_t main(){
        raaz
        
        
        solve();
   return 0;
   }
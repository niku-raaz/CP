 
  
// JITNA BHI DEKHU, DIL BHAR NA PAAYE 
// KAISA SAMAA HAI, HUM TUM YAHA HAI
// JAAHIR KARU KYA HAI JO, MERE IRAADAY
   
   
#include <bits/stdc++.h>
#include <cstdio>
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
   
   
class SGTree {
    vector<int> seg;
public:
  SGTree(int n) {
       seg.resize(4 * n + 1);
   }

   void build(int ind, int low, int high, int arr[]) {
      if (low == high) {
           seg[ind] = arr[low];
           return;
       }

    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, arr);
    build(2 * ind + 2, mid + 1, high, arr);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
    // no overlap
    // l r low high or low high l r
    if (r < low || high < l) return INT_MAX;

    // complete overlap
    // [l low high r]
    if (low >= l && high <= r) return seg[ind];

    int mid = (low + high) >> 1;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return min(left, right);
   }
   void update(int ind, int low, int high, int i, int val) {
    if (low == high) {
       seg[ind] = val;
       return;
    }

    int mid = (low + high) >> 1;
    if (i <= mid) update(2 * ind + 1, low, mid, i, val);
    else update(2 * ind + 2, mid + 1, high, i, val);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};
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


const ll NUM = 1e3 + 7;

ll dp1[NUM][NUM], dp2[NUM][NUM], dp3[NUM][NUM], dp4[NUM][NUM];
ll a[NUM][NUM];

   
   
void solve(){
    take(n); take(m);


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            

        }
    }

   

    // down and right

    // 00 to nm

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp1[i][j]=a[i][j]+max(dp1[i-1][j],dp1[i][j-1]);
        }
    }

    // (i, j) to (1, m) going only up and right.

    for(int j=m;j>=1;j--){

        for(int i=1;i<=n;i++){
            dp2[i][j] = a[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);

        }

    }


    for (int i = n; i >= 1; --i){
        for (int j = 1; j <= m; ++j){
            dp3[i][j] = a[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);

        }
        

    }

    for (int i = n; i >= 1; --i){
        for (int j = m; j >= 1; --j){
            dp4[i][j] = a[i][j] + max(dp4[i][j + 1], dp4[i + 1][j]);
        }
        

    }

    int ans=0;

    for(int i=2;i<n;i++){
        for(int j=2;j<m;j++){

            ans=max(ans,dp1[i][j-1]+dp4[i][j+1]+dp2[i-1][j]+dp3[i+1][j]);

            ans=max(ans,dp1[i-1][j]+dp4[i+1][j]+dp2[i][j+1]+dp3[i][j-1]);

        }
    }

    cout<<ans;

    


    






        
}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        solve();    
   return 0;
   }
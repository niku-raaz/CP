 
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
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
    // no overlap
    // l r low high or low high l r
    if (r < low || high < l) return 0;

    // complete overlap
    // [l low high r]
    if (low >= l && high <= r) return seg[ind];

    int mid = (low + high) >> 1;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
   }
   void update(int ind, int low, int high, int i, int val) {
    if (low == high) {
       seg[ind] = val;
       return;
    }

    int mid = (low + high) >> 1;
    if (i <= mid) update(2 * ind + 1, low, mid, i, val);
    else update(2 * ind + 2, mid + 1, high, i, val);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

   
   
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
    int n;cin>>n;
    takevec(h,n);
    takevec(a,n);

    int dp[n+1];
    for(int i = 0;i<=n;i++) dp[i] = 0;
    SGTree seg(n);
    seg.build(0,0,n-1,dp);

    dp[h[0]] = a[0];
    seg.update(0,0,n-1,h[0]-1,dp[h[0]]);

    for(int i=1;i<n;i++){
        dp[h[i]] = a[i] + seg.query(0,0,n-1,0,h[i]-1);
        seg.update(0,0,n-1,h[i]-1,dp[h[i]]);
    }

    int ans=0;
    for(int i=1;i<=n;i++) ans = max(ans,dp[i]);
    cout<<ans<<endl;
}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
       // cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
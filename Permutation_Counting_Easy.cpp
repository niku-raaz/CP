 
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
class dsu {
    vector<int> rank, parent, size; 
public: 
    dsu(int n) {
       rank.resize(n+1, 0); 
       parent.resize(n+1);
       size.resize(n+1); 
       for(int i = 0;i<=n;i++) {
           parent[i] = i; 
           size[i] = 1; 
       }
   }

   int findUPar(int node) {
       if(node == parent[node])
            return node; 
         return parent[node] = findUPar(parent[node]); 
   }

   void unionByRank(int u, int v) {
       int ulp_u = findUPar(u); 
       int ulp_v = findUPar(v); 
       if(ulp_u == ulp_v) return; 
       if(rank[ulp_u] < rank[ulp_v]) {
          parent[ulp_u] = ulp_v; 
       }
       else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
       }
       else {
           parent[ulp_v] = ulp_u; 
           rank[ulp_u]++; 
       }
   }

   void unionBySize(int u, int v) {
         int ulp_u = findUPar(u); 
    int ulp_v = findUPar(v); 
    if(ulp_u == ulp_v) return; 
    if(size[ulp_u] < size[ulp_v]) {
       parent[ulp_u] = ulp_v; 
       size[ulp_v] += size[ulp_u]; 
    }
    else {
       parent[ulp_v] = ulp_u;
       size[ulp_u] += size[ulp_v]; 
    }
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
   
long long countValidX(long long n) {
    // If n <= 1, the range 1 <= x <= n-1 is empty, so the count is 0.
    if (n <= 1) {
        return 0;
    }

    // The total number of integers from 1 to n-1 is (n-1).
    // The condition (x + n) % 3 != 0 means we must exclude values of x
    // for which (x + n) is a multiple of 3.
    // This is equivalent to excluding x where x % 3 == (-n) % 3.

    long long count;

    // Case 1: n is a multiple of 3 (n % 3 == 0)
    // We need to exclude x where x % 3 == 0.
    // The number of valid x is approximately 2/3 of n.
    // The exact count is 2 * (n / 3).
    if (n % 3 == 0) {
        count = 2 * (n / 3);
    }
    // Case 2: n is not a multiple of 3 (n % 3 == 1 or n % 3 == 2)
    // We need to exclude x where x % 3 is either 1 or 2.
    // The number of valid x is approximately 2/3 of (n-1).
    // The exact count is 2 * ((n - 1) / 3).
    else {
        count = 2 * ((n - 1) / 3);
    }

    return count;
}

long long countMatchingX(long long n) {
    // If n <= 1, the range 1 <= x <= n-1 is empty, so the count is 0.
    if (n <= 1) {
        return 0;
    }

    // This problem is the inverse of the previous one. We are counting the numbers
    // that were excluded before.
    // The condition (x + n) % 3 == 0 is equivalent to x % 3 == (-n) % 3.

    long long count;
    long long num_range = n - 1; // The size of the range for x is n-1

    int n_mod_3 = n % 3;

    if (n_mod_3 == 0) {
        // We need to count x where x % 3 == 0.
        // This is the number of multiples of 3 in the range [1, n-1].
        count = num_range / 3;
    } else if (n_mod_3 == 1) {
        // We need to count x where x % 3 == (-1)%3, which is 2.
        // The number of integers equal to 2 (mod 3) in the range [1, n-1].
        count = n / 3; // Simplified from (num_range + 1) / 3
    } else { // n_mod_3 == 2
        // We need to count x where x % 3 == (-2)%3, which is 1.
        // The number of integers equal to 1 (mod 3) in the range [1, n-1].
        count = (n + 1) / 3; // Simplified from (num_range + 2) / 3
    }

    return count;
}
   
void solve(){
    take(n);
    take(k);

    int mod= 998244353;

    // k=3 fixed in this problem

    // No. of ways of valid permutaion of size n
    // such that a[i]+a[i+1]mod3 !=0 for all i<n
    int dp[n+1]; //valid
    

    dp[2]=0;
    dp[3]=2;
   

    for(int i=4;i<=n;i++){

        dp[i]=dp[i-1]*(i-2*countMatchingX(i));

        dp[i]%=mod;
        
    }

    //

    cout<<dp[n]<<endl;

}
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
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
  
class SGTree {
    vector<int> seg;
public:
  SGTree(int n) {
       seg.resize(4 * n + 1);
   }

   void build(int ind, int low, int high, vector<int>& arr) {
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


void solve(){
    int n;cin>>n;
    int c;
    cin>>c;
    takevec(b,n);
    takevec(d,n);

    vector<int> a(n,0);

    // calculate the number of shifts
    // if i iterate over all the possible shifts
    // Then use seg tree to find min in that range

    SGTree seg(n);
    seg.build(0,0,n-1,b); // over b
    int ans=1e18;

    for(int step=0;step<=n;step++){

        int res=c*step;

        // build seg tree

        for(int i=0;i<n;i++){
            
            // find the minim in the range 
            //  i-step to i
            int mn=d[i];

            if(i-step>=0){
                //
                mn=seg.query(0,0,n-1,i-step,i);
            }else{
                // two query
                int mn1=seg.query(0,0,n-1,0,i);
                int ex=step-(i);
                int mn2=seg.query(0,0,n-1,n-ex,n-1);
                mn=min(mn1,mn2);
            }

            res+=(mn*d[i]);


        }

        ans=min(ans,res);
       

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
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
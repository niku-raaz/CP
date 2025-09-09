 
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
   


bool FFF(long long x1, long long y1, long long fx1, long long fy1,
                                     long long x2, long long y2, long long fx2, long long fy2) {

    // Step 1: Preliminary Checks (same as before)

    long long lenSq1 = (fx1 - x1) * (fx1 - x1) + (fy1 - y1) * (fy1 - y1);
    long long lenSq2 = (fx2 - x2) * (fx2 - x2) + (fy2 - y2) * (fy2 - y2);
    if (lenSq1 != lenSq2) {
        return false;
    }

    long long delta_y1 = fy1 - y1;
    long long delta_x1 = fx1 - x1;
    long long delta_y2 = fy2 - y2;
    long long delta_x2 = fx2 - x2;
    if (delta_y1 * delta_x2 == delta_y2 * delta_x1) {
        return false;
    }

    // Step 2: Find the intersection of the perpendicular bisectors (same as before)
    long long A1 = 2 * (x2 - x1);
    long long B1 = 2 * (y2 - y1);
    long long C1 = x2 * x2 - x1 * x1 + y2 * y2 - y1 * y1;

    long long A2 = 2 * (fx2 - fx1);
    long long B2 = 2 * (fy2 - fy1);
    long long C2 = fx2 * fx2 - fx1 * fx1 + fy2 * fy2 - fy1 * fy1;
    
    long long det = A1 * B2 - A2 * B1;
    if (det == 0) {
        return false;
    }

    long long num_x = C1 * B2 - C2 * B1;
    long long num_y = A1 * C2 - A2 * C1;

    // Step 3: NEW - Check if the intersection point has integer coordinates.
    // This is true only if the numerators are perfectly divisible by the determinant.
    if (num_x % det != 0 || num_y % det != 0) {
        return false;
    }

    // Step 4: Verify the integral point lies on both original segments (same as before)
    bool onSegment1 = ((num_y - y1 * det) * (fx1 - x1) - (num_x - x1 * det) * (fy1 - y1)) == 0;
    bool onSegment2 = ((num_y - y2 * det) * (fx2 - x2) - (num_x - x2 * det) * (fy2 - y2)) == 0;

    return onSegment1 && onSegment2;
}


  
   
void solve(){
    int ans=0;
    take(rt);take(ct);
    take(ra);take(ca);
    take(n);
    take(m);
    take(l);

    vector<pair<char,int>> s(m);
    vector<pair<char,int>> t(l);


     for(int i=0;i<m;i++){
        char x;
        cin>>x;
        take(cc);
        s[i]={x,cc};

     }
     for(int i=0;i<l;i++){
        char x;
        cin>>x;
        take(cc);
        t[i]={x,cc};

     }

     


     int i=0;
     int j=0;

     while(i<m && j<l){
        if(s[i].second==0){
            i++;
        }
        if(t[j].second==0){
            j++;
        }
       // cout<<" yy ";

        if(i>=m || j>=l){
            break;
        }

        int rem1=s[i].second;
        int rem2=t[j].second;
        int rem=min(rem1,rem2);

        s[i].second-=rem;
        t[j].second-=rem;

        int fy1=rt; // y is row // x is col
        int fx1=ct;
        int fy2=ra;
        int fx2=ca;


        if(s[i].first=='U'){

            fy1-=(rem);

        }else if(s[i].first=='D'){
            fy1+=rem;

        }else if(s[i].first=='L'){
            fx1-=rem;

        }else{
            // col mein plus
            fx1+=rem;


        }

        if(t[j].first=='U'){
            fy2-=rem;

        }else if(t[j].first=='D'){
            fy2+=rem;

        }else if(t[j].first=='L'){
            fx2-=rem;

        }else{
            fx2+=rem;
        }


        // if dono match kre 

        if(ra==rt && ct==ca && fx1==fx2 && fy1==fy2){
           // complete overlap
            ans+=rem;
        }
        else if(fx1==fx2 && fy1==fy2){
            // only ends are mathcing
            ans++;

        }
        else{

            // intersecting or not
            if(FFF(ct,rt,fx1,fy1,ca,ra,fx2,fy2) && (ra!=rt && ct!=ca)){
                ans++;
            }


        }

        rt=fy1;
        ct=fx1;
        ra=fy2;
        ca=fx2;

        // intersecting or not

     }

    // cout<<rt<<" "<<ct<<" "<<ra<<" "<<ca;pl;

     cout<<ans;pl;

    



        
}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
        //cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
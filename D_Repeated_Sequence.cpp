 
  
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

//  bool subArraySum(vector<int>& arr, int n, int sum)
// {
//     // create an empty map
//     map<int, int> map;

//     // Maintains sum of elements so far
//     int curr_sum = 0;

//     for (int i = 0; i < n; i++) {
//         // add current element to curr_sum
//         curr_sum = curr_sum + arr[i];

//         // if curr_sum is equal to target sum
//         // we found a subarray starting from index 0
//         // and ending at index i
//         if (curr_sum == sum) {
//             // cout << "Sum found between indexes " << 0
//             //      << " to " << i << endl;
//             return 1;
//         }

//         // If curr_sum - sum already exists in map
//         // we have found a subarray with target sum
//         if (map.find(curr_sum - sum) != map.end()) {
//             // cout << "Sum found between indexes "
//             //      << map[curr_sum - sum] + 1 << " to " << i
//             //      << endl;
//             return 1;
//         }

//         map[curr_sum] = i;
//     }

//     // If we reach here, then no subarray exists
//  //   cout << "No subarray with given sum exists";
//  return 0;
// }
   


bool subarraySum(vector<int>& arr,int n, int sum) {
  
    int s = 0, e = 0;  // Initialize window
  
   // vector<int> res;

    int curr = 0;
    for (int i = 0; i < arr.size(); i++) {
        curr += arr[i];

        // If current sum becomes more or equal,
        // set end and try adjusting start
        if (curr >= sum) {
            e = i;

            // While current sum is more
            // remove, starting elements of
            // current window
            while (curr > sum && s < e) {
                curr -= arr[s];
                ++s;
            }

            // If we found a subraay
            if (curr == sum) {
              //  res.push_back(s + 1);
              //  res.push_back(e + 1);
               // return res;
               return 1;
            }
        }
    }

    return 0; // Never found a subarray
}
   
void solve(){
    take(n); take(s);
    takevec(a,n);

    int tmp=s;



    int tot=0;
    for(auto x: a){
        tot+=x;

        if(tot==s){
            py; return;
        }
    }

    s=(s%tot);

   // cout<<s;pl;

    if(s==0){
        pY; return;
    }


    // from start
    int curr=0;

    for(int i=0;i<n;i++){
        curr+=a[i];

        if(curr==s){
            py; return;
        }
    }


    // from end
    curr=0;

    for(int i=n-1;i>=0;i--){
        curr+=a[i];

        if(curr==s){
            py; return;
        }

    }



    vector<int> v(2*n);
    for(int i=0;i<n;i++){
        v[i]=a[i];
        v[i+n]=a[i];
    }

   // show(v);
    


    if(subarraySum(v,n+n,s)){
        py; return;
    }

   // s+=tot;
   s=tmp;
    if(subarraySum(v,n+n,s)){
        py; return;
    }

    


    pn;
        
}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
     //   cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
 
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
   
 int mex(vector<int> &arr, int N)
 {
  
   // sort the array
   sort(arr.begin(), arr.end());
  
   int mex = 0;
   for (int idx = 0; idx < N; idx++)
   {
     if (arr[idx] == mex)
     {
       // Increment mex
       mex += 1;
     }
   }
  
   // Return mex as answer
   return mex;
 }  


void func(vector<int> a, int ex){
    // in

    int n=a.size();
    int ct=0;

    for(int i=0;i<n;i++){
        if(a[i]>0){
            a[i]=1;
        }else{
            ct++;
        }
    }

    if(ct==4){
        cout<<3;pl;
        cout<<3<<" "<<4;pl;
        cout<<1<<" "<<2;pl;
        cout<<1<<" "<<2;pl;
        return;

    }
    if(ct==0){

        cout<<1;pl;
        cout<<1<<" "<<4;pl; return;



    }
    if(ct==1){

        int ind=0;

        for(int i=0;i<n;i++){
            if(a[i]==0){
                ind=i;
                break;
            }
        }

        if(ind==0){

            cout<<2;pl;
            cout<<1<<" "<<2;pl;
            cout<<1<<" "<<3;pl;
            return;



        }else if(ind==3){
            cout<<2;pl;
            cout<<3<<" "<<4;pl;
            cout<<1<<" "<<3;pl;
            return;


            


        }else{
            cout<<2;pl;
            cout<<ind+1<<" "<<ind+2;pl;
            cout<<1<<" "<<3;pl;
            return;

        }


    }

    if(ct==2){

        int ind1=0;
        int ind2=0;

        for(int i=0;i<4;i++){
            if(a[i]==0){
                ind1=i;
                break;
            }
        }

        for(int i=ind1+1;i<n;i++){
            if(a[i]==0){
                ind2=i;
                break;
            }
        }

        if(ind1==0 && ind2==3){

        cout<<3;pl;
        cout<<3<<" "<<4;pl;
        cout<<1<<" "<<2;pl;
        cout<<1<<" "<<2;pl;
        return;



        }else{
            cout<<2;pl;
            cout<<ind1+1<<" "<<ind2+1;pl;
            cout<<1<<" "<<3;pl;
            return;
        }

    }

    if(ct==3){

        int ind=0;
        for(int i=0;i<n;i++){
            if(a[i]==3){
                ind=i;
                break;
            }
        }


        if(ind==1 || ind==2){
            cout<<3;pl;
            cout<<3<<" "<<4;pl;
        cout<<1<<" "<<2;pl;
        cout<<1<<" "<<2;pl;
        return;

        }else{
            if(ind==0){
                cout<<2;pl;
                cout<<2<<" "<<4;pl;
            cout<<1<<" "<<2;pl;

            return;





            }else{

                cout<<2;pl;
                cout<<1<<" "<<3;pl;
            cout<<1<<" "<<2;pl;

            }
        }



    }





}

void func2(vector<int> a, int ex,int k){
    // in

    int n=a.size();
    int ct=0;

    for(int i=0;i<n;i++){
        if(a[i]>0){
            a[i]=1;
        }else{
            ct++;
        }
    }

    if(ct==4){
        cout<<3+1;pl;
        cout<<4<<" "<<k;pl;
        cout<<3<<" "<<4;pl;
        cout<<1<<" "<<2;pl;
        cout<<1<<" "<<2;pl;
        return;

    }
    if(ct==0){

        cout<<2;pl;
        cout<<4<<" "<<k;pl;
        cout<<1<<" "<<4;pl; return;



    }
    if(ct==1){

        int ind=0;

        for(int i=0;i<n;i++){
            if(a[i]==0){
                ind=i;
                break;
            }
        }

        if(ind==0){

            cout<<3;pl;
            cout<<4<<" "<<k;pl;
            cout<<1<<" "<<2;pl;
            cout<<1<<" "<<3;pl;
            return;



        }else if(ind==3){
            cout<<3;pl;
            cout<<4<<" "<<k;pl;
            cout<<3<<" "<<4;pl;
            cout<<1<<" "<<3;pl;
            return;


            


        }else{
            cout<<3;pl;
            cout<<4<<" "<<k;pl;
            cout<<ind+1<<" "<<ind+2;pl;
            cout<<1<<" "<<3;pl;
            return;

        }


    }

    if(ct==2){

        int ind1=0;
        int ind2=0;

        for(int i=0;i<4;i++){
            if(a[i]==0){
                ind1=i;
                break;
            }
        }

        for(int i=ind1+1;i<n;i++){
            if(a[i]==0){
                ind2=i;
                break;
            }
        }

        if(ind1==0 && ind2==3){

        cout<<4;pl;
        cout<<4<<" "<<k;pl;
        cout<<3<<" "<<4;pl;
        cout<<1<<" "<<2;pl;
        cout<<1<<" "<<2;pl;
        return;



        }else{
            cout<<3;pl;
            cout<<4<<" "<<k;pl;
            cout<<ind1+1<<" "<<ind2+1;pl;
            cout<<1<<" "<<3;pl;
            return;
        }

    }

    if(ct==3){

        int ind=0;
        for(int i=0;i<n;i++){
            if(a[i]==3){
                ind=i;
                break;
            }
        }


        if(ind==1 || ind==2){
            cout<<4;pl;
            cout<<4<<" "<<k;pl;
            cout<<3<<" "<<4;pl;
        cout<<1<<" "<<2;pl;
        cout<<1<<" "<<2;pl;
        return;

        }else{
            if(ind==0){
                cout<<3;pl;
                cout<<4<<" "<<k;pl;
                cout<<2<<" "<<4;pl;
            cout<<1<<" "<<2;pl;

            return;





            }else{

                cout<<3;pl;
                cout<<4<<" "<<k;pl;
                cout<<1<<" "<<3;pl;
            cout<<1<<" "<<2;pl;

            }
        }



    }





}
   
void solve(){
    take(n);
    takevec(a,n);

    if(n==4){
        func(a,0);
        return;

    }

    vector<int> v;

    for(int i=3;i<n;i++){
        v.pb(a[i]);
    }

    int mx=mex(v,v.size());

    a[3]=mx;

    vector<int> b;
    for(int i=0;i<4;i++){
        b.pb(a[i]);
    }

    func2(b,1,n);








    


    



        
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
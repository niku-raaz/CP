 
// RAGON MEIN DAUDTE FIRNE KE HAM NAHI QAYAL
// JAB AANKH SE HI NA TAPKA TO FIR LAHU KYA HAI
   
   
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   
   
   
   
#include <ext/pb_ds/assoc_container.hpp> // Common file   
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update   
#include <ext/pb_ds/detail/standard_policies.hpp>   
   
using namespace __gnu_pbds;  
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;   
    
void myerase(ordered_set &t, int v){   
    int rank = t.order_of_key(v);//Number of elements that are less than v in t   
    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t   
    t.erase(it);  
}   
   
   
   
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
   
 int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int> a, int n) {

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}

// Lets do stress testing


int func(vector<int> p){
    int n=p.size();
        // dp or NOT???
    ordered_set left;
    ordered_set right;

    for(int i=1;i<=n;i++){
        right.insert(i);
    }

    for(int i=0;i<n;i++){
        int num=p[i];

        // left inverion
        // bade log in left
        int chhoteinleft=left.order_of_key(num);
        int badeinleft=left.size()-chhoteinleft;

        // right inverion
        // chhote log in right
        int chhoteinright=right.order_of_key(num);

        int badeinright=right.size()-chhoteinright-1; //

        if(badeinleft>badeinright){
            // 
            // choice 2
            int prev=p[i];
            p[i]=2*n-p[i];
            left.insert(p[i]);
            myerase(right,prev);

        }else if(badeinleft==badeinright){
            // kya kiya jaye isme??
            // try both or one??


            // its not detreminant

            //so try both


        }
        else{
            // coice 1
            // do nothing
            left.insert(p[i]);
            myerase(right,p[i]);

        }

    }

  //  show(p);
    return numberOfInversions(p,n);



}

int n;

int Gans;

// 
void rec(vector<int>& p,int i,ordered_set& left,ordered_set& right){
    if(i==n){
        // 
      //  show(p);
        Gans=min(Gans,numberOfInversions(p,n));
        return;
    }

    int num=p[i];
    int chhoteinleft=left.order_of_key(num);
    int badeinleft=left.size()-chhoteinleft;

    int chhoteinright=right.order_of_key(num);
    int badeinright=right.size()-chhoteinright-1;


    if(badeinleft>badeinright){
            // 
            // choice 2
            int prev=p[i];
            p[i]=2*n-p[i];
            left.insert(p[i]);
            myerase(right,prev);
            rec(p,i+1,left,right);

    }else if(badeinleft==badeinright){
            // kya kiya jaye isme??
            // try both or one??


            // its not detreminant

            //so try both

            // try normal
            int x=p[i];
            left.insert(p[i]);
            myerase(right,p[i]);
            rec(p,i+1,left,right);
            right.insert(x);
            myerase(left,x);


            // try second method
            int prev=p[i];
            p[i]=2*n-p[i];
            left.insert(p[i]);
            myerase(right,prev);
            rec(p,i+1,left,right);



            

    }else{
            // coice 1
            // do nothing
            left.insert(p[i]);
            myerase(right,p[i]);
            rec(p,i+1,left,right);

    }




}






   
void solve(){

    cin>>n;
    takevec(p,n);
    Gans=n*n;

    // dp or NOT???
    ordered_set left;
    ordered_set right;

    for(int i=1;i<=n;i++){
        right.insert(i);
    }

    rec(p,0,left,right);
    cout<<Gans;pl;return;

    // for(int i=0;i<n;i++){
    //     int num=p[i];

    //     // left inverion
    //     // bade log in left
    //     int chhoteinleft=left.order_of_key(num);
    //     int badeinleft=left.size()-chhoteinleft;

    //     // right inverion
    //     // chhote log in right
    //     int chhoteinright=right.order_of_key(num);

    //     int badeinright=right.size()-chhoteinright-1; //

    //     if(badeinleft>badeinright){
    //         // 
    //         // choice 2
    //         int prev=p[i];
    //         p[i]=2*n-p[i];
    //         left.insert(p[i]);
    //         myerase(right,prev);

    //     }else if(badeinleft==badeinright){
    //         // kya kiya jaye isme??
    //         // try both or one??


    //         // its not detreminant

    //         //so try both
            

    //     }else{
    //         // coice 1
    //         // do nothing
    //         left.insert(p[i]);
    //         myerase(right,p[i]);

    //     }

    // }

  //  show(p);
    cout<<numberOfInversions(p,n);pl;



        
}


void brute(){
    vector<int> v={1,2,3,4,5,6,7,8};

    do{
      //  show(v);
       cout<<func(v)<<endl;
    }while(next_permutation(v.begin(),v.end()));
}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  // brute();
    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
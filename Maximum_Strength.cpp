 
// RAGON MEIN DAUDTE FIRNE KE HAM NAHI QAYAL
// JAB AANKH SE HI NA TAPKA TO FIR LAHU KYA HAI
   
   
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
   
   
void buildSegmentTree(vector<int>& segTree, const vector<int>& a, int node, int start, int end) {
    if (start == end) {
        segTree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        buildSegmentTree(segTree, a, 2 * node + 1, start, mid);
        buildSegmentTree(segTree, a, 2 * node + 2, mid + 1, end);
        segTree[node] = min(segTree[2 * node + 1], segTree[2 * node + 2]);
    }
}


int rangeQuery(vector<int>& segTree, int node, int start, int end, int l, int r) {
    if (r < start || l > end) return INT_MAX; // Out of range
    if (l <= start && r >= end) return segTree[node]; // Fully in range
    int mid = (start + end) / 2;
    int leftMin = rangeQuery(segTree, 2 * node + 1, start, mid, l, r);
    int rightMin = rangeQuery(segTree, 2 * node + 2, mid + 1, end, l, r);
    return min(leftMin, rightMin);
}





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
   
vector<int> maxStrengths(vector<int>& a) {
    int n = a.size();
    vector<int> left(n, -1), right(n, n); // Initialize bounds
    stack<int> st;

    // Calculate the nearest smaller to the left
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (!st.empty()) left[i] = st.top();
        st.push(i);
    }

    // Clear stack and calculate the nearest smaller to the right
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (!st.empty()) right[i] = st.top();
        st.push(i);
    }

    // Create a result array to store maximum strength for each group size
    vector<int> result(n + 1, 0);

    // Calculate the group size where each element is the minimum
    for (int i = 0; i < n; ++i) {
        int groupSize = right[i] - left[i] - 1; // Size of the group
        result[groupSize] = max(result[groupSize], a[i]);
    }

    // Fill the result for smaller group sizes
    for (int i = n - 1; i >= 1; --i) {
        result[i] = max(result[i], result[i + 1]);
    }

    // Return the result excluding the 0th index
    result.erase(result.begin());
    return result;
}
   
void solve(){
    take(n);
    takevec(a,n);

    vector<int> left(n, -1), right(n, n);
    stack<int> st;

    
    for (int i=0;i<n;i++) {
        while (!st.empty() && a[st.top()]>=a[i]) {
            st.pop();
        }
        if (!st.empty()){
            left[i] = st.top();

        } 
        st.push(i);
    }

    
    while (!st.empty()) st.pop();
    for (int i=n-1;i>=0;i--) {
        while(!st.empty() && a[st.top()]>=a[i]) {
            st.pop();
        }
        if (!st.empty()){
            right[i] = st.top();

        } 
        st.push(i);
    }

 
    vector<int> result(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int groupSize = right[i] - left[i] - 1; 
        result[groupSize] = max(result[groupSize], a[i]);
    }

    
    for (int i = n - 1; i >= 1; --i) {
        result[i] = max(result[i], result[i + 1]);
    }


    for(int i=1;i<=n;i++){
        cout<<result[i]<<" ";
    }

    
    
  


    



        
}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
      //  cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
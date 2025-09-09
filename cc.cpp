 
  
// JITNA BHI DEKHU, DIL BHAR NA PAAYE 
// KAISA SAMAA HAI, HUM TUM YAHA HAI
// JAAHIR KARU KYA HAI JO, MERE IRAADAY
   
   
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   

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
   
// To store segment tree
int* st;

/* A recursive function to get gcd of given
	range of array indexes. The following are parameters for
	this function.

	st --> Pointer to segment tree
	si --> Index of current node in the segment tree.
Initially 0 is passed as root is always at index 0 ss &
se --> Starting and ending indexes of the segment
				represented by current node, i.e.,
st[index] qs & qe --> Starting and ending indexes of
query range */
int findGcd(int ss, int se, int qs, int qe, int si)
{
	if (ss > qe || se < qs)
		return 0;
	if (qs <= ss && qe >= se)
		return st[si];
	int mid = ss + (se - ss) / 2;
	return __gcd(findGcd(ss, mid, qs, qe, si * 2 + 1),
				findGcd(mid + 1, se, qs, qe, si * 2 + 2));
}

// Finding The gcd of given Range
int findRangeGcd(int ss, int se, int arr[], int n)
{
	if (ss < 0 || se > n - 1 || ss > se) {
		cout << "Invalid Arguments"
			<< "\n";
		return -1;
	}
	return findGcd(0, n - 1, ss, se, 0);
}

// A recursive function that constructs Segment Tree for
// array[ss..se]. si is index of current node in segment
// tree st
int constructST(int arr[], int ss, int se, int si)
{
	if (ss == se) {
		st[si] = arr[ss];
		return st[si];
	}
	int mid = ss + (se - ss) / 2;
	st[si]
		= __gcd(constructST(arr, ss, mid, si * 2 + 1),
				constructST(arr, mid + 1, se, si * 2 + 2));
	return st[si];
}

/* Function to construct segment tree from given array.
This function allocates memory for segment tree and
calls constructSTUtil() to fill the allocated memory */
int* constructSegmentTree(int arr[], int n)
{
	int height = (int)(ceil(log2(n)));
	int size = 2 * (int)pow(2, height) - 1;
	st = new int[size];
	constructST(arr, 0, n - 1, 0);
	return st;
}
  
   
void solve(){
    take(n);
    take(q);

    takearr(a,n);

    constructSegmentTree(a,n);

    while(q--){
        take(l); take(r);
        l--;
        r--;

        if(l==r){
            cout<<0<<" ";
        }else{
            cout<<findRangeGcd(l,r,a,n);
        }


    }
    
        
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
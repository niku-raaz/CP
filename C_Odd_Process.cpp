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
void solve(){
  int n;cin>>n;
  takevec(a,n);
  vector<int> even,odd;

  for(auto x: a){
    if(x&1){
      odd.pb(x);
    }else{
      even.pb(x);
    }
  }

  sort(odd.rbegin(),odd.rend());
  sort(even.rbegin(),even.rend());
  // show(odd);
  // show(even);

  vector<int> v;

  if(odd.size()==0){

    for(int i=0;i<n;i++){
      cout<<0<<" ";
    }
    pl;
    return;
  }

  v.push_back(odd[0]);

  for(auto x: even){
    v.push_back(x);
  }

  for(int i=1;i<odd.size();i++){
    v.push_back(odd[i]);
  }

  //show(v);

  vector<int> ans(n,0);
  int sum=0;

  int mid=-1;


  for(int i=0;i<n;i++){
    sum+=v[i];
    if(sum%2==0){
      mid=i;
      break;
    }
  }

  if(odd.size()==1){

    // make pfx

    sum=0;
    for(int i=0;i<n;i++){
      sum+=v[i];
      ans[i]=sum;
    }

    show(ans);

    return;
  }
   
  sum=0;
  for(int i=0;i<mid;i++){
    sum+=v[i];
    ans[i]=sum;
  }

  for(int i=mid;i<n;i++){

    if(i==n-1 && i==mid){
      ans[i]=0;
      continue;
      // this is right
    }

    // I got two pairs
    int diff=i-mid+1;

    if(diff&1){
      // 1 aage hu
      //  mid-2
      if(mid-2>=0){
        ans[i]=ans[mid-2];
      }
      // else{
      //   ans[i]=0;
      // }
      //cout<<"a ";

    }else{

      // 2 aage hu
      // can use the last one
       //cout<<"b ";
      ans[i]=ans[mid-1];
      // this is also true


    }

  }


  show(ans);





     
        
}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case #"<<xyz<<": ";
             solve(); };        
   return 0;
   }
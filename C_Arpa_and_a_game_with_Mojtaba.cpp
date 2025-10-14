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
int mex(vector<int> &arr)
{

  // sort the array
  sort(arr.begin(), arr.end());
  int N=arr.size();

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

void solve(){
    int n;
    cin>>n;
    takevec(a,n);

    auto pf=[&](int x)->map<int,int> {
        map<int,int> mp;
        int val=x;

        for(int i=2;i*i<=x;i++){
            if(x%i){
                continue;
            }
            int ct=0;
            while(x%i==0){
                x/=i;
                ct++;
            }
            mp[i]=ct;
        }
        if(x==val && x!=1){
            mp[x]=1;
        }
        return mp;
    };

    set<int> p;
    vector<map<int,int>> v(n);

    for(int i=0;i<n;i++){
        v[i]=pf(a[i]);
        for(auto it: v[i]){
           // cout<<it.first<<" "<<it.second;pl;
            p.insert(it.first);
        }
        //pl;
    }

    show(p);

    int ans=0;

    for(auto x: p){
        vector<int> b;
        for(int i=0;i<n;i++){
            b.pb(v[i][x]);
        }
        show(b);
        int mx=mex(b);
        mx--;
        cout<<mx<<endl;
        ans = ans ^ mx;
    }

    if(ans==0){
         cout<<"Arpa";
    }else{
        cout<<"Mojtaba";
    }



        
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
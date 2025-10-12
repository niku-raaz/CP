 
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

int subarraySum(vector<int>& nums, int k) {
        // find l and r 
        // st that sum(l,r) ==k
        // total number of such subarry
        int n=nums.size();

        map<int,int> mp; // stroes the largst ind
        
        int ans=1e9;
        mp[0]=-1;;
        int pfx=0;

        for(int r=0;r<n;r++){
            pfx+=nums[r];
            int currsum=pfx;
            int need=currsum-k;

            
            if(mp.find(need)!=mp.end()){
                ans=min(ans,r-mp[need]);
            }
            mp[currsum]=r;
        }


        return ans;

        
    }

void solve(){
    take(n);
    string s;cin>>s;

    int cta=0;
    int ctb=0;

    for(auto x: s){
        if(x=='a'){
            cta++;
        }else{
            ctb++;
        }
    }

    int diff=abs(cta-ctb);

    if(diff==0){
        cout<<0;pl;
        return;
    }

    if(diff==n){
        cout<<-1;pl;
        return;
    }
    
    char x='a';
    if(ctb>cta){
        x='b';
    }
    vector<int> v(n);
    for(int i=0;i<n;i++){
        if(s[i]==x){
            v[i]=1;
        }else{
            v[i]=-1;
        }
        
    }

    //show(v);

    int ans=subarraySum(v,diff);

    if(ans>=n){
        cout<<-1;pl;
        return;
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
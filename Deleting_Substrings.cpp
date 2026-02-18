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


int dp[200002][103][2];

int rec(int i,int j,int lastdel,string& s,string& t){

    int n=s.size();
    int m=t.size();

    if(j==m){
        // all done
        return n-i;
    }

    if(i==n){
        return 1e9;
    }

    if(dp[i][j][lastdel]!=-1){
        return dp[i][j][lastdel];
    }

    int ans=1e9;

    if(s[i]!=t[j]){
        // delete it
        
        if(lastdel==0){
            ans=min(ans,rec(i+1,j,1,s,t)+1);
        }else{
            ans=min(ans,rec(i+1,j,1,s,t));
        }
        
    }else{
        // not take

        if(lastdel==0){
            ans=min(ans,rec(i+1,j,1,s,t)+1);
        }else{
            ans=min(ans,rec(i+1,j,1,s,t));
        }


        // take

        ans=min(ans,rec(i+1,j+1,0,s,t));
    }

    return dp[i][j][lastdel]=ans;
}

void solve(){

    int n,m;
    cin>>n>>m;

    string s,t;
    cin>>s>>t;

    memset(dp,-1,sizeof(dp));



    // must be 1e7 solution

    int ans=rec(0,0,0,s,t);

    int mx=1e9;

    if(ans>=1e9){
        ans=-1;
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
           // cout<<"Case #"<<xyz<<": ";
             solve(); };        
   return 0;
   }
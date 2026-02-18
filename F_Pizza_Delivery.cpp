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

int dp[200003][2];
int rec(int ind,int last,vector<pair<int,pair<int,int>>>& v){
    int n=v.size();
    if(ind==n){
        return 0;
    }
    // 0 means bottom 
    // 1 means top
    if(dp[ind][last]!=-1){
        return dp[ind][last];
    }

    int ans=1e15;

    int tot=abs(v[ind].second.second-v[ind].second.first);

    // Got the issue


    // two choices

    
    if(last==0){
        // end with 1
        // first go to bottom
        int res=rec(ind+1,1,v)+abs(v[ind].second.first-v[ind-1].second.first)+tot;
        
        // end with 0
        // first go to top
        int res2=rec(ind+1,0,v)+abs(v[ind].second.second-v[ind-1].second.first)+tot;
        

        ans=min(res,res2);


    }else{
        // end with 1
        // go to bottom
        int res=rec(ind+1,1,v)+abs(v[ind].second.first-v[ind-1].second.second)+ tot;
        
        // end with 0
        int res2=rec(ind+1,0,v)+abs(v[ind].second.second-v[ind-1].second.second)+ tot;
        ans=min(res,res2);
    }


    return dp[ind][last]=ans;

}


void solve(){
    int n,ax,ay,bx,by;
    cin>>n>>ax>>ay>>bx>>by;

    // first group all yis with particular xis
    // 

    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>v[i].second;
    }

    sortv(v);

    // now 
    map<int,vector<int>> mp;

    for(int i=0;i<n;i++){
        mp[v[i].first].pb(v[i].second);
    }

    for(auto it: mp){
        sortv(it.second);
    }


    vector<pair<int,pair<int,int>>> Vals;
    Vals.push_back({ax,{ay,ay}});


    int ans=bx-ax;

    for(auto it: mp){
        int x=it.first;
        int top=(it.second).back();
        int bottom=(it.second)[0];
        Vals.push_back({x,{bottom,top}});

        
    }

    Vals.push_back({bx,{by,by}});

   
    memset(dp,-1,sizeof(dp));
    int ex=rec(1,1,Vals);
    int ex2=rec(1,0,Vals);
    
    cout<<ans+min(ex,ex2);pl;
    

    // base Values +

    // states??
    // index and top or bottom (2)

    // add all the base value + some extra
    // extra = base if t-b / b-t
    // extra = 2*base


    // make states like where i wanna end with for thix x
    // top or bottom

    // where was I from the last // top or bottom 


        
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
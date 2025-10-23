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
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    // use graph

    // use in based indexing

    vector<vector<pair<int,int>>> g(n+1);

    for(int i=1;i<=n;i++){
        g[0].push_back({i,a[i]});
        g[i].pb({0,a[i]});
    }


    for(int i=2;i<=n;i++){
        g[i-1].push_back({i,abs(a[i]-a[i-1])});
        g[i].push_back({i-1,abs(a[i]-a[i-1])});
    }

    // use binarey ySearch

    auto check=[&](int mid)->bool{
        // use bfs
        queue<int> q;

        q.push(0);
        vector<int> vis(n+1,0);
        vis[0]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=1;


            for(auto childp: g[node]){
                int child=childp.first;
                int wt=childp.second;

                if(!vis[child] && wt<=mid){
                    q.push(child);
                }
            }
        }

        int ct=0;

        for(int i=1;i<=n;i++){
            if(vis[i]){
                ct++;
            }
        }
        if(ct==n){
            return 1;
        }
        return 0;

    };

    int lo=0;
    int hi=1e9+7;
    int ans=hi;

    while(lo<=hi){
        int mid=(lo+hi)/2;

        if(check(mid)){
            ans=min(ans,mid);
            hi=mid-1;
        }else{
            lo=mid+1;
        }



    }


    cout<<ans;pl;






        
}
   
   
   
int32_t main(){
        raaz
   freopen("snake_scales_chapter_2_input.txt","r",stdin);
   freopen("output.txt","w",stdout);
    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           cout<<"Case #"<<xyz<<": ";
             solve(); 
            };        
   return 0;
   }
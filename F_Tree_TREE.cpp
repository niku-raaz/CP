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

      // Good Re-Rooting Question
      int n,k;
      cin>>n>>k;

      vector<vector<int>> g(n);

      for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
      }

      //
      int root=0;
      vector<int> sub(n,0);

      // dfs to calc subtree size

      auto dfs=[&](int node,int par,auto && dfs)->void{
        int ans=1;
        for(auto child: g[node]){
          if(child==par)continue;
          dfs(child,node,dfs);
          ans+=sub[child];
        }
        sub[node]=ans;
      };


      dfs(0,-1,dfs);


     // show(sub);
     // find the count of elements >=k

     int count=0;

     int ans=0;

     for(int i=0;i<n;i++){
      if(sub[i]>=k){
        count++;
      }
     }


     // now start rerooting

     // dfs2 for this

     auto dfs2=[&](int node,int par,int ct,auto && dfs2)->void{
          
          // if node is my root
          // then ans= count

          ans+=ct;

          for(auto child: g[node]){
            if(child==par)continue;

            // break the edge btw node and child
            int proot=sub[node];
            int pchild=sub[child];

            int nchild=n;
            int nroot=sub[node]-pchild;
            sub[child]=nchild;
            sub[node]=nroot;
            int nct=ct;
            if(proot>=k && nroot<k){
              nct--;
            }
            if(pchild<k && nchild>=k){
              nct++;
            }

            dfs2(child,node,nct,dfs2);


            // undo all changes

            sub[node]=proot;
            sub[child]=pchild;

          }
     };

     dfs2(0,-1,count,dfs2);
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
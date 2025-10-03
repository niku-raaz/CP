 
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


class DSU{
      vector<int> par;
      //vector<int> rank;
      public: 
      DSU(int n){
        par.resize(n);
        //rank.resize(n);

        for(int i=0;i<n;i++){
            par[i]=i;
           // rank[i]=0;
        }
      }


      int findPar(int x){
        if(par[x]==x) return x;
        return par[x]=findPar(par[x]);
      }

      void unite(int x,int y){
        int rx=findPar(x);
        int ry=findPar(y);
        if(rx==ry){
            return;
        }
        par[rx]=ry;
      }

      bool isSame(int x,int y){
        return (findPar(x)==findPar(y));
      }
};
   
   
  
   
void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> E(m);

    for(int i=0;i<m;i++){
        take(x);
        take(y);
        take(w);
        x--;
        y--;
        if(x>y){
            swap(x,y);
        }
        E[i]={w,x,y};
    }

    //sortv(E);
    int ans=0;

    vector<int> valid(m,1); // all are valid initially
    
    for(int b=30;b>=0;b--){

        // sort by the value of bth bit
        
        // only to possiblity 

        // mak two vectors
        vector<vector<int>> E0;
      //  vector<vector<int>> E1;

        for(int i=0;i<m;i++){
            if(!valid[i]) continue;
            if((1<<b)&(E[i][0])){
               // E1.push_back(E[i]);
            }else{
                E0.push_back(E[i]);
            }
        }

        // try making MST
        // from only valid edges
        int ct=0;
        DSU d(n);
        for(auto v: E0){
            if(ct==n-1){
                break;
            }
            if(!d.isSame(v[1],v[2])){
                ct++;
                if(ct==n-1){
                    break;
                }
                d.unite(v[1],v[2]);
            }
        }
        if(ct==n-1){
           // possible to hai
           // invalidate the others
           for(int i=0;i<m;i++){
            if((1<<b)&(E[i][0])){
                valid[i]=0;
            }
           }
        }else{
            ans+=(1<<b);
        }
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
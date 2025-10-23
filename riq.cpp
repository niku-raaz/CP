#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   
   
   
   
#include <ext/pb_ds/assoc_container.hpp> // Common file   
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update   
#include <ext/pb_ds/detail/standard_policies.hpp>   
   
using namespace __gnu_pbds;  
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;   
    
void myerase(ordered_set &t, int v){   
    int rank = t.order_of_key(v);//Number of elements that are less than v in t   
    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t   
    t.erase(it);  
}   
   
   
   
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
 
struct da{
    int ind,a,b;
};
void solve(){
 int n,q;cin>>n>>q;
 int arr[n+1];
 for(int i = 1;i<=n;i++)cin>>arr[i];
//  map<int,vector<da>>ma;
 vector<vector<da>>xx(n+1);
 vector<int>v(q);
 vector<vector<int>>vi(q);
 for(int i = 0;i<q;i++){
    int l,r,a,b;
    cin>>l>>r>>a>>b;
    v[i] = r-l+1;
    // ma[l-1].push_back({i,a,b});
    // ma[r].push_back({i,a,b});
    xx[l-1].push_back({i,a,b});
    xx[r].push_back({i,a,b});
    if(l == 1)vi[i].push_back(0);
 }
 ordered_set os;
 for(int i = 1;i<=n;i++){
    os.insert(arr[i]);
    for(auto [ind,a,b]:xx[i]){
        int la = os.order_of_key(a);
        int ra = os.size() - os.order_of_key(b+1);
        vi[ind].push_back(la+ra);
    }
 }
 for(int i = 0;i<q;i++){
    //cout<<v[i]<<" "<<vi[i][1]<<" "<<vi[i][0]<<" ";
    cout<<v[i]-(vi[i][1]-vi[i][0])<<endl;
 
 }

}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
     //   cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
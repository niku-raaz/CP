 
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
void solve(){

    // need frequnecy of 1s and 0s
    // also need if all the 1-0s are alrenate in that range or not


    int n;
    cin>>n;
    int q;
    cin>>q;

    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    vector<int> ct0(n+1,0),ct1(n+1,0);

    for(int i=1;i<=n;i++){
        if(a[i]){
            ct1[i]=ct1[i-1]+1;
            ct0[i]=ct0[i-1];
        }else{
            ct1[i]=ct1[i-1];
            ct0[i]=ct0[i-1]+1;
        }
    }

    // need to find all the 0 1 intervals

    vector<pair<int,int>> p;

    int curr=a[1];
    int start=1;

    for(int i=2;i<=n;i++){
        if(a[i]==curr){
            // not good
            p.pb({start,i-1});
            start=i;
        }else{
            // 
            curr=a[i];
        }
    }

    p.pb({start,n});

    vector<int> col(n+1,0);

    for(auto v: p){
        int start=v.first;
        int end=v.second;

        for(int i=start;i<=end;i++){
            col[i]=start;
        }
    }



    // for(auto pp: p){
    //     cout<<pp.first<<" "<<pp.second;pl;
    // }
    
  //  pY;

    while(q--){
        take(l);
        take(r);

        int x=ct1[r]-ct1[l-1];
        int y=ct0[r]-ct0[l-1];

        if(x%3!=0 || y%3!=0){
           cout<<-1;pl;
           continue;
        }

        // 
        // check if this l to r lies in any valid range or not
        int ans=0;
        ans+=(x/3);
        ans+=(y/3);

        if(col[l]==col[r]){
            ans++;

        }

        cout<<ans;pl;
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
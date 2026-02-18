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

    int ans=0;

    for(int i=1;i<n;i++){
        if(a[i]==1 && a[i-1]==1){
            ans++;
        }
    }



   // 1 -x pair

   for(int j=0;j<n;j++){
       if(a[j]>1){
        if(j-a[j]>=0){
            if(a[j-a[j]]==1){
                ans++;
               // cout<<j-a[j]+1<<" "<<j+1;pl;
            }
        }
        if(j+a[j]<n){
            if(a[j+a[j]]==1){
                ans++;
               // cout<<j+1<<" "<<j+a[j]+1;pl;
            }
        }
       }
   }

   // find more optimisation


   // x-y pair

   // x,y>=2

   // n sqaure if 2,2,2,2,2,2,,2,2,,2.....

   /// j -i = a[j]* a[i]

   // j= i+a[i]*a[j]

   // for each i
   // find all js such that 
   // j= i+a[i]*a[j]

   
   // Can I cache the product ??




    // for(int j=0;j<n;j++){
    //     if(a[j]>1 && a[j]<=n){
    //         // sare multiple upto n
    //         for(int prod=2*a[j];prod<=j;prod+=a[j]){
    //             int mul=prod/a[j];
    //             if(a[j-prod]==mul){
    //                 ans++;
    //             }
    //         }
    //     }
    // }


    // also where a[i]>=2 && a[i]<=n


    // Think of all feasible pairs ??

    vector<map<int,int>> v(n+1);

    // 

    for(int i=2;i<=n;i++){

        for(int prod=2*i;prod<=n;prod+=i){
            int y=prod/i;

            // find number of pairs 
            // of form 

            // x=i
            // y

            // and y-x == prod
            // 2 and 2 

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
           // cout<<"Case #"<<xyz<<": ";
             solve(); };        
   return 0;
   }
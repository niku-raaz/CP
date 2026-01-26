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


bool check(vector<int>& req,vector<int>& aval){
    int n=req.size();
    int m=aval.size();
    int sum=0;
    int sumaval=0;


    // normal Cases  
    for(auto x: req){
        if(x>m){
            return 0;
        }
        sum+=x;
    }
    for(auto x: aval){
        sumaval+=x;
    }
    if(sum>sumaval){
        return 0;
    }

    // how to solve remaining part ????





    // 
    sort(req.rbegin(),req.rend());
    sort(aval.rbegin(),aval.rend());


    vector<int> pfx(n+1,0);
    for(int i=0;i<n;i++){
        pfx[i+1]=pfx[i]+req[i];
    }


    vector<int> pfxaval(m+1,0);
    for(int i=0;i<m;i++){
        pfxaval[i+1]=pfxaval[i]+aval[i];
    }


    // Link to the blog : https://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93Gallai_theorem
    // I need Biparttite 
    // this is another theorem
    // Link : https://en.wikipedia.org/wiki/Gale%E2%80%93Ryser_theorem
    
    for(int k=1;k<=n;k++){
        int lo=0;
        int hi=m;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(aval[mid]>=k){
                lo=mid+1;
            }else{
                // bad
                hi=mid;
            }
        }

        int ct=lo;

        // 0 to l is >=k  // will give k
        //so ct*k
        //  l+1 to 

       

        int r=ct*k+(pfxaval[m]-pfxaval[ct]);

        if(pfx[k]>r){
            return 0;
        }

    }

    return 1;


}


void solve(){

    // Binary Search


    int n,m;
    cin>>n>>m;
    takevec(a,n);
    takevec(b,m);

    sortv(a);

    // 


    

    int lo=1;
    int hi=n;
    int ans=0;

    sortv(b);

    while(lo<=hi){
        int mid=(lo+hi)/2;


        // int 
        int right=n-1;
        int left=right-mid+1;

        // fromleft to right
        // find req
        int curr=1;
        vector<int> req;
        req.push_back(curr);

        int val=a[left];

        for(int i=left-1;i>=0;i--){
            if(a[i]==val){
                req.push_back(curr); // fuck yaar // this should have beem curr
            }else{
                break;
            }
        }

        for(int i=left+1;i<=right;i++){
            if(a[i]!=a[i-1]){
                curr++;
            }
            req.pb(curr);
        }

        // 
        //  find if matching is possible or not??
        // check some blog for matching

        if(check(req,b)){
            ans=max(ans,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }


    }

    cout<<ans;pl;
        
}
   
   
   
int32_t main(){
        raaz
   freopen("preinput.txt","r",stdin);
   freopen("output.txt","w",stdout);
    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
            cout<<"Case #"<<xyz<<": ";
             solve(); };        
   return 0;
   }
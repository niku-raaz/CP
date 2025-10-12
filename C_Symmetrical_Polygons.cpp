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
    take(n);
    takevec(a,n);
    map<int,int> mp;

    sortv(a);

    for(auto x: a){
        mp[x]++;
    }

    vector<int> v;

    
    
    // i can take any numbers with even frequnecy
    // only two with odd frequncy

    // sum of all > 2*x

    // take all even

    int ans=0;

    int taken=0;
    for(auto it: mp){
        if(it.second%2==0){
            ans+=(it.first*it.second);
            taken+=(it.second);
        }else{
            v.push_back(it.first);
            ans+=(it.first*(it.second-1));
            taken+=(it.second-1);
        }
    }

    // odd wale maxium two le skte hain
    // such that sum > this
    // onlt tow

    if(taken==0){
        cout<<0;pl;
        return;
    }

    // taken 

    int ct=0;
    // two cases
    // take only one odd

    int ans1=ans;
    int ans2=ans;
    bool nahi=1;

    for(int i=v.size()-1;i>=0;i--){
        if(ans1>v[i]){
            ans1+=v[i]; 
            //taken++;
            ct++;
            nahi=0;
            break;

        }
    }

    // take 2
    // elements
    // a b
    // ans > abs(a-b);
    int inf=1e18;
    int res=-inf;
    n=v.size();
    int j=n-1;
    int x=ans;
    for(int i=n-2;i>=0;i--){
        while(j>i && v[j]-v[i]>=x ) {
            j--;
        }
        if(j>i && v[j]-v[i]<x){
            int sum=v[i]+v[j];
            res=max(res,sum);
            nahi=0;
            
        }
    }

    if(res!=-inf){
       ans2=ans+res; 
    }

    if(nahi && taken<3){
        cout<<0;pl;
        return;

    }

    cout<<max(ans1,ans2);pl;

    
        
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
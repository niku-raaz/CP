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

vector<int> Nums;

int stringtoNum(string& s){
    int ans=0LL;
    int base=1LL;
    for(int i=0;i<s.size();i++){
        ans+=((s[i]-'0')*base);
        base*=10LL;
    }
    return ans;
}

void pre(){

    // if we fix the mid point
    // all is fixed

    for(char mid='1';mid<='9';mid++){

        string num="";
        num+=mid;
        Nums.push_back(stringtoNum(num));

        for(char x=mid-1;x>'0';x--){
            num=x+num+x;
            Nums.push_back(stringtoNum(num));
        }
    }

    sortv(Nums);


}

void solve(){

    // Ig Number of peaks will be limited
    // So precompute all such numbers
    int a,b,m;
    cin>>a>>b>>m;


    
    //show(Nums);

    int ans=0;
    for(auto x: Nums){
        if(x>=a && x<=b && (x%m)==0){
            ans++;
        }
    }

    cout<<ans;pl;
    
        
}
   
   
   
int32_t main(){
        raaz
   freopen("preinput.txt","r",stdin);
   freopen("preoutput.txt","w",stdout);

   pre();
    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           cout<<"Case #"<<xyz<<": ";
             solve(); };        
   return 0;
   }
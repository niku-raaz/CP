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
#define pl cout<<"\n";
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



vector<vector<int>> fac(200005);

void pre(){
    for (int i = 2; i<200005; i++){
        if (!fac[i].empty())
            continue;

        for (int j = i; j <= 200005; j += i)
            fac[j].push_back(i);
    }


}

void solve(){
    int n;cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        take(x);
        v[i]={x,0};
    }

    for(int i=0;i<n;i++){
        take(x);
        v[i].second=x;
    }
    
    sort(v.begin(),v.end(),sbs);

    
    // use only prime numbers to check

    map<int,int> mp;
    


    // precompute factors man

    int ans=1e18;

    for(int i=0;i<n;i++){
        int x=v[i].first;
        for(auto p: fac[x]){
            if(mp[p]>0){
                cout<<0;pl;
                return;
            }
            mp[p]++;
        }
    }
    
    // 21 41
    // when i came to 41
    // i checked for 42, and find out i have its factor available
    // that is 7
    // so i can imcrement 41 to 42

    for(int i=0;i<n;i++){
        int x=v[i].first;
        // good technique man
        for(auto p: fac[x]){
            mp[p]--;
        }

        for(auto p: fac[x+1]){
            if(mp[p]>0){
                // iska matlab
                // there exist one number whose factor is p 
                // so I can increament x to x+1
                ans=min(ans,v[i].second);
            }
        }

        for(auto p: fac[x]){
            mp[p]++;
        }


    }

    // 
    // NOw I have choice to increate two munbers
    // such that 
    // there end up having gcd>=2

    // for each number
    // use its smallest score

    map<int,int> score;
    int even=0;

    for(int i=0;i<n;i++){
        if(v[i].first%2==0) even++;
        if(score.find(v[i].first)==score.end()){
            score[v[i].first]=min(score[v[i].first],v[i].second);
        }else{
            score[v[i].first]=v[i].second;
        }
    }

    /// 
    // if score.size <1e3 , we can brute 
    // what is all are unique , worst case
    // with no pairs of gcd >=2
    // first thing is , its all odd (atmost one even)

    







    cout<<2;pl;
    



}
   
   
   
int32_t main(){
        raaz
        pre();
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
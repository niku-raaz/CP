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
    string s;
    cin>>s;
    string t;
    cin>>t;

    map<char,int> mp1,mp2;

    for(auto x: s){
        mp1[x]++;
    }

    for(auto x: t){
        mp2[x]++;
    }

    for(auto it: mp1){
        if(mp2[it.first]<mp1[it.first]){
            cout<<"Impossible";pl;
            return;
        }
    }

    // possible
    

    sortv(t);

    // finr the lexo smallest

    // need to make s in t
    string v="";


    for(auto it: mp1){
        char x=it.first;
        mp2[x]-=(it.second);

    }

    for(auto it: mp2){
        char x=it.first;

        for(int i=0;i<mp2[x];i++){
            v+=x;
        }
    }

    sortv(v);
    //cout<<v;
    int n=v.size();
    int m=s.size();
    int i=0;
    int j=0;
    while(i<n && j<m){

        if(v[i]<s[j]){
            cout<<v[i];
            i++;
        }else{
            cout<<s[j];
            j++;
        }
    }

    while(i<n){
        cout<<v[i];
        i++;
    }

    while(j<m){
        cout<<s[j];
        j++;
    }

    pl;




        
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
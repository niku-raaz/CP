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


// 10 *1e4 == 1e5

// we can use 10 char for eacj dits

// 9876543210
// jihgfedcba 

// use z to crete partition 
// this makes 11 digit in worts case

// make every word 10 digit instead 
// so we dont need partition


string numToString(int x){

    string s="";
    while(x){
        int rem=x%10;
        s+=('a'+rem);
        x/=10;
    }
    int need=10-(int)s.size();

    while(need){
        s+='a';
        need--;
    }
    //s+='z';

    return s;

}

int stringToNum(string & s){

    // dont consider z
    int ans=0;
    int pow=1;
    for(auto x: s){
        int d=x-'a';
        ans+=pow*d;
        pow*=10;
    }

    return ans;

}

void encode(){
    int n;cin>>n;

    string s="";
    
    for(int i=0;i<n;i++){
        int x;cin>>x;
        s+=numToString(x);
    }
    cout<<s;

    

}

void decode(){
    string s;cin>>s;

    string curr="";
    vector<int> ans;
    for(int i=0;i<s.size();i++){
        curr+=s[i];
        if(curr.size()==10){
            ans.push_back(stringToNum(curr));
            curr.clear();
        }

    }

    

    cout<<ans.size();pl;
    show(ans);
    
    

}

void solve(){

    string type;
    cin>>type;
    if(type=="first"){
        encode();
    }else{
        decode();
    }
        
}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
      //  cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
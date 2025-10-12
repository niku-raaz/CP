 
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

    take(n);
    take(k);
    string s;cin>>s;
    vector<char> ans(n,'+');

    vector<char> ans2(n,'+');
    int lo=0;
    int hi=n-1;

    int ct0=0;
    int ct1=0;

    int ex=0;

    for(auto x: s){
        if(x=='0'){
            ct0++;
        }else if(x=='1'){
            ct1++;
        }else{
            ex++;
        }
    }
    int left=0;
    int right=n-1;

    for(int i=0;i<ct0;i++){
        ans[i]='-';
        left++;
    }

    for(int i=0;i<ct1;i++){
        ans[n-i-1]='-';
        right--;
    }

    //cout<<left<<" "<<right;pl;
    

    for(int i=left;i<=right;i++){
        // can i makw it safe
        bool safe=0;
        if((right-left+1)>ex){ // 
            safe=1;
        }

        // can i delete ?
        bool del=0;
        if(i<=left-1+ex || i>=right+1-ex){
           del=1;
        }

        if(safe && del){
            ans[i]='?';
        }else{
            if(del){
                ans[i]='-';
            }

        }


    }

    for(auto x: ans){
        cout<<x;
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
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
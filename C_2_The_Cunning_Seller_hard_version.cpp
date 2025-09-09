 
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
   

   
void solve(){
        take(n); take(k);

    vector<pair<int,int>> v;

    for(int i=0;i<19;i++){
        v.push_back({pow(3,i),pow(3,i+1)+i*pow(3,i-1)});
       // cout<<v[i].first<<" "<<v[i].second<<endl;

    }
    

    // lest do dp

  //  cout<<rec(0,k,v)<<endl;

  // in >=40 deals i can make any number of water melons

  int need=0;
  // minum number of deals needed to make n watermelons
  int ans=0;

  int m=n;

  vector<int> taken(20,0);

    for(int i=v.size()-1;i>=0;i--){
        if(v[i].first<=n){
            int x=(n/v[i].first);
            n-=(v[i].first*x);

           need+=x;
           taken[i]=x;
           ans+=v[i].second*x;
        }

    }

    n=m;

    if(need>k){
        cout<<-1;pl;
        return;
    }

   // py;

    // I can always make 
    // can do dp
    // as need<=k

    int rem=k-need;
    if(rem==0){
        cout<<ans;pl;
        return;
    }
 

    int left=0;
    int right=18;


    for(int right=18;right>0;right--){
        if(rem<=0){
            break;
        }
        int left=right-1;

        if(taken[right]>0){
            int num=min(taken[right],rem/2);
            // itne operation kr skta hu
            if(num>0){
                taken[right]-=num;
                taken[left]+=num*3;
                rem-=num*2;

                ans-=v[right].second*num;
                ans+=3*v[left].second*num;
            }
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
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
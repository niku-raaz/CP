
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   
   
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

    int q;
    cin>>q;
    deque<int> a;
    int sum=0;
    int rizz=0;

    bool sidha=1;
    int n=0;


    while(q--){
        take(op);

        if(op==1){
            // cyclic shift
            if(sidha){
                int last=a.back();
                a.pop_back();
                a.push_front(last);
                rizz+=(sum-n*last);
            }else{
                int first=a.front();
                a.pop_front();
                a.push_back(first);
                rizz+=(sum-n*first);
            }
        }else if(op==2){
            if(sidha){
                sidha=0;
            }else{
                sidha=1;
            }
            rizz=(n+1)*sum-rizz;
        }else{
            take(k);
            n++;
            if(sidha){
                a.push_back(k);
            }else{
                a.push_front(k);
            }
            rizz+=(n)*k;
            sum+=k;
        }
        cout<<rizz;pl;
    }
  
}
   
   
   
int32_t main(){
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
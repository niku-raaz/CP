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

   
void solve(){
    take(n);
    takevec(a,n);   
    int ans = 0;
    vector<int> v(32,0);

    for(int b=0;b<=31;b++){
        for(int i=0;i<n;i++){
            if((a[i]>>b)&1){
                v[b]++;
            }
        }
    }

    for(int k=0;k<n;k++){
        int sum=0;
        int num=a[k];
        for(int b=0;b<=31;b++){
            if((num>>b)&1){
                sum+=(n-v[b])*(1<<b);
            }else{
                sum+=(v[b])*(1<<b);
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;pl;
}
   
   
   
int32_t main(){

        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
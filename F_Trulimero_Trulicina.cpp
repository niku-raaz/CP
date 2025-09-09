 
// RAGON MEIN DAUDTE FIRNE KE HAM NAHI QAYAL
// JAB AANKH SE HI NA TAPKA TO FIR LAHU KYA HAI
   
   
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
    take(n);
    take(m);
    take(k);
    int freq=(n*m)/k;

    vector<vector<int>> g(n,vector<int>(m));

    int num=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            g[i][j]=num;
            num++;
            num%=k;
            if(num==0){
                num=k;
            }
        }
    }

    for(int i=1;i<n;i++){
        bool f=0;
        for(int j=0;j<m;j++){
            if(g[i][j]==g[i-1][j]){
                f=1;
                break;
            }
        }
        if(f==1){
            for(int j=0;j<m;j++){
                g[i][j]+=1;
                g[i][j]%=k;
                if(g[i][j]==0){
                    g[i][j]=k;
                }
            }
        }
    }

    ff(i,0,n){
            show(g[i]);
    }
   
}
   
   
   
int32_t main(){
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
             solve(); };        
   return 0;
   }
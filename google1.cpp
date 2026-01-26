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
   
   


int dp[1000000][100];
int kk;
int rec(int ind,int curr,vector<int>& a){
    int n=a.size();
    if(ind==n){
        return 0;
    }
    if(dp[ind][curr]!=-1){
        return dp[ind][curr];
    }
    int ans=rec(ind+1,max(curr+1,kk),a);
    if(curr){
        // can do
        ans=max(ans,rec(ind+1,curr-1,a)+a[ind]);
    }

    return dp[ind][curr]=ans;
}

int res;

int rec2(int ind,int curr,vector<int>& a,vector<int>& work){
    if(ind==a.size()){
        return 0;
    }

    int way1=dp[ind+1][max(kk,curr+1)];
    if(way1==res){
        work[ind]=1;
        res-=way1;
        rec2(ind+1,max(curr+1,kk),a,work);
    }else{
        work[ind]=0;
        res-=dp[ind+1][curr-1];
        rec2(ind+1,max(curr-1,kk),a,work);
    }

    return 0;

    
}

void solve(){
        int n;
        cin>>n;
        takevec(a,n);
        int k;
        cin>>k;
        memset(dp,-1,sizeof(dp));
        kk=k;

        // 
        int ans=rec(0,k,a);
        res=ans;
        vector<int> work(n,0); // if work[i]==1 work on this day
        // other wise rest
        

        // see from dp table

        rec2(0,k,a,work);
        

        




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
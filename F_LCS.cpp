
   
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
   
   


 string s;
 string t;
 int n,m;

int dp[3002][3002];

int f(int i,int j){
    if(i==n || j==m){
        return 0;
    }

     
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;

    if (s[i] == t[j]) {
           return dp[i][j] = 1 + f(i + 1, j + 1);
    } 

    else {
       return dp[i][j] = max(f(i + 1, j), f(i, j + 1));
    }

}
   
   
void solve(){
        cin>>s>>t;
        n=s.size();
        m=t.size();

        memset(dp,-1,sizeof(dp));

        int ans=f(0,0);

        string res="";

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(dp[i][j]==-1){
                    dp[i][j]=0;
                }
            }
        }

        int i=0;
        int j=0;

        while(i<n && j<m){

            if(s[i]==t[j]){
                res+=s[i];
                i++;
                j++;
            }else{

                if(dp[i+1][j]>=dp[i][j+1]){
                    i++;
                }else{
                    j++;
                }
            }

        }

        cout<<res;pl




}
   
   
   
int32_t main(){
        raaz
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
        int test_case=1; 
       // cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           // cout<<"Case# :"<<xyz<<" ";
             solve(); };        
   return 0;
   }
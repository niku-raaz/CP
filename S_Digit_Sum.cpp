#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
string s;

int d;
int dp[10005][2][102];

int mod=1e9+7;

int dfs(int ind, bool tight,int currsum){

    if(ind==s.size()){
        if((currsum)==0){
            return 1;
        }
        return 0;
    }

    if(dp[ind][tight][currsum]!=-1){
        return dp[ind][tight][currsum];
    }

    char bound=(tight==1 ? s[ind]:'9');
    int ans=0;

    for(char x='0';x<=bound;x++){
        int newsum=currsum+(x-'0');
        newsum%=d;
        ans+=dfs(ind+1,(tight==1)&&(s[ind]==x),newsum);
        ans%=mod;
    }

    return dp[ind][tight][currsum]=ans;

}
   
   
int32_t main(){

   cin>>s;
   cin>>d;

   memset(dp,-1,sizeof(dp));

   cout<< (dfs(0,1,0)-1+mod)%mod;;


   
    
    
   
   
 return 0;
}
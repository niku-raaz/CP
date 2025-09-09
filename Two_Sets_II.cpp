#include<bits/stdc++.h>
using namespace std;

int n;
int mod=1e9+7;
int tot;
int target;

int dp[504][125251];


int f(int ind,int need){
    if(ind==0){
        if(need==0){
            return 1;
        }
        return 0;
    }
    if(dp[ind][need]!=-1){
        return dp[ind][need];
    }

    int ans=0;
    ans=f(ind-1,need);
    ans%=mod;
    if(need>=ind){
        ans+=f(ind-1,need-ind);
    }
    ans%=mod;
    return dp[ind][need]= ans;
}


   
int main(){
    cin>>n;
    tot=(n*(n+1))/2;

    if(tot&1){
        cout<<0;
        return 0;
    }
    memset(dp,-1,sizeof(dp));

    // 
    target=tot/2;

    cout<<(f(n,target)*(500000004LL))%mod;;



    // divide it int two set of equal sum

    
   
   
 return 0;
}
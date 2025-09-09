#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
string s;

int mod=1e9+7;

int binpow(int a, int c){
    int res=1;

    for(int b=0;b<=63;b++){
        if(c&(1LL<<b)){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
    }
    return res;
}

int inv(int a){
    return binpow(a,mod-2);
}
   
   
int32_t main(){
    cin>>n>>s;

    int dp[n+1];
    dp[0]=1;

    for(int i=1;i<n-1;i++){
        int num=i+1;
        int ans=0;
        if(s[i]=='<'){
            for(int j=0;j<i;j++){
                if(s[j]=='<'&& s[j+1]=='>'){
                    ans+=1;
                }
            }
        }else{

            // s[i]=">" // problemmatic

        }
        

    }

    


   



    
   
   
 return 0;
}
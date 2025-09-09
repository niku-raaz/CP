#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    int x;cin>>x;

    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<pair<int,int>> dp((1<<n),{1e9,1e9});

    dp[0]={1,0};

    for(int mask=1;mask<(1<<n);mask++){
        for(int bit=0;bit<n;bit++){

            if(!(mask&(1<<bit))) continue;

            int sp_taken=dp[mask^(1<<bit)].second;

            if(sp_taken+a[bit]<=x){
                //good
                dp[mask]=min(dp[mask],{dp[mask^(1<<bit)].first,sp_taken+a[bit]});
            }else{
                //increase
                dp[mask]=min(dp[mask],{dp[mask^(1<<bit)].first+1,a[bit]});
            }


        }
    }

    cout<<dp[(1<<n)-1].first;
    
   
   
 return 0;
}
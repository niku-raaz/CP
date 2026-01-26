#include<bits/stdc++.h>
using namespace std;
#define int long long

   
   
int32_t main(){
    // calc. minimum of max-> Binary Search
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }



    auto check=[&](int mid)->bool{
        // try to make adjacent differnce <=mid for all 
        // in minimum possible operation

        // if at any index a[i]-a[i-1] >mid
        // we could change a[i]/ a[i-1]
        // which one to change ? and to what value?

        // think in opposite way
        // find the max numbers that we can keep unchanged
        vector<int> dp(n);
        dp[0]=1;
        int res=1;
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                int mult=i-j;
                if(abs(a[j]-a[i])<=mid*mult){
                   // 
                   dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }

        int change=n-res;

        return change<=k;
        

    };

    int hi=1e10;
    int lo=0;
    int ans=hi;

    while(lo<=hi){
        int mid=(lo+hi)/2;

        // I want to change atmost k elements in a
        // suct that max(adj_diff) <=mid
        if(check(mid)){
            ans=min(ans,mid);
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }

    cout<<ans;
    
   
   
 return 0;
}
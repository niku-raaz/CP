#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;


   
int32_t main(){

    cin>>n;

    vector<pair<int,pair<int,int>>> v(n);

    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;

        v[i]={y,{x,z}};
    }

    sort(v.begin(),v.end());


    // 2 4 4
    // 3 6 6
    // 5 7 3
    // 6 8 2

    // attend first and third

    // I wanna maintain last taken 

    vector<int> last(n);
    for(int i=0;i<n;i++){
        last[i]=v[i].first;
    }
    
    vector<int> dp(n+1,0);

    dp[0]=0;

    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];

        // take
        int s=v[i-1].second.first;
        int p=v[i-1].second.second;

        // find the last compatible project // s is just greater than max end
        int j=upper_bound(last.begin(),last.end(),s-1)-last.begin();

        dp[i]=max(dp[i],dp[j]+p);


    }

    cout<<dp[n];

    



    

    
   
   
 return 0;
}
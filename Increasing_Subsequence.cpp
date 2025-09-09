#include<bits/stdc++.h>
using namespace std;
#define int long long
void show(int v[],int n){
    for(int i=0;i<n;i++)cout<<v[i]<<" ";
    cout<<endl;
}
   
int32_t main(){
    int n;cin>>n;

    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int dp[n];
    dp[0]=1;
    vector<int> tmp;
    tmp.push_back(a[0]);

    for(int i=1;i<n;i++){
        if(a[i]>tmp.back()){
            tmp.push_back(a[i]);
            dp[i]=tmp.size();
        }else{
            int lo=lower_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin();
            tmp[lo]=a[i];
            dp[i]=lo+1;
        }
    }
   // show(dp,n);
    int ans=1;
    for(int i=0;i<n;i++)ans=max(ans,dp[i]);
    cout<<ans<<endl;
    
    
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    //
    int ct[n+1];
    ct[0]=0;

    int sum=0;
    int pfx[n+1];
    pfx[0]=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        pfx[i]=pfx[i-1]+a[i];
    }
    if(sum%3!=0){
       cout<<0;
       return 0;
    }
    sum/=3;
    int curr=0;
    for(int i=1;i<=n;i++){
        curr+=a[i];
        if(curr==sum){
            ct[i]=1;
        }else{
            ct[i]=0;
        }
    }

    int p[n+1];
    p[0]=0;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+ct[i];
    }

    int ans=0;

    for(int r=3;r<=n;r++){
        // r to n ka sum suhould be sum
        int right=pfx[n]-pfx[r-1];
        if(right==sum){
            // find the number of indexs st that their  prefix sum is == sum
            // 0 0 0 r-2
            ans+=p[r-2];
        }
    }
    cout<<ans;
   
   
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    auto check=[&](int mid)->bool{
        int sum=0LL;

        for(int i=0;i<n;i++){
            sum+=(mid/a[i]);
            if(sum>=k){
                return 1;
            }
        }
        if(sum>=k){
            return 1;
        }
        return 0;

    };

    int lo=0;
    int hi=1e18;
    int ans=hi;

    while(lo<=hi){
        int mid=(lo+hi)/2;

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
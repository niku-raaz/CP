#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    int k;cin>>k;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }


    auto check=[&](int max)->bool{
        
        int ct=1;
        int sum=a[0];

        for(int i=1;i<n;i++){
            if(sum+a[i]<=max){
                sum+=a[i];
            }else{
                ct++;
                sum=a[i];
                if(sum>max){
                    return 0;
                }
            }
        }
        

        if(sum<=max && ct<=k){
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

    cout<<ans;;
    
   
   
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    // BS
    int n;cin>>n;
    int k;cin>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    auto check=[&](int mid)->bool{
        // try to make every aray have <=mid sum
        int sum=0;
        int i=0;
        int ct=1;

        while(i<n){
            if(sum+a[i]<=mid){
                sum+=a[i];
                i++;
            }else{
                ct++;
                sum=a[i];
                if(sum>mid){
                    return 0;
                }
                i++;
            }
        }
        if(ct>k){
            return 0;
        }
        return 1;
    };

    int lo=0;
    int hi=1e16;
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
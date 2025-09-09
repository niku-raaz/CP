#include<bits/stdc++.h>
using namespace std;

#define int long long
   
int32_t main(){

    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // Binary Search
    // we have to minimise the maximum subaarya sum

    int lo=0;
    int hi=1e18;

    int ans=hi;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        // i have to part the array into k subbarys such that 
        // sum of each subaaray is <=mid

        int ct=1;

        int sum=0;
        bool flag=0;

        for(int i=0;i<n;i++){
            if(sum+a[i]<=mid){
                sum+=a[i];
            }else{
                sum=a[i];
                if(sum>mid){
                    flag=1;
                    break;
                }
                ct++;
            }
        }

        if(ct<=k && !flag){
            // good
            ans=min(ans,mid);
            hi=mid-1;

        }else{
            lo=mid+1;
        }





    }

    cout<<ans;

    
   
   
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
   
#define int long long
int32_t main(){

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]%=n;
        a[i]+=n;
        a[i]%=n;

        if(a[i]==0){
            a[i]=n;
        }
        
    }

    //

    map<int,int> mp;
    int ans=0;
    int sum=0;

    for(int i=0;i<n;i++){

        sum+=a[i];
        sum%=n;
        if(sum==0){
            sum=n;
        }
        
        // X can be 

        int prev=n-sum;
        

        if(mp.find(prev)!=mp.end()){
            ans+=mp[prev];
           // cout<<a[i]<<" ";
        }

        mp[sum]++;

    }

    cout<<ans;
    
   
   
 return 0;
}
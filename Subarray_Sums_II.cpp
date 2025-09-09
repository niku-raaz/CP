#include<bits/stdc++.h>
using namespace std;
   
#define int long long 

int32_t main(){

    int n;
    cin>>n;
    int target=0;
    cin>>target;
    vector<int> a(n);


    for(int i=1;i<=n;i++){
        cin>>a[i-1];

       
    }

    map<int,int> mp;
    int ans=0;

    mp[0]++;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];

        // if end here
        // means r=i;
        // i need to find l sucj that sum(l,r)==target
        // sum-prev=traget

        int prev=sum-target;
        if(mp.find(prev)!=mp.end()){
            ans+=mp[prev];

        }

        mp[sum]++;

        

    }

    cout<<ans;

    


   


    
   
   
 return 0;
}
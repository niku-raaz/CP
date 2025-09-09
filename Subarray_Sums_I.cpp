#include<bits/stdc++.h>
using namespace std;
   
#define int long long 

int32_t main(){

    int n;
    cin>>n;
    int target=0;
    cin>>target;
    vector<int> a(n+1),pfx(n+1);

    pfx[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pfx[i]=pfx[i-1]+a[i];
    }

    // prefix sum is
    // 2 6 7 9 16
    int ans=0;


    for(int i=1;i<=n;i++){

        // I want to know j<=i so that pfx[i]-pfx[j-1]=target
        // So i need to find pfx[i]-target in pfx[1,,,,i]

        int see=binary_search(pfx.begin(),pfx.begin()+i,(pfx[i]-target));
       // cout<<see<<" ";

        if(see){
            ans++;
        }

    }

    cout<<ans;


    
   
   
 return 0;
}
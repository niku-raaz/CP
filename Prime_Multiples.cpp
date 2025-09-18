#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,k;
    cin>>n>>k;
    int a[k];

    for(int i=0;i<k;i++){
        cin>>a[i];
    }

    int ans=0;

    // IEP

    // 
    for(int mask=1;mask<(1<<k);mask++){
        // 1e6*20

        int num=n;

        for(int i=0;i<k;i++){
            if(mask&(1<<i)){
               num=(num/a[i]);
            }
        }

        // no think plus all minus
        int ct=__builtin_popcount(mask);
        if(ct&1){
            ans+=num;
        }else{
            ans-=num;
        }


    }

    cout<<ans;



    
   
   
 return 0;
}
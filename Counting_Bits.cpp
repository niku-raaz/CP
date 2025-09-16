#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;
    cin>>n;
    n++;


    int ans=0;
    int batch=1;

    for(int b=0;b<=60;b++){
        // at bth bit
        batch*=2;

        int num=n/batch;
        int rem=n%batch;

        ans+=(num*(batch/2));

        ans+=((max(0LL,rem-batch/2)));


    }

    cout<<ans;
    
   
   
 return 0;
}
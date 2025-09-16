#include<bits/stdc++.h>
using namespace std;

   
   
int32_t main(){
    int n;cin>>n;
    int k;cin>>k;

    int a[n];

    for(int i=0;i<n;i++){
        int num=0;
        int cont=(1<<(k-1));
        for(int j=0;j<k;j++){
            char x;cin>>x;
            if(x=='1'){
                num+=cont;
            }
            cont>>=1;
        }
        a[i]=num;
    }

    int ans=k;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x=a[i]^a[j];
            int sb=__builtin_popcount(x);
            //cout<<a[i]<<" "<<a[j]<<" "<<x<<endl;
            ans=min(ans,sb);
        }
    }

    cout<<ans;
    
   
   
 return 0;
}
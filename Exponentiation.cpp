#include<bits/stdc++.h>
using namespace std;



int mod=1e9+7;

   
   
int32_t main(){
    int tt;
    cin>>tt;

    while(tt--){
        int a,b;
        cin>>a>>b;


        int ans=1;
        int prod=a;

        for(int i=0;i<=31;i++){

            if(b&(1<<i)){

                ans=(ans*1LL*prod)%mod;
                
               // cout<<prod<<" ";

            }
            prod=(prod*1LL*prod)%mod;
            

        }

        cout<<ans<<endl;;

        




    }
    
   
   
 return 0;
}
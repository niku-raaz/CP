#include<bits/stdc++.h>
using namespace std;


   
   
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

       
        int ca=0,cb=0;

        for(int i=0;i<n;i++){
            char x;
            cin>>x;

            if(x=='-'){
               
                ca++;
            }else{
                
                cb++;
            }

        }



        

            long long x=ca/2;
            long long  y=cb;
            long long  z=ca-(ca/2);

            long long  ans=x*y*z;


            cout<<ans<<endl;


        

      

        

















    }
    
   
   
 return 0;
}
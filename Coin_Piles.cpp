#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int tt;cin>>tt;
    while(tt--){

        int a,b;
        cin>>a>>b;

        if(a>b){
            swap(a,b);
        }

        // a is smaller 

        int mx=2*a;

        if(b>mx){
           cout<<"NO\n";
        }else{

           int d=mx-b;
           if(d%3==0){
            cout<<"YES\n";
           }else{
            cout<<"NO\n";

           }

        }










    }
    
   
   
 return 0;
}
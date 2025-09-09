#include<bits/stdc++.h>
using namespace std;
   
   
int main(){

    int n; cin>>n;

    int x=0;

    if(n%4==0){

        x=n;

    }

    if(n%4==1){
        x=1;
    }

    if(n%4==2){
        x=1^n;

    }

    if(n%4==3){
        x=0;

    }

    for(int i=0;i<n-1;i++){
        int z; cin>>z;
        x=x^z;
    }

    cout<<x;

    
   
   
 return 0;
}
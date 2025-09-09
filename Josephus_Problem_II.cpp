#include<bits/stdc++.h>
using namespace std;

int f(int n, int k){

    if(n==1){ 
        return 1;

    }

    if(k*2<=((n+1))){
        if(k*2>n){
            return (2*k)%n;
            // 1 is included
        }
        return 2*k;
    }


    int ans=f(n/2,k-(n+1)/2);
    if(n&1){
        return 2*ans+1;
    }

    return 2*ans-1;
               


}
   
   
int main(){
    int n,k;cin>>n>>k;

    for(int i=1;i<=n;i++){
        
    }

    
   
   
 return 0;
}
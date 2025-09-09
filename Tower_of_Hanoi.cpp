#include<bits/stdc++.h>
using namespace std;

int n;




void rec(int source, int target,int extra,int n){

    if(n==1){
     

     cout<<source<<" "<<target<<"\n";
        return;
    }

    // 
    rec(source,extra,target,n-1);

   
   cout<<source<<" "<<target<<"\n";

    rec(extra,target,source,n-1);


}

   
   
int main(){
    cin>>n;

    cout<<(2<<(n-1))-1<<"\n";


   rec(1,3,2,n);
   
   
 return 0;
}
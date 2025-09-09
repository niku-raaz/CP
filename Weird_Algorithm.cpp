#include<bits/stdc++.h>
using namespace std;
   
   
int main(){

    long long n;
    cin>>n;

    set<int> s;

    while(1){

        if(s.count(n)){
            break;
        }

        s.insert(n);

        cout<<n<<" ";

        if(n==1){
            break;
        }

        if(n&1){
            n=3*n+1;

        }else{
            n=n/2;
        }



    }

    

    
   
   
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){

    int N=1000;

    for(int x=1;x<=N;x++){

        int right=2*x;
        int y=2*x;
        int z= sqrt(y);
        int left=z+1;

        if(right%left==0){
            cout<<x<<" ";
        }

    }
    
   
   
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){

    int q,x;
    cin>>q>>x;
    int N=4e5+5;
    vector<int> v(N,0);

    int ind=0;

    while(q--){
        int a;cin>>a;

        if(x==1){
            cout<<ind+1;
            ind++;
            cout<<endl;
            continue;
        }
        
        // find the smallest number greater than >= ans 
        // we can make using +x / -x

        // BS
        //int curr=ind;

       if(a>N){
          // first make a smallesr than N
          // using large operations
          int k=(a-N+x-1)/x;
          a-=(k*x);
       }

        
        while(a-x>=ind){
            a-=x;
        }

        while(a<N && v[a]==1){
            a+=x;
        }
        if(a<N){
            v[a]=1;
        }

        while(ind<N && v[ind]==1){
            ind++;
        }
        cout<<ind<<endl;

    }


    
   
   
 return 0;
}
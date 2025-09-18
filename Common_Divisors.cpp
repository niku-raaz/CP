#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){

    int n;cin>>n;
    int a[n];
    int MX=1e6;
    vector<int> f(MX+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        f[a[i]]++;
    }

    // ai <=1e6;

    for(int g=MX;g>=2;g--){

        // is sare multiples check kro
        // if we mind two multiples
        // this is the answer
        int ct=0;
        for(int i=1;i*g<=MX;i++){
            ct+=f[i*g];
            if(ct>=2){
                cout<<g;
                return 0;
            }
        }
    }
    //cout<<"hey";
    cout<<1;

    
   
   
 return 0;
}
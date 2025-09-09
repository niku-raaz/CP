#include<bits/stdc++.h>

using namespace std;

#define ll long long



ll dpa[10000001];
//ll dpb[10000001],dpc[10000001],dpd[10000001];



int main(){

    ll n;
    cin>>n;

    int N=10000000;



     ll mod=1e9+7;

     dpa[1]=0;
     

     ll x=1;
     ll y=1;
     ll z=1;

     for(int i=2;i<=n;i++){

        dpa[i]=(x+y+z)%mod;
        
        ll currx=x;
        ll curry=y;
        ll currz=z;

        x=dpa[i-1]+curry+currz;
        x%=mod;
        y=dpa[i-1]+currx+currz;
        y%=mod;
        z=dpa[i-1]+currx+curry;
        z%=mod;




     }

     cout<<dpa[n];

     





    


    return 0;
}
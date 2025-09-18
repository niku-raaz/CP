#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int mod=1e9+7;
int phi=(mod-1);
 
long long binpow(long long a, long long b, long long m) {
   a %= m;
   long long res = 1;
   while (b > 0) {
        if (b & 1)
          res = res * a % m;
        a = a * a % m;
        b >>= 1;
   }
  return res;
} 
 
int inv(int x){
    return binpow(x,mod-2,mod);
}
 
 
   
   
int32_t main(){
    int n;cin>>n;
    vector<pair<int,int>> v(n);
    int a=1;
    int b=1;
    int even=1;
    int prod=1;
    int N=1;
    int N2=1;
    int D=1;
    int D2=1;
    int divid=0;
 
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a*=(y+1);
        a%=mod;
        v[i]={x,y};
        int sum=((binpow(x,y+1,mod)-1+mod)*inv(x-1))%mod;
        b*=sum;
        b%=mod;
        N*=binpow(x,y,mod);
        N%=mod;
        if(y&1){
          even=0;
        }
        N2*=binpow(x,y/2,mod);
        N2%=mod;
        D*=(y+1);
        D%=phi;

        int term=y+1;
        if(term%2==0 && !divid){
          divid=1;
          D2*=(term/2);
          D2%=phi;
        }else{
          D2*=(term);
          D2%=phi;
        }

    }
    int c=1;

    // Now i have N and D
    // calculate D/2

    if(even){
      N=N2;
      // sqrt(N)powerD
    }else{
      // whenN isnt perfect square
      // do D/2;
      D=D2;
    }

    c=binpow(N,D,mod);
    c%=mod;
 
 
    cout<<a<<" "<<b<<" "<<c;
 return 0;
}

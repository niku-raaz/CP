#include<bits/stdc++.h>
using namespace std;
#define int long long


int binpow(int a, int b, int mod) {
    int base = a % mod;
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        b >>= 1;
    }
    return ans;
}
int N=1000002;
int power1[1000002];
int power2[1000002];
int p1=31;
int p2=53;
int mod1=1e9+7;
int mod2=1e9+9;
int inv1[1000002];
int inv2[1000002];
void pre() {
    power1[0] = 1;
    power2[0] = 1;
    for (int i = 1; i < N; i++) {
        power1[i] = (power1[i - 1] * p1) % mod1;
        power2[i] = (power2[i - 1] * p2) % mod2;
    }

    // Compute inverse of last power
    inv1[N - 1] = binpow(power1[N - 1], mod1 - 2, mod1);
    inv2[N - 1] = binpow(power2[N - 1], mod2 - 2, mod2);

    // Fill backwards in O(N)
    for (int i = N - 2; i >= 0; i--) {
        inv1[i] = (inv1[i + 1] * p1) % mod1;
        inv2[i] = (inv2[i + 1] * p2) % mod2;
    }
}

class Hash{
    string s;
    int n;
    vector<int> pfx,pfx2;
    public:
    Hash(string& str){
        s=str;
        n=s.size();
        pfx.resize(n);
        pfx2.resize(n);
        build();
    }
    void build(){
        // pfx[i] = summation ((s[i]-'a+1)*p^i)
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=((s[i]-'a'+1)*power1[i]);
            sum%=mod1;
            pfx[i]=sum;
        }
        sum=0;
        for(int i=0;i<n;i++){
            sum+=(s[i]-'a'+1)*power2[i];
            sum%=mod2;
            pfx2[i]=sum;
        }
    }

    int getVal1(int l,int r){
        if(l==0){
            return pfx[r];
        }
        int res=pfx[r]-pfx[l-1]+mod1;
        res%=mod1;
        res*=inv1[l];
        res%=mod1;
        return res;
    }
    int getVal2(int l,int r){
        if(l==0){
            return pfx2[r];
        }
        int res=pfx2[r]-pfx2[l-1]+mod2;
        res%=mod2;
        res*=inv2[l];
        res%=mod2;
        return res;
    }
};

   
   
int32_t main(){
    string s;
    cin>>s;
    string pat;
    cin>>pat;
    pre();
   
    int n=s.size();
    int m=pat.size();
    Hash h1(s);
    Hash h2(pat);
    int num21=h2.getVal1(0,m-1);
    int num22=h2.getVal2(0,m-1);

    int ans=0;

    for(int i=0;i<n;i++){
        int l=i;
        int r=i+m-1;
        if(r>=n){
            break;
        }
        int num11=h1.getVal1(l,r);
        int num12=h1.getVal2(l,r);
        if(num11==num21 && num12==num22){
            ans++;
        }
    }

    cout<<ans;
    
    
   
   
 return 0;
}
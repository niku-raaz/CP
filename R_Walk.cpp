#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,k;
int mod=1e9+7;
#define vvi vector<vector<int>> 

void mat_mult(vvi& A,vvi& B){
    vvi C(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                C[i][j]+=(A[i][k]*B[k][j])%mod;
                C[i][j]%=mod;
            }
        }
    }
    A=C;
}


vector<vector<int>> binpow(vector<vector<int>>& M, int k){
    if(k==1) return M;
    vector<vector<int>> ans(n,vector<int>(n,0));
    for(int i=0;i<n;i++) ans[i][i]=1;

    for(int b=0;b<=63;b++){
        if(k&(1LL<<b)){
            mat_mult(ans,M);
            //cout<<"Multiplying ans with M for bit "<<b<<endl;
        }
        mat_mult(M,M);
    }
    return ans;
}
   
   
int32_t main(){
    cin>>n>>k;

    //cout<<"Calculating M^"<<k<<endl;

    vector<vector<int>> M(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>M[i][j];
        }
    }


    // I want to caculate M^K
    // We Can do that in Binary Exponentiation

    vvi ans=binpow(M,k);

    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res=(res+ans[i][j])%mod;
        }
    }


    cout<<res<<endl;

   
   
 return 0;
}
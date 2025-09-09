#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){

    int n;int q;
    cin>>n>>q;

    int p[n+1];

    p[0]=0;

    for(int i=1;i<=n;i++){
        cin>>p[i];
    }

    for(int i=1;i<=n;i++){
        p[i]+=p[i-1];
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        cout<<p[r]-p[l-1]<<endl;
    }
    
   
   
 return 0;
}
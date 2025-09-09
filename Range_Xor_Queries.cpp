#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[200005];
   
   
int32_t main(){
    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;i++){
        cin>>a[i+1];
    }

    a[0]=0;

    for(int i=1;i<=n;i++){
        a[i]=a[i]^a[i-1];
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        cout<<(a[r]^a[l-1])<<endl;
    }



    
   
   
 return 0;
}
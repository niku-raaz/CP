#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    int x,a,b,c;
    cin>>x>>a>>b>>c;

    int prev=x;
    int ans=0;
    int curr=0;

    for(int i=1;i<=k;i++){
        curr^=x;
        x=(a*x+b)%c;
    }
    
    

    for(int i=k+1;i<=n;i++){
        //cout<<prev<<" "<<x<<" "<<curr<<endl;
        ans=ans^curr;

        curr^=prev;
        curr^=x;
        prev=(prev*a+b)%c;
        x=(x*a+b)%c;
        
    }

    ans=ans^curr;

    cout<<ans;
    
   
   
 return 0;
}
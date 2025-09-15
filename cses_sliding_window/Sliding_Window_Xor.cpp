#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    int ans=0;
 
    int x,a,b,c;
    cin>>x>>a>>b>>c;
 
    int last=x;
 
    for(int i=1;i<=k;i++){
        ans^=x;
        x=(a*x+b)%c;
    }
    //cout<<ans<<" ";
    int win=ans;
 
    for(int i=k+1;i<=n;i++){
        cout<<last<<" "<<x<<" "<<win<<endl;
        win^=last;
        last=(a*last+b)%c;        
        win^=x;
        x=(a*x+b)%c;

        ans^=win;
    }
    ans^=last;
    ans^=x;
 
    cout<<ans;
    
   
   
 return 0;
}

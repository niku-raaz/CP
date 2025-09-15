#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    int ans=0;
    int sum=0;

    int x,a,b,c;
    cin>>x>>a>>b>>c;

    int last=x;

    for(int i=1;i<=k;i++){
      //  cout<<x<<" ";
        sum+=x;
        x=(a*x+b)%c;
    }
    //cout<<endl;
    //cout<<sum<<" ";

    ans=ans^sum;

    for(int i=k+1;i<=n;i++){
        sum-=last;
        //cout<<last<<" ";
        last=(a*last+b)%c;
        //cout<<x<<" ";
        
        sum+=x;
        //cout<<x<<endl;
        x=(a*x+b)%c;
        
       // cout<<sum<<" ";
        ans^=sum;
    }

    cout<<endl;

    cout<<ans;
    
   
   
 return 0;
}
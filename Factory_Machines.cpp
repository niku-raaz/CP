#include<bits/stdc++.h>
using namespace std;

#define ll long long
   
   
int main(){
    int n,t;
    cin>>n>>t;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll lo=0;
    ll hi=1e18;

    ll ans=hi;

    while(lo<=hi){
        ll mid=(lo+hi)/2;

        // if i have mid second
        // can i make >=t prodccuts
        ll count=0;

        for(int i=0;i<n;i++){
            count+=(mid/a[i]);
            if(count>=t){
                break;
            }

        }

        if(count>=t){
            ans=min(ans,mid);
            hi=mid-1;


        }else{
            lo=mid+1;

        }

    }

    cout<<ans;



    
   
   
 return 0;
}
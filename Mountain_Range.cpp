#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){

    int n;cin>>n;

    

    vector<int> a(n,0),l(n,0),r(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // 

    
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            l[i]=l[i-1]+1;
        }else{
            l[i]=0;
        }
    }
    
    for(int i=n-2;i>=0;i--){
        if(a[i+1]<a[i]){
            r[i]=r[i+1]+1;
        }else{
            r[i]=0;
        }
    }

    int ans=1;
    for(int i=0;i<n;i++){
        ans=max(ans,(l[i]+r[i]+1));
    }

    cout<<ans;
    
    
   
   
 return 0;
}
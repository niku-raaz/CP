#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    sort(a,a+n);
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+1<a[i]){
            cout<<sum+1;
            return 0;
        }
        sum+=a[i];
    }

    cout<<sum+1;

    
   
   
 return 0;
}
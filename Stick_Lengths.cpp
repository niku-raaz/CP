#include<bits/stdc++.h>
using namespace std;

#define ll long long
   
int main(){
    int n;cin>>n;

    vector<int> a(n);
  
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    ll mean=a[(n/2)];

    ll ans=0;

    for(int i=0;i<n;i++){
        ans+=abs(a[i]-mean);
    }

    cout<<ans<<endl;
   

    



    
   
   
 return 0;
}
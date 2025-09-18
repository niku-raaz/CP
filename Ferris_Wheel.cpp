#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,x;
    cin>>n>>x;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    int ans=0;
    int i=0;
    int j=n-1;

    while(i<=j){
        if(i==j){
            ans++;
            break;
        }
        if(a[i]+a[j]<=x){
            i++;
            j--;
            ans++;
        }else{
            ans++;
            j--;
        }
    }

    cout<<ans;
    
   
   
 return 0;
}
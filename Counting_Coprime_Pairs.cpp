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

    vector<int> f(1e6+1,0),f2(1e6+1,0);

    for(int i=0;i<n;i++){
        f[a[i]]++;
    }

    vector<int> cnt(1e6+1,0);

    for(int i=2;i<=1e6;i++){
        for(int j=2*i;j<=1e6;j+=i){
            cnt[j]+=f[i];
        }
    }

    int ans=0;
    int ex=0;

    for(int i=0;i<n;i++){
        if(a[i]==1){
            ex++;
            continue;
        }
        int x=a[i];

        ans+=(i-cnt[x]-f2[x]);
        cout<<a[i]<<" "<<cnt[x]<<" "<<f2[x]<<endl;
        f2[a[i]]++;
         
    }

    cout<<ans+(ex*(ex-1))/2;
    
    
   
   
 return 0;
}
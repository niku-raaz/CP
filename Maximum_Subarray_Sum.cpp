#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    long long ans=*max_element(a.begin(),a.end());
    long long maxtillhere=0;
   

    for(int i=0;i<n;i++){
        maxtillhere+=a[i];
        ans=max(ans,maxtillhere);

        if(maxtillhere<0){
            maxtillhere=0;
        }

        

    }
    cout<<ans;

   
   
 return 0;
}
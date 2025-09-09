#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;
    cin>>n;
    int x;cin>>x;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    int lo=0;
    int hi=n-1;
    int ans=0;

    while(lo<=hi){
       
        if(lo==hi){
            ans++;
            break;
        }
        if(a[lo]+a[hi]>x){
            ans++;
            hi--;

        }else{
            ans++;
            lo++;
            hi--;
        }

    }

    cout<<ans;
    
   
   
 return 0;
}
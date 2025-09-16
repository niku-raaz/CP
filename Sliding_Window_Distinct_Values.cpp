#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,k;
    cin>>n>>k;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    map<int,int> mp;
    for(int i=0;i<k;i++){
        mp[a[i]]++;
    }

    for(int i=k;i<n;i++){
        cout<<mp.size()<<" ";

        int last=a[i-k];
        mp[last]--;
        mp[a[i]]++;
        if(mp[last]==0){
            mp.erase(mp.find(last));
        }

    }
    cout<<mp.size();


    
   
   
 return 0;
}
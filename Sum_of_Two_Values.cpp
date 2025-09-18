#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,x;
    cin>>n>>x;

    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++){
        int k;cin>>k;
        v[i]={k,i};
    }

    sort(v.begin(),v.end());

    // brute on first
    // BS on second

    for(int i=0;i<n;i++){
        int need=x-v[i].first;

        int lo=i+1;
        int hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(v[mid].first==need){
                cout<<v[i].second+1<<" "<<v[mid].second+1;
                return 0;
            }else if(v[mid].first>need){
                hi=mid-1;
            }else{
                lo=mid+1;

            }
        }
    }



    cout<<"IMPOSSIBLE";

    
   
   
 return 0;
}
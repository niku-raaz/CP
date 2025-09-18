#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> b(m);
    vector<pair<int,int>> a(n);
 
    for(int i=0;i<n;i++){
        int x;cin>>x;

        a[i]={x-k,x+k};
    }

    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    sort(b.begin(),b.end());

    sort(a.begin(),a.end());

    // sorted by end time

    int i=0;
    int j=0;

    int ans=0;

    while(i<n && j<m){

        if(a[i].first<=b[j] && a[i].second>=b[j]){
            ans++;
            j++;
            i++;
        }else{
            if(a[i].first<=b[j]){
               // endpoint< b[j]
                i++;
            }else if(a[i].second>=b[j]){
                // start> b[j]
                j++;
            }

        }
    }

    cout<<ans;
    
   
   
 return 0;
}
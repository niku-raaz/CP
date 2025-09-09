#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i]={x,y};
    }

    sort(a.begin(),a.end(),[&](const pair<int,int>& x, const pair<int,int>& y){
        return x.second<y.second;
    });

   int ans=0;
   int curr=0;

   for(int i=0;i<n;i++){
    if(a[i].first>=curr){
        ans++;
        curr=a[i].second;
    }

   }

   cout<<ans;








    
   
   
 return 0;
}
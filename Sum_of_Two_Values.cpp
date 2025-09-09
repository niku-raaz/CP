#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;cin>>n;
    int x;cin>>x;

    vector<pair<int,int>> a(n);

    for(int i=0;i<n;i++){
        int y;cin>>y;
        a[i]={y,i+1};
    }

    sort(a.begin(),a.end());

    int lo=0;
    int hi=n-1;
    while(lo<hi){
        int sum=a[lo].first+a[hi].first;
        if(sum==x){
            cout<<a[lo].second<<" "<<a[hi].second;
            return 0;
        }else if(sum>x){
            hi--;
        }else{
            lo++;
        }


    }

    cout<<"IMPOSSIBLE";


    
   
   
 return 0;
}
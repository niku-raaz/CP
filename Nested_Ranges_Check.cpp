#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;cin>>n;
    vector<pair<int,pair<int,int>>> v(n);

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[i]={a,{b,i}};
    }

    sort(v.begin(),v.end(),[&](pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b){
                 if(a.first!=b.first){
                    return a.first<b.first;
                 }else{
                    return a.second.first>=b.second.first;
                 }
    });

    vector<int> f1(n,0),f2(n,0);

    // 1 2 3 4
    // 6 4 6 8
    
    // 1 0 0 0  // does it contains some other range
    // 0 1 1 0  // is it contained in other range

    int mn=v[n-1].second.first;

    for(int i=n-2;i>=0;i--){

        if(mn<=v[i].second.first){
            f1[v[i].second.second]=1;
        }

        mn=min(mn,v[i].second.first);
    }

    int mx=v[0].second.first;

    for(int i=1;i<n;i++){

        if(mx>=v[i].second.first){
            f2[v[i].second.second]=1;
        }
        mx=max(mx,v[i].second.first);
    }





    for(int i=0;i<n;i++){
        cout<<f1[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<f2[i]<<" ";
    }







    
   
   
 return 0;
}
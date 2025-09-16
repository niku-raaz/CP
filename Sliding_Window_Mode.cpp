#include<bits/stdc++.h>
using namespace std;
#define int long long


struct Cmp{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const{
     if(a.second!=b.second){
        return a.second>b.second;
     }

     return a.first<b.first;
    }
};

   
int32_t main(){
    // one with max frequnecy
    // pririty queue?
    int n,k;
    cin>>n>>k;
    // I want ordered map// 
    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // for freq
    map<int,int> f;

    // for custom comparator
    multiset<pair<int,int>,Cmp> mp;

    auto ans=[&]()->void{
        cout<<(*mp.begin()).first<<" ";
    };

    auto add=[&](int x)->void{
        if(f[x]>0){
            mp.erase({x,f[x]});
        }
        f[x]++;
        mp.insert({x,f[x]});

    };
    auto del=[&](int x)->void{
        mp.erase({x,f[x]});
        f[x]--;
        if(f[x]){
           mp.insert({x,f[x]});
        }

    };


    for(int i=0;i<k;i++){
        add(a[i]);
    }


    for(int i=k;i<n;i++){
        ans();
        add(a[i]);
        del(a[i-k]);
    }

    ans();
    

    
    
   
   
 return 0;
}
#include<bits/stdc++.h>
using namespace std;

   
   
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int x,n;
    cin>>x>>n;

    set<pair<int,int>> s;

    multiset<int,greater<int>> Mx;

    Mx.insert(x);

    s.insert({0,x});

    for(int i=0;i<n;i++){
        int a;cin>>a;
        auto up=s.lower_bound({a,a});// >=
        up--;
        // jus smaller
        pair<int,int> p=*up;
        int l=p.first;
        int r=p.second;
        int d=r-l;
        s.erase(up);
        s.insert({l,a});
        s.insert({a,r});
        Mx.erase(Mx.find(d));
        Mx.insert(a-l);
        Mx.insert(r-a);

        cout<<(*Mx.begin())<<" ";
    }
    
   
   
 return 0;
}
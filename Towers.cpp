#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;

    multiset<int> s;

    for(int i=0;i<n;i++){
        int x;cin>>x;
        auto up=s.upper_bound(x);
        if(up==s.end()){
            s.insert(x);
        }else{
            s.erase(up);
            s.insert(x);
        }
    }

    cout<<s.size();

    
   
   
 return 0;
}
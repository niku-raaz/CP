#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n,m;
    cin>>n>>m;
    
    multiset<int> s;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        s.insert(x);
    }

    for(int i=0;i<m;i++){
        int p;cin>>p;

        auto lb=(s.upper_bound(p));

        if(lb==s.begin()){
            cout<<-1<<endl;
            continue;
        }
        lb--;
        cout<<*lb<<endl;
        s.erase(s.find(*lb));
        
        
        
    }
    
   
   
 return 0;
}
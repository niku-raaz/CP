#include<bits/stdc++.h>
using namespace std;
   
   
int main(){

    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    
    multiset<int> s;
    s.insert(a[0]);

    for(int i=1;i<n;i++){
        int x=*(--s.end());

        if(a[i]>=x){
            s.insert(a[i]);
            continue;
        }


        int up=*s.upper_bound(a[i]);
        s.erase(s.find(up));
        s.insert(a[i]);

    }

    cout<<s.size();
    
   
   
 return 0;
}
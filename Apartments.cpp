#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    multiset<int> s;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        s.insert(x);
    }

    int ans=0;



    for(auto num: a){
        int lo=num-k;
        int lb=*s.lower_bound(lo);
        if(lb<=num+k && lb>=num-k){
            s.erase(s.find(lb));
            ans++;
        }



    }

    cout<<ans;



    
   
   
 return 0;
}
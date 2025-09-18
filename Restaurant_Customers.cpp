#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;
    cin>>n;

    set<int> s;
    vector<int> v(2*n);

    for(int i=0;i<2*n;i+=2){
        int x,y;
        cin>>x>>y;
        v[i]=x;
        v[i+1]=y;
        s.insert(x);
    }

    sort(v.begin(),v.end());
    int ans=1;
    int curr=0;
    for(int i=0;i<2*n;i++){
        if(s.count(v[i])){
            curr++;
        }else{
            curr--;
        }
        ans=max(ans,curr);
    }

    cout<<ans;

 return 0;
}
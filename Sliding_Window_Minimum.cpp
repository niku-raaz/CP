#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    int n;cin>>n;

    int k;cin>>k;

    int x,a,b,c;
    cin>>x>>a>>b>>c;
    int ans=0;

    deque<pair<int,int>> dq;

    for(int i=1;i<=k;i++){
        int ct=1;
        while(!dq.empty() && dq.back().first>x){
            ct+=dq.back().second;
            dq.pop_back();
            
        }
        dq.push_back({x,ct});
        // if ct reaches 0 means, remove that guy

        x=(x*a+b)%c;
    }

    for(int i=k+1;i<=n;i++){
        
        // calculate the answer buddy
        pair<int,int> p=dq.front();
        ans^=p.first;

        dq.front().second-=1;
        if(dq.front().second==0){
            dq.pop_front();
        }

        int ct=1;

        while(!dq.empty() && dq.back().first>x){
            ct+=dq.back().second;
            dq.pop_back();
            
        }
        dq.push_back({x,ct});
        x=(x*a+b)%c;

    }
    pair<int,int> p=dq.front();
    ans^=p.first;

    cout<<ans;

    
   
   
 return 0;
}
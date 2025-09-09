#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;
    cin>>n;
    vector<int> v;
    set<int> in;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(x);
        v.push_back(y);
        in.insert(x);
        
    }

    int ans=0;
    int curr=0;
    sort(v.begin(),v.end());

    for(auto t: v){
        if(in.count(t)){
            curr++;

        }else{
            curr--;

        }
        ans=max(ans,curr);

    }

    cout<<ans;
    
   
   
 return 0;
}
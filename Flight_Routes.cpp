#include<bits/stdc++.h>
using namespace std;
#define int long long
   
   
int32_t main(){
    // k is upto 10


    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>> g(n+1);

    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
    }
    int inf=1e18;
    vector<vector<int>> dis(n+1,vector<int>(k+1,inf));
    
    

    
   
   
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
    }
    int m; cin>>m;
    for(int i=0;i<n;i++){
        cin>>v[i].second;
    }

    for(int i=0;i<n;i++){
        if(v[i].first>v[i].second){
            swap(v[i].first,v[i].second);
        }
    }

    sort(v.begin(),v.end());

    vector<bool> vis(n,0);

    int ans=0;

    for(int i=0;i<n;i++){

        if(!vis[i]){
            vis[i]=1;
            ans++;
            // right most point pe

            // 
            int curr=v[i].second;

            for(int j=i+1;j<n;j++){

                if(v[j].first>curr){
                    break;
                }

                vis[j]=1;


            }


        }

    }

    cout<<ans;
    
   
   
 return 0;
}
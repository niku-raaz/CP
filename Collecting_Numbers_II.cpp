#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),mp(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]=i;
    } 

    int ans=1;
    for(int i=2;i<=n;i++){
        if(mp[i]<mp[i-1]){
            ans++;
        }
    }


    while(m--){
        int x,y;
        cin>>x>>y;

        if(x>y){
            swap(x,y);
        }

        // char position pe
        int before=0;

        if(x>1){
            if(mp[x-1]>mp[x]){
                before++;
            }
        }
        if(x<n){
            if(mp[x+1]<mp[x]){
                before++;
            }
        }

        if(y>1 && abs(y-x)>1){
            if(mp[y-1]>mp[y]){
                before++;
            }
        }
        if(y<n){
            if(mp[y+1]<mp[y]){
                before++;
            }
        }
        
        swap(mp[a[x-1]],mp[a[y-1]]);
        swap(a[x-1],a[y-1]);

        // for(int i=1;i<=n;i++){
        //     cout<<mp[i]<<" ";
        // }
        // cout<<endl;

        int after=0;

        if(x>1){
            if(mp[x-1]>mp[x]){
                after++;
            }
        }
        if(x<n){
            if(mp[x+1]<mp[x]){
                after++;
            }
        }

        if(y>1 && abs(y-x)>1){
            if(mp[y-1]>mp[y]){
                after++;
            }
        }
        if(y<n){
            if(mp[y+1]<mp[y]){
                after++;
            }
        }

       // cout<<before<<" "<<after<<endl;

        ans=ans+(after-before);
        cout<<ans<<endl;

        



    }
    
   
   
 return 0;
}
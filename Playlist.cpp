#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;
    cin>>n;
    map<int,int> mp;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }


    int ans=1;
    int left=0;

    for(int i=0;i<n;i++){
        if(mp.find(a[i])!=mp.end()){
            // exist
            left=max(left,mp[a[i]]+1);
            mp[a[i]]=i;
          
            ans=max(ans,i-left+1);
           // cout<<i-left+1<<" ";
            
        }else{
            mp[a[i]]=i;
            ans=max(ans,i-left+1);
           // cout<<i-left+1<<" ";

        }

      //  cout<<endl;
        
        
      

    }

    cout<<ans;


    
   
   
 return 0;
}
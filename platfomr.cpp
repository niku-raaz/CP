#include<bits/stdc++.h>
using namespace std;

bool sbs(pair<int,int>&a, pair<int,int>&b){
            return a.second<b.second;
}
int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n=arr.size();
        
        int ans=0;
        
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
            vp[i]={arr[i],dep[i]};
        }
        sort(vp.begin(),vp.end(),sbs); // why not starttime? 
        // sorted by ent time
        
        //
        
        set<array<int,2>> s; // {endtime, platform}
        
        s.insert({vp[0].second,0}); 
        
        for(int i=1;i<n;i++){
            int start=vp[i].first;
            int end=vp[i].second;
            
            // find in set do we have some platform whose 
            // endtime is less than start
            
            auto it= s.lower_bound({start});
            
            if(it!=s.begin()){
                it--;
                // we can erase the it
                // and use that platform
                s.insert({end,(*it)[1]});
                
                s.erase(it);
            }else{
                // cant do anythiiing 
                // hav a new platform
                s.insert({end,(int)s.size()});
            }
            
        }
        
        
        return s.size();
     
}
   
   
int main(){

    
    
   
   
 return 0;
}
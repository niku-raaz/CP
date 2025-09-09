#include<bits/stdc++.h>
using namespace std;

#define int long long
   
int32_t main(){
    int tt;cin>>tt;

    while(tt--){
        int n;cin>>n;
        long long x,y;
        cin>>x>>y;
        
        long long sum=0;

        vector<int> a(n);
        
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }

        long long res=0;

        sort(a.begin(),a.end());

        for(int i=0;i<n;i++){

            int p=i;

            int tmp=sum-a[i];
        
            if(tmp>=x){
        
                int lo=i+1;
                int hi=n-1;
        
                int ans=-1;
        

        
                while(lo<=hi){
                    int mid=(lo+hi)/2;
        
                    if(tmp-a[mid]>=x){

                        ans=max(ans,mid);
                        lo=mid+1;
                    }else{
                        hi=mid-1;
                    }
                }
        
                lo=i+1;
                hi=n-1;
        
                int ans2=n+1;
        
        
                while(lo<=hi){
                    int mid=(lo+hi)/2;
        
        
                    if(tmp-a[mid]<=y){

                        ans2=min(ans2,mid);
                        hi=mid-1;
        
                    }else{ 
                        lo=mid+1;
                    }
                }
        
                if(ans2<=ans){
        
                    res+=(ans-ans2+1);
                    
                }
        
        
        
        
        
        
        
                
            }

            


        }

        cout<<res<<endl;





    }
    
   
   
 return 0;
}
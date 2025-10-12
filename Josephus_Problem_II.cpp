#include<bits/stdc++.h>
using namespace std;
#define int long long

class BIT{
    vector<int> p;
    public:
    BIT(int n){
        p.resize(n+1,0);
    }

    void update(int ind,int val){
        for(ind;ind<p.size();ind+=(ind& (-ind))){
            p[ind]+=val;
        }
    }

    int sum(int ind){
        int ans=0;
        for(ind;ind>0 ;ind-=(ind&(-ind))){
            ans+=p[ind];
        }
        return ans;
    }

    int findKth(int k){
        int lo=1;
        int hi=p.size()-1;
        int ans=hi+1;

        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(sum(mid)>=k){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};
   
   
int32_t main(){
    int n,k;
    cin>>n>>k;

    BIT b(n);
    for(int i=1;i<=n;i++){
        b.update(i,1);
    }

    int alive=n;

    int curr=0;

    for(int i=0;i<n;i++){
        curr+=k;
        curr%=alive;

        int ans=b.findKth(curr+1);

        cout<<ans<<" ";

        b.update(ans,-1);

        alive--;

    }

    
   
   
 return 0;
}
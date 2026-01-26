#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod=1e9+7;
class BIT{
    vector<int> p;
    public:
    BIT(int n){
        p.resize(n+1,0);
    }

    void update(int ind,int val){
         for(ind;ind<p.size();ind+=(ind&(-ind))){
            p[ind]+=val;
            p[ind]%=mod;
         }
    }

    int query(int ind){
        int sum=0LL;
        for(ind;ind>0;ind-=(ind&(-ind))){
            sum+=p[ind];
            sum%=mod;
        }
        return sum;
    }

    int query(int l,int r){
        int ans=query(r)-query(l-1);
        ans+=mod;
        ans%=mod;
        return ans;
    }

};
   
   
int32_t main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> dp(n,1);
    BIT F(n);

    // dp[i] -> number of  Incresing subsequnces ending with i

    vector<int> sub;

    dp[0]=1;
    sub.push_back(a[0]);
    F.update(1,1);

    for(int i=1;i<n;i++){
        if(a[i]>sub.back()){
            // we can extend it from whole sub
            //  dp[i]=sum(dp[i-1]+.....+dp[0])
            
            int res=F.query(1,i);
            dp[i]=res;
            F.update(i+1,dp[i]);
            sub.push_back(a[i]);
        }else{

            // there exist som index which is >a[i]
            int lo=lower_bound(sub.begin(),sub.end(),a[i])-sub.begin();

            a[lo]=a[i];

            //dp[i]= sum(dp[0]+dp[1]+.......+dp[lo-1])
            int res=F.query(1,lo);
            dp[i]=res;
            F.update(i+1,dp[i]);


        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans+=dp[i];
        ans%=mod;
        cout<<dp[i]<<" ";
    }

    cout<<ans;

    
    
   
   
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long

int rec(int ind,int sum){
    // can i make sum using 
    // the first 0 ....ind elemts ??
    if(ind==0){

        //
        // 
    }
}
   
   
int32_t main(){
    int tt;cin>>tt;

    while(tt--){
        int n;cin>>n;
        int x,y;
        cin>>x>>y;
        vector<int> a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        /// input done

        int dp[n+1][50005];

        // base case 0;

        memset(dp,0,sizeof(dp));

        dp[0][(x%a[0])]=1;

        for(int i=1;i<n;i++){

            // agar main cuurent element ko use kru 
            // to kya kya bana skta hu
            
        }



        
    }
    
   
   
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int N=1000005;
    
    vector<int> dp(N+1,1);

    for(int i=2;i<=N;i++){

        for(int j=1;j*i<=N;j++){
            dp[j*i]++;

        }

    }

    int n;
    cin>>n;

    while(n--){
        int x; cin>>x;
        cout<<dp[x]<<endl;


    }



    
   
   
 return 0;
}
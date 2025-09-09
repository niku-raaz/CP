#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;
int dp[N + 1]; 
   
int main(){
    int n;
    cin>>n;

    dp[0]=0;
    for(int i=1;i<=9;i++){
        dp[i]=1;
    }

    for(int i=10;i<=N;i++){
        dp[i]=1e9;
        int num=i;
        while(num>0){
            int d=num%10; 
            if(d>0 && i-d>=0)dp[i]=min(dp[i],1+dp[i-d]);
            num/=10;
        }
    }
    cout<<dp[n];
   
   
 return 0;
}
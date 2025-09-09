#include<bits/stdc++.h>
using namespace std;


int n;

char g[1002][1002];


bool issafe(int i, int j){

     if(i>=0 && j>=0 && i<n && j<n && g[i][j]=='.'){
        return 1;
     }

     return 0;

}
   
   
int main(){
    
    cin>>n;

    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }

    int mod=1e9+7;


    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(g[i][j]=='*'){
                dp[i][j]=0;
            }else{

                // up

                int x=i-1;
                int y=j;

                if(issafe(x,y)){

                    dp[i][j]+=dp[x][y];
                    dp[i][j]%=mod;
                }


                // left

                int a=i;
                int b=j-1;

                if(issafe(a,b)){

                    dp[i][j]+=dp[a][b];
                    dp[i][j]%=mod;
                }





            }

        }
    }

    cout<<dp[n-1][n-1];



    
   
   
 return 0;
}
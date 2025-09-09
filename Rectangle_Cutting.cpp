#include<bits/stdc++.h>
using namespace std;

int a,b;

int dp[502][502];



   
   
int main(){

    cin>>a>>b;

    if(a>b){
        swap(a,b);
    }


    for(int i=1;i<=500;i++){
        dp[1][i]=i-1;
        dp[i][1]=i-1;
    }

    for(int i=2;i<=500;i++){

        for(int j=2;j<=500;j++){


            if(i==j){

                dp[i][j]=0;



            }
            else{

                int mn=1e9;

                // cut on i;


                for(int mid=1;mid<i;mid++){

                    mn=min(mn,(dp[mid][j]+dp[i-mid][j]));
                }

                // cut on j

                for(int mid=1;mid<j;mid++){

                    mn=min(mn,(dp[i][mid]+dp[i][j-mid]));



                }

                dp[i][j]=mn+1;





            }





        }


    }

    // for(int i=1;i<10;i++){
    //     for(int j=1;j<10;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<dp[a][b];





    


    
   
   
 return 0;
}
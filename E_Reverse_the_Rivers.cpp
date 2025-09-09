
   
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
   
#define int long long 

#define nl cout<<endl; 

#define take(n) int n; cin>>n;

#define pl cout<<endl;

   
   
void solve(){
    take(n);
    take(k); take(q);


    int mat[n+1][k+1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin>>mat[i][j];
        }
    }


    for(int reg=1;reg<=k;reg++){
       // int curr=mat[1][reg];
        for(int c=2;c<=n;c++){
          //  curr=curr^mat[c][reg];
            mat[c][reg]|=mat[c-1][reg];
        }
    }

    while(q--){
        
        take(m);

        int mn=1;
        int mx=n;

        while(m--){
            take(reg);
            char ch; cin>>ch;

            take(bord);

            if(ch=='<'){

                int lo=1;
                int hi=n;

                int ans=lo;

                while(lo<=hi){
                    int mid=(lo+hi)/2;

                    if(mat[mid][reg]<bord){
                        ans=max(ans,mid);
                        lo=mid+1;

                    }else{
                        hi=mid-1;
                    }
                }

                if(mat[ans][reg]>=bord){
                    ans=0;
                }

                mx=min(mx,ans);



            }else{

                int lo=1;
                int hi=n;

                int ans=hi;

                while(lo<=hi){
                    int mid=(lo+hi)/2;

                    if(mat[mid][reg]>bord){
                        ans=min(ans,mid);
                        hi=mid-1;
                    }else{
                        lo=mid+1;
                    }


                }

                if(mat[ans][reg]<=bord){
                    ans=n+1;
                }

                mn=max(mn,ans);





            }








        }

        if(mn<=mx){
            cout<<mn;pl;
        }else{
            cout<<-1;pl;
        }








    }

   

    



        
}
   
   
   
int32_t main(){

    
        int test_case=1; 

        for(int xyz=1;xyz<=test_case;xyz++){
 
             solve(); };        
   return 0;
   }
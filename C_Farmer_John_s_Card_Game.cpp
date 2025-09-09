#include <bits/stdc++.h>
using namespace std;
   
#define int long long 
  
   
void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> g(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }

    for(int i=0;i<n;i++){
        sort(g[i].begin(),g[i].end());
    }
 

    

    int diff=n;

    for(int i=0;i<n;i++){

        for(int j=1;j<m;j++){
            if((g[i][j]-g[i][j-1])!=diff){
                cout<<-1;
                cout<<endl;
                 return;
            }

        }

    }

    vector<int> p(n);

    for(int num=0;num<n;num++){

        for(int i=0;i<n;i++){
            if(g[i][0]==num){
                p[num]=i+1;
                break;
            }
        }


    }

    for(int i=0;i<p.size();i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    
        
}
   
   
   
int32_t main(){

    
        int test_case=1; 
        cin>>test_case; 
        for(int xyz=1;xyz<=test_case;xyz++){
           
             solve();
            
            };        

            
   return 0;
   }
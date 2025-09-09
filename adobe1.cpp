#include<bits/stdc++.h>
using namespace std;
   
bool comp(vector<int>& x, vector<int>& y){
    return x[3]>=y[3];
}


int main(){
    int tt;
    cin>>tt;

    while(tt--){
        int x,y;
        cin>>x>>y;
        int n=x+y+1;

        vector<int> a(n),b(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

         for(int i=0;i<n;i++){
            cin>>b[i];
        }

        // 

        vector<vector<int>> v(n,vector<int>(4));

        for(int i=0;i<n;i++){
            v[i][0]=a[0];
            v[i][1]=b[0];
            v[i][2]=i;
            v[i][3]=max(a[i],b[i]);
        }


        sort(v.begin(),v.end(),comp);

        // Adobe 

        int up=0;
        int down=0;

        int i=0;


        int ans1=0;
        int ans2=0;

        while(up<x && down<y){
            if(v[i][0]>v[i][1] && up<x){
                ans1+=v[i][0];
                up++;
                i++;
            }else if(down<y){
                ans2+=v[i][1];
                down++;
                i++;
            }

        }



    }
    
   
   
 return 0;
}
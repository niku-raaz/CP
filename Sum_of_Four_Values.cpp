#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n,tar;
    cin>>n>>tar;
    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i;
    }

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x=tar-v[i].first-v[j].first;

            int lo=0;
            int hi=n-1;

            while(lo<hi){
                if(lo==i){
                    lo++;
                }else if(lo==j){
                    lo++;
                }else if(hi==i){
                    hi--;
                }else if(hi==j){
                    hi--;
                }else{
                    int sum=v[lo].first+v[hi].first;

                    if(sum<x){
                        lo++;
                    }else if(sum>x){
                        hi--;
                    }else{
                        cout<<v[i].second+1<<" "<<v[j].second+1<<" "<<v[lo].second+1<<" "<<v[hi].second+1;
                        return 0;
                    }
                }

            }


        }
    }

    cout<<"IMPOSSIBLE";

    
   
   
 return 0;
}
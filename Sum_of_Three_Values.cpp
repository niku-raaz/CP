#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;cin>>n;
    int tar;cin>>tar;

    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }

    sort(a.begin(),a.end());

    // Can do N*N solution

    for(int i=0;i<n;i++){

        // My first nummber is a[i].first

        int x=tar-a[i].first;

        int lo=0;
        int hi=n-1;

        while(lo<hi){
            if(lo==i){
                lo++;
            }else if(hi==i){
                hi--;
            }else{
                // This is just two sum
                int sum=a[lo].first+a[hi].first;

                if(sum<x){
                    lo++;

                }else if(sum>x){
                    hi--;
                }else{
                    // mil gya
                    cout<<a[i].second+1<<" "<<a[lo].second+1<<" "<<a[hi].second+1;
                    return 0;
                }



            }

        }





    }

    cout<<"IMPOSSIBLE";
    
   
   
 return 0;
}
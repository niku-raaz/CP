#include<bits/stdc++.h>
using namespace std;
   
   
int main(){
    int n;cin>>n;
    string s;cin>>s;

    if(n==1){
        cout<<"Yes"<<endl;
        return 0;
    }

    vector<int> mp(26,0);

    for(auto x: s){
        mp[(x-'a')]+=1;
    }

    for(int i=0;i<26;i++){
        if(mp[i]>=2){
            cout<<"Yes"<<endl; return 0;
        }
    }


    cout<<"No"<<endl;



    
   
   
 return 0;
}